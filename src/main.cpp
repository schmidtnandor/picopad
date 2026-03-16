#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Keyboard.h>
Adafruit_ST7735 tft = Adafruit_ST7735(17, 16, 19, 18, 20);
int pins[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
const int keyCount = sizeof(pins) / sizeof(pins[0]);
class Key {
public:
  int pin;
  bool isFilledRect;
};
Key keys[9];
int sliderPowerPin = 12;
void setup() {
  Serial.begin(115200);
  Keyboard.begin(KeyboardLayout_en_US);
  pinMode(sliderPowerPin, OUTPUT);
  digitalWrite(sliderPowerPin, HIGH);
  for (int pin : pins) {
    pinMode(pin, INPUT_PULLUP);
  }

  for (int i = 0; i < keyCount; i++) {
    keys[i].pin = pins[i];
    keys[i].isFilledRect = false;
  }
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
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
  analogRead(28);
  delay(10);
  int sliderValue = analogRead(28);
  Serial.println(sliderValue);
  for (int pin : pins) {
    if (digitalRead(pin) == LOW) {
      switch (pin) {
      case 0:
        Keyboard.write('a');
        if (keys[0].isFilledRect == false) {
          tft.fillRect(24, 8, 32, 32, 0xFFFF);
          keys[0].isFilledRect = true;
        }
        break;
      case 1:
        Keyboard.write('b');
        if (keys[1].isFilledRect == false) {
          tft.fillRect(24, 48, 32, 32, 0xFFFF);
          keys[1].isFilledRect = true;
        }
        break;
      case 2:
        Keyboard.write('c');
        if (keys[2].isFilledRect == false) {
          tft.fillRect(24, 88, 32, 32, 0xFFFF);
          keys[2].isFilledRect = true;
        }
        break;
      case 3:
        Keyboard.write('d');
        if (keys[3].isFilledRect == false) {
          tft.fillRect(64, 8, 32, 32, 0xFFFF);
          keys[3].isFilledRect = true;
        }
        break;
      case 4:
        Keyboard.write('e');
        if (keys[4].isFilledRect == false) {
          tft.fillRect(65, 48, 32, 32, 0xFFFF);
          keys[4].isFilledRect = true;
        }
        break;
      case 5:
        Keyboard.write('f');
        if (keys[5].isFilledRect == false) {
          tft.fillRect(64, 88, 32, 32, 0xFFFF);
          keys[5].isFilledRect = true;
        }
        break;
      case 6:
        Keyboard.write('g');
        if (keys[6].isFilledRect == false) {
          tft.fillRect(104, 8, 32, 32, 0xFFFF);
          keys[6].isFilledRect = true;
        }
        break;
      case 7:
        Keyboard.write('h');
        if (keys[7].isFilledRect == false) {
          tft.fillRect(104, 48, 32, 32, 0xFFFF);
          keys[7].isFilledRect = true;
        }
        break;
      case 8:
        Keyboard.write('i');
        if (keys[8].isFilledRect == false) {
          tft.fillRect(104, 88, 32, 32, 0xFFFF);
          keys[8].isFilledRect = true;
        }
        break;
      }
    } else {
      switch (pin) {
      case 0:
        if (keys[0].isFilledRect == true) {
          tft.fillRect(24, 8, 32, 32, 0x0000);
          tft.drawRect(24, 8, 32, 32, 0xFFFF);
        }
        keys[0].isFilledRect = false;
        break;
      case 1:
        if (keys[1].isFilledRect == true) {
          tft.fillRect(24, 48, 32, 32, 0x0000);
          tft.drawRect(24, 48, 32, 32, 0xFFFF);
        }
        keys[1].isFilledRect = false;
        break;
      case 2:
        if (keys[2].isFilledRect == true) {
          tft.fillRect(24, 88, 32, 32, 0x0000);
          tft.drawRect(24, 88, 32, 32, 0xFFFF);
        }
        keys[2].isFilledRect = false;
        break;
      case 3:
        if (keys[3].isFilledRect == true) {
          tft.fillRect(64, 8, 32, 32, 0x0000);
          tft.drawRect(64, 8, 32, 32, 0xFFFF);
        }
        keys[3].isFilledRect = false;
        break;
      case 4:
        if (keys[4].isFilledRect == true) {
          tft.fillRect(65, 48, 32, 32, 0x0000);
          tft.drawRect(65, 48, 32, 32, 0xFFFF);
        }
        keys[4].isFilledRect = false;
        break;
      case 5:
        if (keys[5].isFilledRect == true) {
          tft.fillRect(64, 88, 32, 32, 0x0000);
          tft.drawRect(64, 88, 32, 32, 0xFFFF);
        }
        keys[5].isFilledRect = false;
        break;
      case 6:
        if (keys[6].isFilledRect == true) {
          tft.fillRect(104, 8, 32, 32, 0x0000);
          tft.drawRect(104, 8, 32, 32, 0xFFFF);
        }
        keys[6].isFilledRect = false;
        break;
      case 7:
        if (keys[7].isFilledRect == true) {
          tft.fillRect(104, 48, 32, 32, 0x0000);
          tft.drawRect(104, 48, 32, 32, 0xFFFF);
        }
        keys[7].isFilledRect = false;
        break;
      case 8:
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
