#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,20,4); 

void setup() {
  lcd.init();             
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Loading...");
  dht.begin();
}

void loop() { 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float hic = dht.computeHeatIndex(t, h, false);

  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("t:");
  lcd.print(t);
  lcd.setCursor(8,0);
  lcd.print("HI:");
  lcd.print(hic);
  lcd.setCursor(0,1);
  lcd.print("h:");
  lcd.print(h);
  lcd.print("%");
}
