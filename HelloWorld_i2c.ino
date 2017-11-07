#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);  // Set the LCD I2C address

void setup()
{
  // Switch on the backlight
    
  lcd.init();
 lcd.backlight();

  // initialize the lcd 
  lcd.begin(16, 2);

 lcd.print("hellllllooooo");
  lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print (" WORLD!  ");      
}

void loop()
{

}
