#include <LCD_I2C.h>
#include <HCSR04.h>

LCD_I2C lcd(0x3F, 16, 2);

// LIBRARY
 float distance; 
 const byte triggerPin = 13; //OUTPUT
 const byte echoPin = 12;  //INPUT
 UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup() {
  Serial.begin(9600);  
  lcd.begin(); 
  lcd.backlight();
}

void loop() {
    lcd.setCursor(0, 0); 
    lcd.print("Distance:"); 
    distance = distanceSensor.measureDistanceCm();
    lcd.setCursor(9, 0); 
    lcd.print(distance); 
    lcd.setCursor(14, 0); 
    lcd.print("cm"); 
    delay(200);
}