#include <Servo.h>

Servo myservo1;
Servo myservo2;

int pos1 = 0;
int pos2 = 0;


void setup() 
{
 
  myservo1.attach(11);// attache les cervomoteurs à la bonne pin
  myservo2.attach(10);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  pos1 = analogRead(0);
  Serial.println(pos1);
  pos1 = map(pos1,0,1023,0,180); //lis la valeur du potentiomètre et remet à l'échelle pour le servo
  myservo1.write(pos1); // donne la position voulue au servo
   pos2 = analogRead(2);
  Serial.println(pos2);
  pos2 = map(pos2,0,1023,0,180);
  myservo2.write(pos2);
 
}
