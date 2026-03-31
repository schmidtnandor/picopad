#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Keyboard.h>
Adafruit_ST7735 tft = Adafruit_ST7735(5, 6, 3, 2, 7);
int pins[9] = {9, 12, 15, 10, 11, 19, 16, 21, 17};
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
    keys[i].pin = pins[i];
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

  Serial.println();
  analogRead(28);
  delay(10);
  for (int pin : pins) {
    if (digitalRead(pin) == LOW) {
      switch (pin) {
      case 9:
        Keyboard.write('a');
        if (keys[0].isFilledRect == false) {
          tft.fillRect(24, 8, 32, 32, 0xFFFF);
          keys[0].isFilledRect = true;
        }
        break;
      case 10:
        Keyboard.write('b');
        if (keys[1].isFilledRect == false) {
          tft.fillRect(24, 48, 32, 32, 0xFFFF);
          keys[1].isFilledRect = true;
        }
        break;
      case 12:
        Keyboard.write('c');
        if (keys[2].isFilledRect == false) {
          tft.fillRect(24, 88, 32, 32, 0xFFFF);
          keys[2].isFilledRect = true;
        }
        break;
      case 15:
        Keyboard.write('d');
        if (keys[3].isFilledRect == false) {
          tft.fillRect(64, 8, 32, 32, 0xFFFF);

          keys[3].isFilledRect = true;
        }
        break;
      case 11:
        Keyboard.write('e');
        if (keys[4].isFilledRect == false) {
          tft.fillRect(65, 48, 32, 32, 0xFFFF);
          keys[4].isFilledRect = true;
        }
        break;
      case 19:
        Keyboard.write('f');
        if (keys[5].isFilledRect == false) {
          tft.fillRect(64, 88, 32, 32, 0xFFFF);
          keys[5].isFilledRect = true;
        }
        break;
      case 16:
        Keyboard.write('g');
        if (keys[6].isFilledRect == false) {
          tft.fillRect(104, 8, 32, 32, 0xFFFF);
          keys[6].isFilledRect = true;
        }
        break;
      case 21:
        Keyboard.write('h');
        if (keys[7].isFilledRect == false) {
          tft.fillRect(104, 48, 32, 32, 0xFFFF);
          keys[7].isFilledRect = true;
        }
        break;
      case 17:
        Keyboard.write('i');
        if (keys[8].isFilledRect == false) {
          tft.fillRect(104, 88, 32, 32, 0xFFFF);
          keys[8].isFilledRect = true;
        }
        break;
      }
    } else {
      switch (pin) {
      case 9:
        if (keys[0].isFilledRect == true) {
          tft.fillRect(24, 8, 32, 32, 0x0000);
          tft.drawRect(24, 8, 32, 32, 0xFFFF);
        }
        keys[0].isFilledRect = false;
        break;
      case 10:
        if (keys[1].isFilledRect == true) {
          tft.fillRect(24, 48, 32, 32, 0x0000);
          tft.drawRect(24, 48, 32, 32, 0xFFFF);
        }
        keys[1].isFilledRect = false;
        break;
      case 12:
        if (keys[2].isFilledRect == true) {
          tft.fillRect(24, 88, 32, 32, 0x0000);
          tft.drawRect(24, 88, 32, 32, 0xFFFF);
        }
        keys[2].isFilledRect = false;
        break;
      case 15:
        if (keys[3].isFilledRect == true) {
          tft.fillRect(64, 8, 32, 32, 0x0000);
          tft.drawRect(64, 8, 32, 32, 0xFFFF);
        }
        keys[3].isFilledRect = false;
        break;
      case 11:
        if (keys[4].isFilledRect == true) {
          tft.fillRect(65, 48, 32, 32, 0x0000);
          tft.drawRect(65, 48, 32, 32, 0xFFFF);
        }
        keys[4].isFilledRect = false;
        break;
      case 19:
        if (keys[5].isFilledRect == true) {
          tft.fillRect(64, 88, 32, 32, 0x0000);
          tft.drawRect(64, 88, 32, 32, 0xFFFF);
        }
        keys[5].isFilledRect = false;
        break;
      case 16:
        if (keys[6].isFilledRect == true) {
          tft.fillRect(104, 8, 32, 32, 0x0000);
          tft.drawRect(104, 8, 32, 32, 0xFFFF);
        }
        keys[6].isFilledRect = false;
        break;
      case 21:
        if (keys[7].isFilledRect == true) {
          tft.fillRect(104, 48, 32, 32, 0x0000);
          tft.drawRect(104, 48, 32, 32, 0xFFFF);
        }
        keys[7].isFilledRect = false;
        break;
      case 17:
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
