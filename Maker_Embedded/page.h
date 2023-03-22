#include <Arduino.h>

static const char PROGMEM INDEX_HTML[] = R"rawliteral(
<html>
  <head>
    <title>MAKER IN 4 PASI</title>
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <style>
      body {
        font-family: Arial;
        text-align: center;
        margin: 0 auto;
        padding-top: 30px
      }

      .items {
        width: 100%;
        height: 100%;
        display: flex;
        flex-direction: column;
        align-items: center;
        justify-content: center
      }

      table {
        margin-left: auto;
        margin-right: auto
      }

      td {
        padding: 8 px
      }

      .button {
        background-color: #2f4468;
        border: none;
        color: #fff;
        padding: 10px 20px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 18px;
        margin: 6px 3px;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: transparent
      }

      img {
        width: auto;
        max-width: 100%;
        height: auto
      }

      select {
        appearance: none;
        background: #2f4468;
        color: #fff;
        cursor: pointer;
        border-radius: 4px
      }
    </style>
  </head>
  <body>
    <div class="items">
      <h1>Maker in 4 Pasi</h1>
      <table>
        <tr>
          <td colspan="3" align="center">
            <select onchange="changeImage(this.value);">
              <option value="s">Smile</option>
              <option value="f">Frown</option>
              <option value="c">Curios</option>
              <option value="S">SOLIDUS</option>
            </select>
          </td>
        </tr>
        <tr>
          <td colspan="3" align="center">
            <button class="button" onpointerdown='toggleCheckbox("f")' onpointerup='toggleCheckbox("s")'>Forward</button>
          </td>
        </tr>
        <tr>
          <td align="center">
            <button class="button" onpointerdown='toggleCheckbox("l")' onpointerup='toggleCheckbox("s")'>Left</button>
          </td>
          <td align="center">
            <button class="button" onpointerdown='toggleCheckbox("h")' onpointerup='toggleCheckbox("s")'>HONK</button>
          </td>
          <td align="center">
            <button class="button" onpointerdown='toggleCheckbox("r")' onpointerup='toggleCheckbox("s")'>Right</button>
          </td>
        </tr>
        <tr>
          <td colspan="3" align="center">
            <button class="button" onpointerdown='toggleCheckbox("b")' onpointerup='toggleCheckbox("s")'>Backward</button>
          </td>
        </tr>
      </table>
    </div>
    <script>
      function toggleCheckbox(e) {
        var n = new XMLHttpRequest;
        n.open("GET", "/action?do=" + e, !0), n.send()
      }
      function changeImage(e) {
        var n = new XMLHttpRequest;
        n.open("GET", "/image?do=" + e, !0), n.send()
      }
    </script>
  </body>
</html>
)rawliteral";
