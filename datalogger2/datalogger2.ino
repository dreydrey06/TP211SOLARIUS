
#include "SD.h"
#include"SPI.h"
//
//the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD
// library functions will not work.
const int CSpin = 10;
String dataString =""; // holds the data to be written to the SD card
float power = 0.00; // value read from your first sensor
float voltage = 0.00; // value read from your second sensor
File sensorData;
int number_of_mesure = 0;

float resistance = 12.5;
//
//
void setup()
{
// Open serial communications
Serial.begin(9600);
Serial.print("Initializing SD card...");
pinMode(CSpin, OUTPUT);
//
// see if the card is present and can be initialized:
if (!SD.begin(CSpin)) {
Serial.println("Card failed, or not present");
// don't do anything more:
return;
}
Serial.println("card initialized.");
}
//
void loop(){
// 
  number_of_mesure = number_of_mesure + 1;
  voltage = analogRead(A0);
  voltage = (voltage * 5 )/ 1023;
  power =(voltage * voltage)/ resistance ;
  Serial.println(power);
// build the data string
dataString = String(number_of_mesure)+ "," + String(power) + "," + String(voltage); // convert to CSV
saveData(); // save to SD card
delay(1000); // delay before next write to SD Card, adjust as required
}
//
void saveData(){
if(SD.exists("data.csv")){ // check the card is still there
// now append new data file
sensorData = SD.open("data.csv", FILE_WRITE);
if (sensorData){
sensorData.println(dataString);
sensorData.close(); // close the file
}
}
else{
Serial.println("Error writing to file !");
}
}
