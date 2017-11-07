#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 



void setup () {
   lcd.begin (16,2); // Set baudrate to 9600
     lcd.init();
  lcd.backlight();

}



void loop () {
   lcd.print ( "** shiyar **");
  lcd.setCursor ( 0, 1 );        // go to the next line
   lcd.print ( "**shiyaroo**");
  lcd.setCursor ( 0, 1 );        // go to the next line

   delay (1000);
}
