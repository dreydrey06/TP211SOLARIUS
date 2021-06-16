
float voltage;
float power;
float resistance = 12.5;

void setup() {
 Serial.begin(9600);
}

void loop() {
  voltage = analogRead(A0);
  voltage = (voltage * 5 )/ 1023;
  power =(voltage * voltage)/ resistance ;
  Serial.println(power);
}
