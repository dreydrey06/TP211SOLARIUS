#include <Servo.h>

Servo servo.rotate;
Servo servo.incline; 

int pos.rorate;
int pos.incline;
int capt1val;
int capt2val;
int capt3val;
int capt4val;
int sensorValue;
int frequence = 1000; //milisec
float voltage;


String dataLabel0 = "Voltage sensor";
String dataLabel1 = "Photoresistor 1 ";
String dataLabel2 = "Photoresistor 2 ";
String dataLabel3 = "Photoresistor 3 ";
String dataLabel4 = "Photoresistor 4 ";
String dataLabel5 = "Angle of rotation ";
String dataLabel6 = "Angle of inclination ";
bool label = true;


void setup() 
{
  servo.rotate.attach(11);
  servo.incline.attach(10);
  pinMode(A0,INPUT_PULLUP); // capteur de tension 
  pinMode(A1,INPUT_PULLUP); // capteur 1
  pinMode(A2,INPUT_PULLUP); // capteur 2
  pinMode(A3,INPUT_PULLUP); // capteur 3
  pinMode(A3,INPUT_PULLUP); // capteur 4
  Serial.begin(9600);
}

void loop() 
{
  while(label)
  { //This will print the name of my colums for my future CSV file
        Serial.print(dataLabel1);
        Serial.print(",");
        Serial.println(dataLabel2);
        label=false;
   }
   
  capt1val = analogRead(A1);
  capt2val = analogRead(A2);
  capt3val = analogRead(A3);
  capt4val = analogRead(A4);
  sensorValue = analogRead(A0);
  voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);
  Serial.println(capt1val);
  Serial.println(capt2val);
  Serial.println(capt3val);
  Serial.println(capt4val);
  
  delay(frequence);
}
