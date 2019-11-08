const char UploadPayload[] PROGMEM = R"=====(
<html>
  <head>
    <title>BadUsb_PControl</title>
    <meta charset="utf-8">
    <style>
      body {
        background-color: #333333;
        font-family: "Century Gothic", Arial;
        color: white;
        margin: 20px;

      }

      .myButton:link, .myButton:visited {
        background: linear-gradient(#777777, #444444);
        color: white;
        padding: 4px;
        min-width: 100px;
        border-radius: 5px;
        border: 2px solid white;
        text-align: center;
        margin-right: 20px;
        text-decoration: none;
        display: inline-block;
        transition: 0.25s;
      }

      .myButton:hover, .myButton:active {
        background: linear-gradient(#888888, #555555);
        border: 2px solid deepskyblue;
        border-radius: 10px;
        transform:scale(1.15);

      }

      .defBtn{
        background: linear-gradient(#777777, #444444);
        color: white;
        padding: 4px;
        border-radius: 2.5px;
        border: 2px solid white;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        transition: 0.2s

      }

      .defBtn:hover, .defBtn:active{
        background: linear-gradient(#888888, #555555);
        border: 2px solid deepskyblue;
      }
    </style>
  </head>
  <body>
  <center>
    <div id="header">
      <div id="menu">
        <ul>
          <a class="myButton" href="/">Virtual Keyboard</a>
          <a class="myButton" href="/physicalkeyboard">Physical Keyboard</a>
          <a class="myButton" href="/livepayload">Live Payload</a>
          <a class="myButton" href="/uploadpayload">Upload Payload</a>
          <a class="myButton" href="/listpayloads">Choose Payload</a>
          <a class="myButton" href="/exfil">Exfiltration</a>
      </div>
    </div>
    <hr>

<b>
</b>
<br>
<form method='POST' action='/upload' enctype='multipart/form-data'><input class="defBtn" type='file' name='upload'><br><br><input class="defBtn" type='submit' value='Upload'>
</form> 
</body>
</html>
)=====";
