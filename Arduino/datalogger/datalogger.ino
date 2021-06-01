#include <Servo.h>

Servo servo.rotate;
Servo servo.incline; 

int pos.rorate;
int pos.incline;

void setup() {
  servo.rotate.attach();
  servo.incline.attach();
  pinMode(A0,INPUT_PULLUP); // capteur 1
  pinMode(A1,INPUT_PULLUP); // capteur 2
  pinMode(A2,INPUT_PULLUP); // capteur 3
  pinMode(A3,INPUT_PULLUP); // capteur 4
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
