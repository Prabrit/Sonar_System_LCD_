#include <Servo.h>
#include <LiquidCrystal.h>
 
Servo myservo;
LiquidCrystal lcd(4, 6, 10, 11, 12, 13); 
 
int pos = 0; 
const int trigPin = 7;
const int echoPin = 5;
const int servo = 9;

float distanceCm, duration;
 
void setup() {
myservo.attach(servo); 
lcd.begin(16,2); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);


 
}
 
void loop() {
for (pos = 0; pos <= 180; pos += 1) { 

myservo.write(pos); 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;

lcd.setCursor(0,0);
lcd.print("Distance: "); 
lcd.print(distanceCm);  
delay(80);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(80); 
 
}
for (pos = 180; pos >= 0; pos -= 1) { 
myservo.write(pos); 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;

lcd.setCursor(0,0); 
lcd.print("Distance: "); 
lcd.print(distanceCm); 
delay(80);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(80);
}
}
