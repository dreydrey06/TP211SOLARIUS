#include <Servo.h>

Servo servo_rotate;
Servo servo_incline; 

int pos_rotate = 0;
int pos_incline = 0;

int top_left_capt;
int top_right_capt;
int bottom_left_capt;
int bottom_right_capt;

int top_average;
int bottom_average;
int left_average;
int right_average;

int difference_topdown;
int difference_sides;
const int margin = 40;


void setup() 
{
  servo_rotate.attach(11);
  servo_incline.attach(9);
  
  Serial.begin(9600);
}
void loop() {
  
  top_left_capt = analogRead(A2); //reading data from sensors
  top_right_capt = analogRead(A3);
  bottom_left_capt = analogRead(A0);
  bottom_right_capt = analogRead(A1);
  pos_incline = servo_incline.read();
  pos_rotate = servo_rotate.read();

  Serial.println(pos_incline);

  

  bottom_average = ( bottom_left_capt + bottom_right_capt )/2; //average of the two lower sensors 
  top_average = (top_left_capt + top_right_capt)/2;            //average of the two upper sensors 
  left_average = ( top_left_capt + bottom_left_capt) / 2;      //average of the sensors on the left
  right_average = ( top_right_capt + bottom_right_capt) / 2;   //average of the sensors on the right
  
  difference_topdown = abs(bottom_average - top_average); //checking the difference 
  difference_sides = abs(left_average - right_average);
  
  if ((top_average > bottom_average) && (difference_topdown > margin))
    {
     if (pos_incline < 180) //if different from max val
       {
       pos_incline = pos_incline + 1;
       servo_incline.write(pos_incline);
       delay(5);
       }
    }
    
  if((bottom_average > top_average) && (difference_topdown > margin))
    {
    if (pos_incline > 0) //if different from min val
      {
       pos_incline = pos_incline - 1;
       servo_incline.write(pos_incline);
       delay(5);
      }
    }
    
  if ((right_average > left_average) && (difference_sides > margin))
    {
     if (pos_rotate < 180) //if different from max val
       {
       pos_rotate = pos_rotate + 1;
       servo_rotate.write(pos_rotate);
       delay(5);
       }
    }
    
  if((left_average > right_average) && (difference_sides > margin))
    {
    if (pos_rotate > 0) //if different from min val
      {
       pos_incline =pos_incline - 1;
       servo_rotate.write(pos_rotate);
       delay(5);
      }
    }

  delay(25);
}
