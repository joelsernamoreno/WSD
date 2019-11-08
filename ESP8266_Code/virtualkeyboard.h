const char VirtualKeyboard[] PROGMEM = R"=====(
<!DOCTYPE HTML>
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

        input{
            background: linear-gradient(#777777, #444444);
            color: white;
            padding: 4px;
            min-width: 40px;
            border-radius: 2.5px;
            border: 2px solid white;
            text-align: center;
            text-decoration: none;
            transition: 0.1s
        }

        input:hover, input:active{
            background: linear-gradient(#888888, #555555);
            border: 2px solid deepskyblue;

        }

        .console{
            width: 99%;
            background-color: black;
            color: white;
            font-family: monospace;
            padding: 5px;
            border: 0px;
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


<div id="control">
          <div id="Teclado">
            <table style="text-align: center; display: inline-block;">
              <tr>
                <td>
<FORM action="/runlivepayload" method="post" id="esc" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="esc" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_ESC</textarea>
<INPUT type="submit" form="esc" value="ESC"></form>
          </td>
      <td>
<FORM action="/runlivepayload" method="post" id="f1" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f1" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F1</textarea>
<INPUT type="submit" form="f1" value="F1"></form>
      </td>
      <td>
<FORM action="/runlivepayload" method="post" id="f2" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f2" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F2</textarea>
<INPUT type="submit" form="f2" value="F2"></form>
      </td>
      <td>
<FORM action="/runlivepayload" method="post" id="f3" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f3" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F3</textarea>
<INPUT type="submit" form="f3" value="F3"></form>
      </td>
      <td>
<FORM action="/runlivepayload" method="post" id="f4" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f4" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F4</textarea>
<INPUT type="submit" form="f4" value="F4"></form>
      </td>
<td>
<FORM action="/runlivepayload" method="post" id="f5" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f5" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F5</textarea>
<INPUT type="submit" form="f5" value="F5"></form>
      </td>
      <td>
<FORM action="/runlivepayload" method="post" id="f6" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f6" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F6</textarea>
<INPUT type="submit" form="f6" value="F6"></form>
      </td>
<td>
<FORM action="/runlivepayload" method="post" id="f7" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f7" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F7</textarea>
<INPUT type="submit" form="f7" value="F7"></form>
      </td>
      <td>
<FORM action="/runlivepayload" method="post" id="f8" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f8" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F8</textarea>
<INPUT type="submit" form="f8" value="F8"></form>
      </td>
<td>
<FORM action="/runlivepayload" method="post" id="f9" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f9" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F9</textarea>
<INPUT type="submit" form="f9" value="F9"></form>
      </td>
      <td>
<FORM action="/runlivepayload" method="post" id="f10" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f10" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F10</textarea>
<INPUT type="submit" form="f10" value="F10"></form>
      </td>
<td>
<FORM action="/runlivepayload" method="post" id="f11" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f11" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F11</textarea>
<INPUT type="submit" form="f11" value="F11"></form>
      </td>
      <td>
<FORM action="/runlivepayload" method="post" id="f12" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f12" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_F12</textarea>
<INPUT type="submit" form="f12" value="F12"></form>
      </td>
      <td>

<FORM action="/runlivepayload" method="post" id="insert" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="insert" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_INSERT</textarea>
<INPUT type="submit" form="insert" value="INS"></form>
      </td>
      <td>
<FORM action="/runlivepayload" method="post" id="delete" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="delete" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_DELETE</textarea>
<INPUT type="submit" form="delete" value="DEL"></form>
      </td>
              </tr>
              <tr>
 <tr>
  <td>
<FORM action="/runlivepayload" method="post" id="tab" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="tab" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_TAB</textarea>
<INPUT type="submit" form="tab" value="TAB"></form>
  </td>
  <td>
<FORM action="/runlivepayload" method="post" id="q" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="q" rows="1" cols="100" name="livepayload" hidden="1">print q</textarea>
<INPUT type="submit" form="q" value="q"></form>
  </td>
 <td>
<FORM action="/runlivepayload" method="post" id="w" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="w" rows="1" cols="100" name="livepayload" hidden="1">print w</textarea>
<INPUT type="submit" form="w" value="w"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="e" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="e" rows="1" cols="100" name="livepayload" hidden="1">print e</textarea>
<INPUT type="submit" form="e" value="e"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="r" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="r" rows="1" cols="100" name="livepayload" hidden="1">print r</textarea>
<INPUT type="submit" form="r" value="r"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="t" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="t" rows="1" cols="100" name="livepayload" hidden="1">print t</textarea>
<INPUT type="submit" form="t" value="t"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="y" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="y" rows="1" cols="100" name="livepayload" hidden="1">print y</textarea>
<INPUT type="submit" form="y" value="y"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="u" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="u" rows="1" cols="100" name="livepayload" hidden="1">print u</textarea>
<INPUT type="submit" form="u" value="u"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="i" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="i" rows="1" cols="100" name="livepayload" hidden="1">print i</textarea>
<INPUT type="submit" form="i" value="i"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="o" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="o" rows="1" cols="100" name="livepayload" hidden="1">print o</textarea>
<INPUT type="submit" form="o" value="o"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="p" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="p" rows="1" cols="100" name="livepayload" hidden="1">print p</textarea>
<INPUT type="submit" form="p" value="p"></form>
  </td>
<td rowspan="2">
<FORM action="/runlivepayload" method="post" id="enter" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="enter" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_RETURN</textarea>
<INPUT style="padding-bottom:20px;padding-top:20px;padding-left: 0px;padding-right:0px" type="submit" form="enter" value="ENTER"></form>
</td>
<td>
</td>
  </td><td></td>
<td>
<FORM action="/runlivepayload" method="post" id="arrowup" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="arrowup" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_UP_ARROW</textarea>
<INPUT  type="submit" form="arrowup" value="UP"></form>
</td>
 </tr>
<tr>
  <td>
<FORM action="/runlivepayload" method="post" id="capslock" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="capslock" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_CAPS_LOCK</textarea>
<INPUT type="submit" form="capslock" value="CAPSLOCK"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="a" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="a" rows="1" cols="100" name="livepayload" hidden="1">print a</textarea>
<INPUT type="submit" form="a" value="a"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="s" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="s" rows="1" cols="100" name="livepayload" hidden="1">print s</textarea>
<INPUT type="submit" form="s" value="s"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="d" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="d" rows="1" cols="100" name="livepayload" hidden="1">print d</textarea>
<INPUT type="submit" form="d" value="d"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="f" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="f" rows="1" cols="100" name="livepayload" hidden="1">print f</textarea>
<INPUT type="submit" form="f" value="f"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="g" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="g" rows="1" cols="100" name="livepayload" hidden="1">print g</textarea>
<INPUT type="submit" form="g" value="g"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="h" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="h" rows="1" cols="100" name="livepayload" hidden="1">print h</textarea>
<INPUT type="submit" form="h" value="h"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="j" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="j" rows="1" cols="100" name="livepayload" hidden="1">print j</textarea>
<INPUT type="submit" form="j" value="j"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="k" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="k" rows="1" cols="100" name="livepayload" hidden="1">print k</textarea>
<INPUT type="submit" form="k" value="k"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="l" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="l" rows="1" cols="100" name="livepayload" hidden="1">print l</textarea>
<INPUT type="submit" form="l" value="l"></form>
  </td>
<td>
  </td>
<td></td>
<td>
<FORM action="/runlivepayload" method="post" id="arrowLeft" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="arrowLeft" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_LEFT_ARROW</textarea>
<INPUT type="submit" form="arrowLeft" value="Left"></form>
  </td>
<td> </td>
<td>
<FORM action="/runlivepayload" method="post" id="arrowRight" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="arrowRight" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_RIGHT_ARROW</textarea>
<INPUT type="submit" form="arrowRight" value="Right"></form>
  </td>
<td>
 </tr>
<tr>
  <td>
<FORM action="/runlivepayload" method="post" id="shift" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="shift" rows="1" cols="100" name="livepayload" hidden="1">press KEY_LEFT_SHIFT</textarea>
<INPUT style="width:100%;"type="submit" form="shift" value="SHIFT"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="z" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="z" rows="1" cols="100" name="livepayload" hidden="1">print z</textarea>
<INPUT type="submit" form="z" value="z"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="x" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="x" rows="1" cols="100" name="livepayload" hidden="1">print x</textarea>
<INPUT type="submit" form="x" value="x"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="c" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="c" rows="1" cols="100" name="livepayload" hidden="1">print c</textarea>
<INPUT type="submit" form="c" value="c"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="v" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="v" rows="1" cols="100" name="livepayload" hidden="1">print v</textarea>
<INPUT type="submit" form="v" value="v"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="b" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="b" rows="1" cols="100" name="livepayload" hidden="1">print b</textarea>
<INPUT type="submit" form="b" value="b"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="n" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="n" rows="1" cols="100" name="livepayload" hidden="1">print n</textarea>
<INPUT type="submit" form="n" value="n"></form>
  </td>
<td>
<FORM action="/runlivepayload" method="post" id="m" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="m" rows="1" cols="100" name="livepayload" hidden="1">print m</textarea>
<INPUT type="submit" form="m" value="m"></form>
  </td>
  <td></td><td></td><td></td>
  <td>
<FORM action="/runlivepayload" method="post" id="backspace" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="backspace" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_BACKSPACE</textarea>
<INPUT type="submit" form="backspace" value="Backspace"></form>
  </td><td></td><td></td>
  <td>
<FORM action="/runlivepayload" method="post" id="arrowDown" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="arrowDown" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_DOWN_ARROW</textarea>
<INPUT type="submit" form="arrowDown" value="Down"></form>
  </td>
 </tr>
</tr>
            </table>
       <table>
 <tr>
  <td>
<FORM action="/runlivepayload" method="post" id="ctrl" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="ctrl" rows="1" cols="100" name="livepayload" hidden="1">press KEY_LEFT_CTRL</textarea>
<INPUT style="padding-left:25px;padding-right:25px;"type="submit" form="ctrl" value="CTRL"></form>
  </td>
  <td>
<FORM action="/runlivepayload" method="post" id="mod" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="mod" rows="1" cols="100" name="livepayload" hidden="1">rawpress KEY_LEFT_GUI</textarea>
<INPUT type="submit" form="mod" value="GUI"></form>
  </td>
  <td>
<FORM action="/runlivepayload" method="post" id="alt" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="alt" rows="1" cols="100" name="livepayload" hidden="1">press KEY_LEFT_ALT</textarea>
<INPUT type="submit" form="alt" value="ALT"></form>
  </td>
  <td colspan="4">
<FORM action="/runlivepayload" method="post" id="space" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="space" rows="1" cols="100" name="livepayload" hidden="1">print  </textarea>
<INPUT style="padding-left:70px;padding-right:70px;width:100%"type="submit" form="space" value="SPACE"></form>
  </td>
  <td>
<FORM action="/runlivepayload" method="post" id="ctrl" target="iframe">
<INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
<textarea style ="width: 100%;" form="ctrl" rows="1" cols="100" name="livepayload" hidden="1">press KEY_RIGH_CTRL</textarea>
<INPUT type="submit" form="ctrl" value="CTRL"></form>
  </td>
  <td style="padding-right: 40px;">
  </td>
  <td>
    <FORM action="/runlivepayload" method="post" id="guiR" target="iframe">
    <INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
    <textarea style ="width: 100%;" form="guiR" rows="1" cols="100" name="livepayload" hidden="1">runwin</textarea>
    <INPUT type="submit" form="guiR" value="Runwin"></form>
  </td>
  <td>
    <FORM action="/runlivepayload" method="post" id="altF2" target="iframe">
    <INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
    <textarea style ="width: 100%;" form="altF2" rows="1" cols="100" name="livepayload" hidden="1">rungnome</textarea>
    <INPUT type="submit" form="altF2" value="Rungnome"></form>
  </td>
  <td>
    <FORM action="/runlivepayload" method="post" id="guiSPA" target="iframe">
    <INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
    <textarea style ="width: 100%;" form="guiSPA" rows="1" cols="100" name="livepayload" hidden="1">runmac</textarea>
    <INPUT type="submit" form="guiSPA" value="Runmac"></form>
  </td>
  <td>
    <FORM action="/runlivepayload" method="post" id="release" target="iframe">
    <INPUT type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
    <textarea style ="width: 100%;" form="release" rows="1" cols="100" name="livepayload" hidden="1">release</textarea>
    <INPUT type="submit" form="release" value="release"></form>
  </td>
 </tr>
 </tr>

            </table>
          </div>
        </div>

  <div id="sendText">

<table>
<tr>
<td>
<form action="/runlivepayload" method="post" id="print" target="iframe">
<input name="livepayloadpresent" value="1" checked="checked" hidden="1" type="radio">
<textarea class="console" form="print" rows="1" cols="100" name="livepayload">print </textarea>
</form></td>
</tr><tr>
<td>
<input form="print" value="Send Text" type="submit">
</td>
</tr>
</table>
    </center>
</div>
          <hr>

        </div>
    <iframe style="visibility:hidden;"src="/runlivepayload" name="iframe"></iframe>
  </body>
</html>
)=====";
