#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Keyboard.h>
Adafruit_ST7735 tft = Adafruit_ST7735(17,16,19,18,20);
GFXcanvas1 canvas = GFXcanvas1(160,128);
int testSwitchPin = 21;
void setup() {
  Serial.begin(115200);
  Keyboard.begin(KeyboardLayout_en_US);
  pinMode(testSwitchPin,INPUT_PULLUP);
  tft.initR();
  tft.setRotation(1);
  tft.setCursor(0,0);
  tft.fillScreen(ST7735_BLACK);
  canvas.setRotation(1);
  canvas.setCursor(0,0);
  canvas.fillRect(40, 16, 74, 62,1);
}



void loop(){
  // tft.fillScreen(ST7735_BLACK);
  // delay(1000);
  // tft.drawRect(40, 16, 74, 62, 1);
  // delay(1000);
  // tft.drawBitmap(0, 0, pressedCanvas.getBuffer(),pressedCanvas.width(), pressedCanvas.height(), 0xFFFF, 0x0000);
      
if (digitalRead(testSwitchPin) == LOW)
  {
    Keyboard.press('A');
    tft.setCursor(0,0);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.print("Switch pressed!");
    Serial.println("Switch pressed!");
  }
  else 
  {
    Keyboard.release('A');
    tft.setCursor(0,0);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.print("Switch not pressed!");
    Serial.println("Switch not pressed!");
  }
}

