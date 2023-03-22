#include "Motor.h"
#include "Display.h"
#include "Buzzer.h"
#include "definitions.h"
#include "page.h"

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebSrv.h>

const char *ssid = "CAR1";
const char *password = "CAR1PASSWORD";
AsyncWebServer server(80);

const char *PARAM_ACTION = "do";

Motor left(MOT_A1, MOT_A2, DEFAULT_SPEED);
Motor right(MOT_B1, MOT_B2, DEFAULT_SPEED);

Buzzer buzzer(BUZZER_PIN, DEFAULT_FREQ, 500);

Display display;

void doAction(char action) {
  switch (action) {
    case 'f':
      left.RunMotor(MOT_FWD);
      right.RunMotor(MOT_FWD);
      break;
    case 'l':
      left.RunMotor(MOT_FWD, .75);
      right.RunMotor(MOT_BKW, .75);
      break;
    case 'r':
      left.RunMotor(MOT_BKW, .75f);
      right.RunMotor(MOT_FWD, .75f);
      break;
    case 'b':
      left.RunMotor(MOT_BKW);
      right.RunMotor(MOT_BKW);
      break;
    case 'h':
      buzzer.Run();
      break;
    case 's':
      buzzer.Stop();
      left.Stop();
      right.Stop();
    default:
      break;
  }
}

void doDisplay(char image) {
  switch (image) {
    case 's':
      display.Show(Images::smile);
      break;
    case 'f':
      display.Show(Images::frown);
      break;
    case 'c':
      display.Show(Images::curios);
      break;
    case 'S':
      display.Show(Images::solidus);
      break;
    default:
      break;
  }
}

void setup() {

  pinMode(MOT_A1, OUTPUT);
  pinMode(MOT_A2, OUTPUT);
  pinMode(MOT_B1, OUTPUT);
  pinMode(MOT_B2, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);


  Serial.begin(9600);
  
  Serial.println("\n[*] Creating AP");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);
  Serial.print("[+] AP Created with IP Gateway ");
  Serial.println(WiFi.softAPIP());

  display = Display();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", INDEX_HTML);
  });

  server.on("/action", HTTP_GET,
            [](AsyncWebServerRequest *request) {
              String message;
              message = request->getParam(PARAM_ACTION)->value();
              doAction(message[0]);
              request->send(200, "OK");
            });

  server.on("/image", HTTP_GET,
            [](AsyncWebServerRequest *request) {
              String message;
              message = request->getParam(PARAM_ACTION)->value();
              doDisplay(message[0]);
              request->send(200, "OK");
            });

  server.onNotFound([](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", INDEX_HTML);
  });

  server.begin();
}

void loop() {
}
