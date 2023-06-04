#include <LCD_I2C.h>
#include <ArxStringUtils.h>

LCD_I2C lcd(0x3F, 16, 2); 
int val = 0;
String morseCode = "";
uint8_t wow[8] =
{
    0b00000,
    0b00000,
    0b00000,
    0b01110,
    0b01110,
    0b00000,
    0b00000,
    0b00000,
};

uint8_t line[8] =
{
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b00000,
    0b00000,
    0b00000
};

void returnSymbol(){
   delay(300);
   val = analogRead(A1);
   if(val <= 150){
      lcd.write(1);
      morseCode += "*";
      } else {
        lcd.write(3);
        morseCode += "-";
      }   
}

String returnLetter(String morseCode){
    if(morseCode == "*-"){
      return "A";
    } else if( morseCode == "-***"){
      return "B";
    } else if( morseCode == "-*-*"){
      return "C";
    } else if( morseCode == "-**"){
      return "D";
    } else if( morseCode == "*"){
      return "E";
    } else if( morseCode == "**-*"){
      return "F";
    } else if( morseCode == "--*"){
      return "G"; 
    } else if( morseCode == "****"){
      return "H";
    } else if( morseCode == "**"){
      return "I";
    } else if( morseCode == "*---"){
      return "J";
    } else if( morseCode == "-*-"){
      return "K";
    } else if( morseCode == "*-**"){
      return "L";
    } else if( morseCode == "--"){
      return "M";
    } else if( morseCode == "-*"){
      return "N";
    } else if( morseCode == "---"){
      return "O";
    } else if( morseCode == "*--*"){
      return "P";
    } else if( morseCode == "--*-"){
      return "Q";
    } else if( morseCode == "*-*"){
      return "R";
    } else if( morseCode == "***"){
      return "S";
    } else if( morseCode == "-"){
      return "T";
    } else if( morseCode == "**-"){
      return "U";
    } else if( morseCode == "***-"){
      return "V";
    } else if( morseCode == "*--"){
      return "W";
    } else if( morseCode == "-**-"){
      return "X";
    } else if( morseCode == "-*--"){
      return "Y";
    } else if( morseCode == "--**"){
      return "Z";
    }
    return "Wrong";
}
void setup()
{
    lcd.begin();
    lcd.backlight();

    Serial.begin(9600); 
    pinMode(2, INPUT_PULLUP);  // LOW = ACTIVE
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(14, INPUT); 

    lcd.createChar(1, wow);
    lcd.createChar(3, line);
}

void loop()
{     
     morseCode = "";
       lcd.clear();
     while(true){
       lcd.backlight();
       delay(600);
       lcd.setCursor(5, 0);
       lcd.print("Morse"); 
       lcd.setCursor(5, 1); 
       lcd.print("Code!");
       delay(900);
       lcd.clear();
       lcd.noBacklight();
       delay(100);
       
       if(digitalRead(2) == LOW) {
        lcd.clear();
        lcd.setCursor(0,0);
        delay(500);
        lcd.backlight(); // if light off
        break;
       }
     }
     while(true){
      
      if(digitalRead(3) == LOW){
       returnSymbol();        
      }
      if(digitalRead(4) == LOW){ //Finished code
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Letter:"); 
       lcd.setCursor(5, 1); //TEST
       lcd.print(returnLetter(morseCode));  
       delay(5000);
       break;
      }  
     }   
}