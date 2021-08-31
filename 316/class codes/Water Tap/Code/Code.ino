#include<Servo.h>
#define trigPin 4
#define echoPin 5
Servo Myservo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Myservo.attach(3);
}
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds (2);
  digitalWrite (trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn (echoPin, HIGH);
  distance=(duration*0.034)/2;
  if(distance<20){
    Serial.println("distance less than 20 cm");
    Myservo.write(90);
  }
  else{
    Serial.println("distance greater than 20 cm");
    Myservo.write(0);
  } 
  delay(500);
}
