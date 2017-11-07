 #include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int trigPin =8;
const int echoPin = 9;
 
 int cm;
 int redled= 13;
 int yallwoled= 12;
 int blueled= 11;
int buzzer =3;

int sound = 500;

byte armsUp[8] = {0b00100, 0b01010, 0b00100, 0b10101, 0b01110, 0b00100, 0b00100, 0b01010};
byte armsDown[8] = {0b00100, 0b01010, 0b00100, 0b00100, 0b01110, 0b10101, 0b00100, 0b01010};

void setup() {
  lcd.init(); 
 lcd.backlight();
lcd.begin(16, 2);
 lcd.clear();
 lcd.setCursor(0 , 0);
lcd.println("WELCOME  TNTU      ");// Print a message to the LCD.
  delay(1000);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(blueled, OUTPUT);
  pinMode(yallwoled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.createChar (0, armsUp);    // load character to the LCD
  lcd.createChar (1, armsDown);    // load character to the LCD
 
}

 
void loop()
{
 long duration, distance; 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
  for (int i = 0; i <= 15; i++) ;
  for (int i = 15; i >= 0; i--) ;
  if (distance >= 91) {


      lcd.setCursor(0 , 0);
lcd.println("WELCOME TNTU       ");
       lcd.setCursor(0 , 1);
 lcd.print(char(random(0, 2))); // show one of the two custom characters
  delay(150); // wait so it can be seen
  lcd.setCursor ( 0, 1 ); // go to position again
  lcd.print(" ");
 }

 if (distance <= 90) {
    digitalWrite(blueled, HIGH);
    
     lcd.setCursor(0 , 0);
 
     lcd.println("Safety distance  ");
         sound = 0;

 }
  else {
    digitalWrite(blueled,LOW);
  }
  if (distance <= 50) {
    digitalWrite(blueled, HIGH);
    
     lcd.setCursor(0 , 0);

     lcd.println("Be Careful          ");
    sound = 100;
}
  else {
    digitalWrite(blueled,LOW);
  }
  if (distance < 35) {
      digitalWrite(yallwoled, HIGH);
           lcd.setCursor(0 , 0);

     lcd.println("you are closer        ");
      sound = 250;
}
  else {
      digitalWrite(yallwoled, LOW);
  }
 
  if (distance < 15) {
    digitalWrite(redled, HIGH);
     lcd.setCursor(0 , 0);
    lcd.println("danger!           ");
    sound = 500;
}
  else {
    digitalWrite(redled,LOW);
  }
 

  if (distance > 50 ){
  
      digitalWrite(redled,LOW);
       sound = 0;
    noTone(buzzer);
  }
  else {
  lcd.setCursor(0 ,1);
    lcd.print(distance);
   lcd.println("CM              ");
    tone(buzzer, sound);
   
  }
  delay(250);
}





 
 
