// Project 42 - Detecting Collisions with an Ultrasonic Distance Sensor
//libraries
#include <HCSR04.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
//pin definitions
#define TFT_CS   10
#define TFT_RST   9   
#define TFT_DC    8
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
// tft screen dimensions
#define SCREEN_W  240
#define SCREEN_H  320

// set up ultrasonic sensor
UltraSonicDistanceSensor HCSR04(2, 13); // trig - D2, echo - D13

boolean crash=false;

void setup()
{
 Serial.begin(9600); 
 tft.init(240, 320);          
 tft.fillScreen(ST77XX_BLACK);
}

void checkDistance()
{
  float distance;
  distance = HCSR04.measureDistanceCm();
   if (distance < 2) // crash distance set to 2 cm 
  {
    Serial.print("CRASHED");
    crash = true;
    delay(50);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(1);
    tft.setCursor(10, SCREEN_H / 2 - 4);
    tft.println("CRASHED!!!!!!!");
  }
  else
  { 
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(1);
    tft.setCursor(10, SCREEN_H / 2 - 4);
    tft.println("WAITING FOR CRASH...");}
}


void loop()
{
  checkDistance();
  delay(50);
}