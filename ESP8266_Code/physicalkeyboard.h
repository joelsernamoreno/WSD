const char PhysicalKeyboard[] PROGMEM = R"=====(
<html>
  <head>
    <meta charset="UTF-8">
        <title>BadUsb_PControl</title>
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

          .enlaceboton{
            background: linear-gradient(#777777, #444444);
            color: white;
            padding: 2px;
            border-radius: 2.5px;
            border: 2px solid white;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            transition: 0.2s;
          }

          .enlaceboton:hover, .enlaceboton:active{
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
    <br>
        </style>
        <script>
        function mobileCheck() { 
            var mainId = document.getElementById("main");
                if( navigator.userAgent.match(/Android/i)
                || navigator.userAgent.match(/webOS/i)
                || navigator.userAgent.match(/iPhone/i)
                || navigator.userAgent.match(/iPad/i)
                || navigator.userAgent.match(/iPod/i)
                || navigator.userAgent.match(/BlackBerry/i)
                || navigator.userAgent.match(/Windows Phone/i)
                ){
                    mainId.innerHTML = '<textarea id="output" col="100" row="30" ></textarea>';
                    }
                    else {
          mainId.innerHTML = '<div id="output"></textarea></div>';
                    }
                    }
        </script>
  </head>
<body onload="mobileCheck()">
    <a class="enlaceboton" name="F1" alt="F1" href="#" onclick='input_form("rawpress ","194")'>F1</a>
    <a Class="enlaceboton" name="F2" alt="F2" href="#" onclick='input_form("rawpress ","195")'>F2</a>
    <a Class="enlaceboton" name="F3" alt="F3" href="#" onclick='input_form("rawpress ","196")'>F3</a>
    <a Class="enlaceboton" name="F4" alt="F4" href="#" onclick='input_form("rawpress ","197")'>F4</a>
    <a Class="enlaceboton" name="F5" alt="F5" href="#" onclick='input_form("rawpress ","198")'>F5</a>
    <a Class="enlaceboton" name="F6" alt="F6" href="#" onclick='input_form("rawpress ","199")'>F6</a>
    <a Class="enlaceboton" name="F7" alt="F7" href="#" onclick='input_form("rawpress ","200")'>F7</a>
    <a Class="enlaceboton" name="F8" alt="F8" href="#" onclick='input_form("rawpress ","201")'>F8</a>
    <a Class="enlaceboton" name="F9" alt="F9" href="#" onclick='input_form("rawpress ","202")'>F9</a>
    <a Class="enlaceboton" name="F10" alt="F10" href="#" onclick='input_form("rawpress ","203")'>F10</a>
    <a Class="enlaceboton" name="F11" alt="F11" href="#" onclick='input_form("rawpress ","204")'>F11</a>
    <a Class="enlaceboton" name="F12" alt="F12" href="#" onclick='input_form("rawpress ","205")'>F12</a>
    <a Class="enlaceboton" name="runwin" alt="runwin" href="#" onclick='input_form("rawpress","131")'>Runwin</a>

    <p>Type to see the result</p>
  <!--<textarea id="output1" col="100" row="30" ></textarea> -->
  <div id="main"></div>
<script>
    window.addEventListener("keydown",function(event){
 
if( navigator.userAgent.match(/Android/i)
                || navigator.userAgent.match(/webOS/i)
                || navigator.userAgent.match(/iPhone/i)
                || navigator.userAgent.match(/iPad/i)
                || navigator.userAgent.match(/iPod/i)
                || navigator.userAgent.match(/BlackBerry/i)
                || navigator.userAgent.match(/Windows Phone/i)
                ){
  var PelementLegth = document.getElementById("output").value.length;
    
  setTimeout(function(){    
  var element = document.getElementById("output");
  var elementLegth = element.value.length; 
  let str2 = event.key;
  var InitElement = elementLegth + (PelementLegth - elementLegth); 
  if (parseInt(InitElement,10) > parseInt(elementLegth,10)){input_form("rawpress ","178");}
  else if (str2 == "Enter"){input_form("rawpress ","176");}
  else {
   var str = element.value.substring(InitElement,elementLegth);
   input_form("print ",str);
   }
    
  },50);
      }else{
            var NspecialKey = true; 
            let str = event.key;
      if (str == "Backspace"){
        var removeCharacter = document.getElementById("output");
        removeCharacter.removeChild(removeCharacter.lastChild);
        input_form("rawpress ","178");
      }else{
      let el = document.createElement ("span");
      if (str == "CapsLock"){
                input_form("rawpress ","193");
                NspecialKey= false;}
      var SpecialCharacter = ["Meta","Control","AltGraph","ContextMenu","Shift","End","Tab",
                                    "Escape","Alt","Home","PageDown","PageUp","Delete","Insert","ArrowRight","ArrowLeft","ArrowUp","ArrowDown"];
      let SpecialCharacter_Value ={
                Meta:"210",Control:"132",Shift:"133",
                End:"213",Tab:"179",Escape:"177",Alt:"130",
                Home:"210",PageDown:"214",PageUP:"211",Delete:"212",
                Insert:"209",ArrowLeft:"216",ArrowRight:"215",ArrowUp:"218",ArrowDown:"217"}
           
      if (SpecialCharacter.indexOf(str) >=  0){
        input_form("press ",SpecialCharacter_Value[str]);
        NspecialKey= false;}
      if (str == "Enter"){ str = "<br/>";input_form("rawpress ","176");}
                        
      el.innerHTML = str;
      
      if (NspecialKey){
                document.getElementById("output").appendChild(el);
          input_form("print ",str);
      } 
      } 
      }  
        },true);

function input_form(action,value){
 document.getElementById("Sinput").setAttribute("value",value);
 var textarea;
 textarea = document.getElementById("tecla");
 textarea.innerHTML = action + value;
 document.forms["myForm"].submit();
}
        </script>
<form hidden="1" name="myForm" action="/runlivepayload" method="post" id="sendForm" target="iframe">
    <input type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
    <textarea id="tecla" style ="width: 100%;" form="sendForm" rows="1" cols="100" name="livepayload" hidden="1">Press:200</textarea>
    <input id="Sinput" type="submit" form="sendForm" value="">
</form>
<iframe style="visibility:hidden;"src="/runlivepayload" name="iframe"></iframe>
<hr>
</body>
</html>
)=====";
