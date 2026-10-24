#include <Servo.h>

Servo myservo;
char BT_reading;
int m1p1 = 4;
int m1p2 = 5;
int m2p1 = 6;
int m2p2 = 7;
int trig = 10;
int echo = 9;
long distance, duration;
int rightDistance;
int leftDistance;
int counter = 0;

void setup() {
  myservo.attach(8);
  Serial.begin(9600);

  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void left() {
   digitalWrite(m1p1, LOW);
   digitalWrite(m1p2, LOW);
   digitalWrite(m2p1, LOW);
   digitalWrite(m2p2, HIGH);
}

void backward() {
   digitalWrite(m1p1, HIGH);
   digitalWrite(m1p2, LOW);
   digitalWrite(m2p1, HIGH);
   digitalWrite(m2p2, LOW);
}

void forward() {
   digitalWrite(m1p1, LOW);
   digitalWrite(m1p2, HIGH);
   digitalWrite(m2p1, LOW);
   digitalWrite(m2p2, HIGH);
}

void right() {
   digitalWrite(m1p1, LOW);
   digitalWrite(m1p2, HIGH);
   digitalWrite(m2p1, LOW);
   digitalWrite(m2p2, LOW);
}

void stop() {
   digitalWrite(m1p1, LOW);
   digitalWrite(m1p2, LOW);
   digitalWrite(m2p1, LOW);
   digitalWrite(m2p2, LOW);
}

long getDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  return pulseIn(echo, HIGH) * 0.034 / 2;
}

void loop() {
  if (Serial.available()) {
    BT_reading = Serial.read();
    Serial.print("Received: ");
    Serial.println(BT_reading);
   
    if (BT_reading == 'H') {
      counter = 0;  
      Serial.println("Manual Mode");
    } else if (BT_reading == 'J') {
      counter = 1; 
      Serial.println("Auto Mode");
    }

    if (counter == 0) { 
      switch (BT_reading) {
        case 'F': forward(); break;
        case 'B': backward(); break;
        case 'R': right(); break;
        case 'L': left(); break;
        default: stop();
      }
    }
  }

  if (counter == 1) { 
  
    distance = getDistance();
    Serial.print("Distance: ");
    Serial.println(distance);
    
    if (distance > 20) {
      forward();
    } else {
      stop();
      delay(500);

      myservo.write(0);
      delay(500);
      rightDistance = getDistance();

      myservo.write(180);
      delay(500);
      leftDistance = getDistance(); 

      myservo.write(90);
      delay(500);
      
      if (rightDistance > leftDistance) {
        right();
        delay(500);
      } else {
        left();
        delay(500);
      }
    }
  }
}
