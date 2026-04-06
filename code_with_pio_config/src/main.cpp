#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Keyboard.h>
const int TFT_CS = 5;
const int TFT_DC = 6;
const int TFT_MOSI = 3;
const int TFT_SCLK = 2;
const int TFT_RST = 7;
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
const int TOP_LEFT_PIN = 9;
const int TOP_MIDDLE_PIN = 15;
const int TOP_RIGHT_PIN = 16;
const int MIDDLE_LEFT_PIN = 10;
const int MIDDLE_MIDDLE_PIN = 11;
const int MIDDLE_RIGHT_PIN = 21;
const int BOTTOM_LEFT_PIN = 12;
const int BOTTOM_MIDDLE_PIN = 19;
const int BOTTOM_RIGHT_PIN = 17;

int pins[9] = {TOP_LEFT_PIN, TOP_MIDDLE_PIN, TOP_RIGHT_PIN, MIDDLE_LEFT_PIN, MIDDLE_MIDDLE_PIN, MIDDLE_RIGHT_PIN, BOTTOM_LEFT_PIN, BOTTOM_MIDDLE_PIN, BOTTOM_RIGHT_PIN};
const int keyCount = sizeof(pins) / sizeof(pins[0]);
class Key {
public:
  int pin;
  bool isFilledRect;
};
Key keys[9];
void setup() {
  Serial.begin(115200);
  Keyboard.begin(KeyboardLayout_en_US);
  for (int pin : pins) {
    pinMode(pin, INPUT_PULLUP);
  }

  for (int i = 0; i < keyCount; i++) {
    keys[i].isFilledRect = false;
  }
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(3);
  tft.setCursor(0, 0);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  tft.drawRect(24, 8, 32, 32, 0xFFFF);
  tft.drawRect(64, 8, 32, 32, 0xFFFF);
  tft.drawRect(104, 8, 32, 32, 0xFFFF);
  tft.drawRect(24, 48, 32, 32, 0xFFFF);
  tft.drawRect(65, 48, 32, 32, 0xFFFF);
  tft.drawRect(104, 48, 32, 32, 0xFFFF);
  tft.drawRect(24, 88, 32, 32, 0xFFFF);
  tft.drawRect(64, 88, 32, 32, 0xFFFF);
  tft.drawRect(104, 88, 32, 32, 0xFFFF);
}
void loop() {
  Keyboard.releaseAll();
  delay(50);
  for (int pin : pins) {
    if (digitalRead(pin) == LOW) {
      switch (pin) {
      case TOP_LEFT_PIN:
        Keyboard.press('a');
        // if you want to use a modifier key or multiple of them, follow the example below
        // Keyboard.press(KEY_LEFT_CTRL);
        // Keyboard.press(KEY_LEFT_ALT);
        // Keyboard.press(KEY_DELETE);
        if (keys[0].isFilledRect == false) {
          tft.fillRect(24, 8, 32, 32, 0xFFFF);
          keys[0].isFilledRect = true;
        }
        break;
      case TOP_MIDDLE_PIN:
        Keyboard.press('b');
        if (keys[1].isFilledRect == false) {
          tft.fillRect(64, 8, 32, 32, 0xFFFF);
          keys[1].isFilledRect = true;
        }
        break;
      case TOP_RIGHT_PIN:
        Keyboard.press('c');
        if (keys[2].isFilledRect == false) {
          tft.fillRect(104, 8, 32, 32, 0xFFFF);
          keys[2].isFilledRect = true;
        }
        break;
      case MIDDLE_LEFT_PIN:
        Keyboard.press('d');
        if (keys[3].isFilledRect == false) {
          tft.fillRect(24, 48, 32, 32, 0xFFFF);

          keys[3].isFilledRect = true;
        }
        break;
      case MIDDLE_MIDDLE_PIN:
        Keyboard.press('e');
        if (keys[4].isFilledRect == false) {
          tft.fillRect(65, 48, 32, 32, 0xFFFF);
          keys[4].isFilledRect = true;
        }
        break;
      case MIDDLE_RIGHT_PIN:
        Keyboard.press('f');
        if (keys[5].isFilledRect == false) {
          tft.fillRect(104, 48, 32, 32, 0xFFFF);
          keys[5].isFilledRect = true;
        }
        break;
      case BOTTOM_LEFT_PIN:
        Keyboard.press('g');
        if (keys[6].isFilledRect == false) {
          tft.fillRect(24, 88, 32, 32, 0xFFFF);
          keys[6].isFilledRect = true;
        }
        break;
      case BOTTOM_MIDDLE_PIN:
        Keyboard.press('h');
        if (keys[7].isFilledRect == false) {
          tft.fillRect(64, 88, 32, 32, 0xFFFF);
          keys[7].isFilledRect = true;
        }
        break;
      case BOTTOM_RIGHT_PIN:
        Keyboard.press('i');
        if (keys[8].isFilledRect == false) {
          tft.fillRect(104, 88, 32, 32, 0xFFFF);
          keys[8].isFilledRect = true;
        }
        break;
      }
    } else {
      switch (pin) {
      case TOP_LEFT_PIN:
        if (keys[0].isFilledRect == true) {
          tft.fillRect(24, 8, 32, 32, 0x0000);
          tft.drawRect(24, 8, 32, 32, 0xFFFF);
        }
        keys[0].isFilledRect = false;
        break;
      case TOP_MIDDLE_PIN:
        if (keys[1].isFilledRect == true) {
          tft.fillRect(64, 8, 32, 32, 0x0000);
          tft.drawRect(64, 8, 32, 32, 0xFFFF);
        }
        keys[1].isFilledRect = false;
        break;
      case TOP_RIGHT_PIN:
        if (keys[2].isFilledRect == true) {
          tft.fillRect(104, 8, 32, 32, 0x0000);
          tft.drawRect(104, 8, 32, 32, 0xFFFF);
        }
        keys[2].isFilledRect = false;
        break;
      case MIDDLE_LEFT_PIN:
        if (keys[3].isFilledRect == true) {
          tft.fillRect(24, 48, 32, 32, 0x0000);
          tft.drawRect(24, 48, 32, 32, 0xFFFF);
        }
        keys[3].isFilledRect = false;
        break;
      case MIDDLE_MIDDLE_PIN:
        if (keys[4].isFilledRect == true) {
          tft.fillRect(65, 48, 32, 32, 0x0000);
          tft.drawRect(65, 48, 32, 32, 0xFFFF);
        }
        keys[4].isFilledRect = false;
        break;
      case MIDDLE_RIGHT_PIN:
        if (keys[5].isFilledRect == true) {
          tft.fillRect(104, 48, 32, 32, 0x0000);
          tft.drawRect(104, 48, 32, 32, 0xFFFF);
        }
        keys[5].isFilledRect = false;
        break;
      case BOTTOM_LEFT_PIN:
        if (keys[6].isFilledRect == true) {
          tft.fillRect(24, 88, 32, 32, 0x0000);
          tft.drawRect(24, 88, 32, 32, 0xFFFF);
        }
        keys[6].isFilledRect = false;
        break;
      case BOTTOM_MIDDLE_PIN:
        if (keys[7].isFilledRect == true) {
          tft.fillRect(64, 88, 32, 32, 0x0000);
          tft.drawRect(64, 88, 32, 32, 0xFFFF);
        }
        keys[7].isFilledRect = false;
        break;
      case BOTTOM_RIGHT_PIN:
        if (keys[8].isFilledRect == true) {
          tft.fillRect(104, 88, 32, 32, 0x0000);
          tft.drawRect(104, 88, 32, 32, 0xFFFF);
        }
        keys[8].isFilledRect = false;
        break;

      default:
        break;
      }
    }
  }
}
