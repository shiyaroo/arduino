int led1 =13;
int led2 =12;
int led3 =11;
int led4 =10;

void setup() {

pinMode (led1,OUTPUT);
pinMode (led2,OUTPUT);
pinMode (led3,OUTPUT);
pinMode (led4,OUTPUT);

}

void loop() {
  digitalWrite (led1,HIGH);
 delay (1000);
 digitalWrite (led2,HIGH);
 delay (1000);
digitalWrite (led3,HIGH);
 delay (1000);
digitalWrite (led4,HIGH);
 delay (1000);
 digitalWrite (led1,LOW);
 delay (1000);
 digitalWrite (led2,LOW);
 delay (1000);
  digitalWrite (led3,LOW);
 delay (1000);
 digitalWrite (led4,LOW);
 delay (1000);


}
