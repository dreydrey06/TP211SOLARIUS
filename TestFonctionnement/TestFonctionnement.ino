#include <Servo.h>

Servo myservo1;
Servo myservo2;

int pos1 = 0;
int pos2 = 0;


void setup() 
{
 
  myservo1.attach(11);// attache les cervomoteurs à la bonne pin
  myservo2.attach(10);

  pinMode(A0,INPUT_PULLUP); // attache les potentiomètres à la bonne pin
  pinMode(A1,INPUT_PULLUP);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  pos1 = map(digitalRead(A0),0,1230,0,180) //lis la valeur du potentiomètre et remet à l'échelle pour le servo
  myservo1.write(pos1); // donne la position voulue au servo
  pos2 = map(digitalRead(A1),0,1230,0,180)
  myservo2.write(pos2);
 
}
