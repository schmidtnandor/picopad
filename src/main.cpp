#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Keyboard.h>
Adafruit_ST7735 tft = Adafruit_ST7735(17, 16, 19, 18, 20);
GFXcanvas1 canvas = GFXcanvas1(160, 128);
int testSwitchPin = 21;
int testSwitchPin2 = 10;
bool isFilledRect = false;
bool isFilledRect2 = false;
void setup() {
  Serial.begin(115200);
  Keyboard.begin(KeyboardLayout_en_US);
  pinMode(testSwitchPin, INPUT_PULLUP);
  pinMode(testSwitchPin2, INPUT_PULLUP);
  tft.initR();
  tft.setRotation(1);
  tft.setCursor(0, 0);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  canvas.setRotation(1);
  canvas.setCursor(0, 0);
  canvas.fillRect(9, 9, 13, 14, 1);
  tft.drawRect(24, 8, 32, 32, 0xFFFF);

  tft.drawRect(64, 8, 32, 32, 0xFFFF);

  tft.drawRect(103, 8, 32, 32, 0xFFFF);

  tft.drawRect(24, 48, 32, 32, 0xFFFF);

  tft.drawRect(64, 48, 32, 32, 0xFFFF);

  tft.drawRect(103, 48, 32, 32, 0xFFFF);

  tft.drawRect(24, 87, 32, 32, 0xFFFF);

  tft.drawRect(64, 87, 32, 32, 0xFFFF);

  tft.drawRect(103, 87, 32, 32, 0xFFFF);
  ;
}

void loop() {

  if (digitalRead(testSwitchPin) == LOW) {
    if (!isFilledRect) {
      tft.fillRect(24, 8, 32, 32, 0xFFFF);
      isFilledRect = true;
    }

    Keyboard.press('A');
    tft.setCursor(0, 0);
    Serial.println("Switch pressed!");
    delay(50);
  } else {
    if (isFilledRect) {
      tft.fillRect(24, 8, 32, 32, 0x0000);
      tft.drawRect(24, 8, 32, 32, 0xFFFF);
    }

    isFilledRect = false;
    Keyboard.release('A');
    tft.setCursor(0, 0);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    Serial.println("Switch not pressed!");
    delay(50);
  }
  // ezzel még valami van + borzasztóan fog kinézni a kód xd
  if (digitalRead(testSwitchPin2) == LOW) {
    if (!isFilledRect2) {
      tft.fillRect(64, 8, 32, 32, 0xFFFF);
      isFilledRect2 = true;
    } else {
      if (isFilledRect2) {
        tft.fillRect(64, 8, 32, 32, 0x0000);
        tft.drawRect(64, 8, 32, 32, 0xFFFF);
      }

      isFilledRect2 = false;
      tft.setCursor(0, 0);
      tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
      Serial.println("Switch not pressed!");
      delay(50);
    }
  }
}