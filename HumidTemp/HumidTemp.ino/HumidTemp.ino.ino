#include <dht.h>

dht DHT;

#define DHT11_PIN 10
#define BUZZ_PIN 7
#define VIBRATION_MOTOR 3
#define INDICATOR_LED 12

int delay_count=0;

void setup(){
  Serial.begin(9600);
  pinMode(DHT11_PIN, INPUT);
  pinMode(INDICATOR_LED, OUTPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(VIBRATION_MOTOR, OUTPUT);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);

  if(delay_count>20)
  {
    digitalWrite(INDICATOR_LED, HIGH);
    tone(BUZZ_PIN, 1000); // Send 1KHz sound signal...
    delay(5000);        // ...for 1 sec
    noTone(BUZZ_PIN);     // Stop sound...
    delay(5000);        // ...for 1sec
    digitalWrite(VIBRATION_MOTOR, HIGH);
    delay(10000);
    delay_count = 0;
  }
  else
  {
    delay_count++;
    digitalWrite(INDICATOR_LED, LOW);
    digitalWrite(VIBRATION_MOTOR, LOW);
  }
  delay(100);
}

