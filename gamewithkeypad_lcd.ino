#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const byte ROWS = 4;
const byte COLS = 4; 

char Keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};  

Keypad mykeypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 
void setup(){
 
  lcd.init();                      
 lcd.backlight();
 lcd.begin(16,2);
  
}
  
void loop(){
  char key = mykeypad.getKey();
 if(key!=NO_KEY){
  lcd.setCursor(0,0);
  lcd.print(key);
   lcd.print(" enta ga7esh");
 }
  }
