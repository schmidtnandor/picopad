#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

static constexpr uint8_t PIN_SWITCH = 21;
static constexpr bool SWITCH_ACTIVE_LOW = true;
static constexpr uint8_t TFT_CS = 17;
static constexpr uint8_t TFT_DC = 16;
static constexpr uint8_t TFT_RST = 20;
static constexpr uint8_t TFT_SCK = 18;
static constexpr uint8_t TFT_MOSI = 19;

Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST);

void setup() {
  Serial.begin(115200);
  pinMode(PIN_SWITCH, SWITCH_ACTIVE_LOW ? INPUT_PULLUP : INPUT_PULLDOWN);

  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
  tft.setTextSize(1);
  tft.setCursor(0, 0);
  tft.println("Ready");
  tft.println("Waiting for switch...");
}

void loop() {
  static int lastState = HIGH;
  static unsigned long lastChangeMs = 0;
  static unsigned long lastDrawMs = 0;

  int state = digitalRead(PIN_SWITCH);
  if (state != lastState && (millis() - lastChangeMs) > 20) {
    lastChangeMs = millis();
    lastState = state;
    lastDrawMs = 0; // force redraw on change
  }

  if (millis() - lastDrawMs > 200) {
    lastDrawMs = millis();
    bool pressed = SWITCH_ACTIVE_LOW ? (state == LOW) : (state == HIGH);
    Serial.println(pressed ? "GPIO21 pressed" : "GPIO21 released");

   
    tft.setCursor(0, 0);
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    tft.setTextSize(2);
    tft.println(pressed ? "Pressed!" : "Released");
    tft.setTextSize(1);
    tft.println(" ");
    tft.print("Raw: ");
    tft.println(state == LOW ? "LOW" : "HIGH");
  }

  delay(5);
}