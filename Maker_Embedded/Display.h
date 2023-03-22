#ifndef DISPLAY_h
#define DISPLAY_h

#include "definitions.h"
#include "images.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


enum Images {
  smile,
  frown,
  curios,
  solidus
};

class Display {

private:
  Adafruit_SSD1306 display;

public:

  Display() {
    Serial.println("initialize");
    this->display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
    Serial.println("initialized");
  }

  void Show(Images image) {
    Serial.println("hello");
    this->display.clearDisplay();

    Serial.println("hi");

    switch (image) {
      case Images::curios:
        this->display.drawBitmap((display.width() - SIGLA_WIDTH) / 2,
                                 (display.height() - SIGLA_HEIGHT) / 2,
                                 sigla_bmp, SIGLA_WIDTH, SIGLA_HEIGHT, 1);
        break;
      case Images::frown:
        break;
      case Images::smile:
        break;
      case Images::solidus:
      default:
        this->display.drawBitmap((display.width() - LOGO_WIDTH) / 2,
                                 (display.height() - LOGO_HEIGHT) / 2,
                                 logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
        break;
    }

    this->display.display();
  }
};
#endif
