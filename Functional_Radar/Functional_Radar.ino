#include <Servo.h>

#define PIN_TRIG 3
#define PIN_ECHO 2

Servo myServo;
int pos = 0;   
bool movingForward = true; 
bool objectDetected = false;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  myServo.attach(9); 
  pinMode(4, OUTPUT); 
}

void loop() {
  if (!objectDetected) {
    if (movingForward) {
  
      for (; pos <= 180; pos++) {
        myServo.write(pos);
        delay(10);
        if (checkDistance()) {
          objectDetected = true;
          break; 
        }
      }
      if (!objectDetected) {
        movingForward = false; 
      }
    } else {
     
      for (; pos >= 0; pos--) {
        myServo.write(pos);
        delay(10);
        if (checkDistance()) {
          objectDetected = true;
          break; 
        }
      }
      if (!objectDetected) {
        movingForward = true;
      }
    }
  } else {
    
    if (!checkDistance()) {
      objectDetected = false;
      noTone(4); 
    }
  }
}

bool checkDistance() {
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  int duration = pulseIn(PIN_ECHO, HIGH);
  int dist = duration / 58;

  Serial.print("Distance in CM: ");
  Serial.println(dist);

  if (dist < 50 && dist != 0) { 
    tone(4, 2000); 
    Serial.println("Object detected below 50 cm, stopping.");
    return true; 
  }
  return false; 
}
