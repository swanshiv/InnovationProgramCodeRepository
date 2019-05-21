int motionState = 0;
int motionSense = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(motionSense,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  motionState = digitalRead(motionSense);
  if(motionState == HIGH)
  {
    Serial.println("Motion");
    digitalWrite(13,HIGH);
  }
  else
  {
    Serial.println("No Motion");
    digitalWrite(13,LOW);
  }

  delay(5000);

  
}
