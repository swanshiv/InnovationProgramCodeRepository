/* 
 * Program for gesture control VLC Player
 * Controlled uisng Python
 * Code by Shivranjan Kolvankar
 * Dated: 11-10-2017
 * Learning Links Foundation
 */
const int trigger1 = 2; //Trigger pin of 1st Sesnor
const int echo1 = 3; //Echo pin of 1st Sesnor
const int trigger2 = 4; //Trigger pin of 2nd Sesnor
const int echo2 = 5;//Echo pin of 2nd Sesnor
long time_taken;
int dist,distL,distR;
 
void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
}
/*###Function to calculate distance###*/
void calculate_distance(int trigger, int echo)
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  time_taken = pulseIn(echo, HIGH);
  dist= time_taken*0.034/2;
}
void loop() { //infinite loopy
  calculate_distance(trigger1,echo1);
  distL =dist; //get distance of left sensor
  calculate_distance(trigger2,echo2);
  distR =dist; //get distance of right sensor
  Serial.println(distL);
}
