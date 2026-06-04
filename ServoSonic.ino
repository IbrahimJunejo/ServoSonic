/*
  ServoSonic - Ultrasonic Sensor with Servo Motor Scanner
  ========================================================
  Project: ServoSonic
  Description: 180° proximity scanner using HC-SR04 ultrasonic sensor
               mounted on a servo motor. Triggers buzzer and LED when
               object detected within 10cm range.

  Components:
  - Arduino Uno
  - HC-SR04 Ultrasonic Sensor
  - MG90S / SG90 Servo Motor
  - Buzzer
  - LED + 220 ohm resistor

  Connections:
  - HC-SR04 TRIG  → Pin 9
  - HC-SR04 ECHO  → Pin 8
  - Servo Signal  → Pin 3
  - Buzzer +      → Pin 4
  - LED +         → Pin 5 (via 220 ohm resistor)

  Author: ServoSonic Project
  License: Open Source - Free for educational use
*/

#include <Servo.h>

const int trigPin = 9;
const int echoPin = 8;
const int buzzerPin = 4;
const int ledPin = 5;

long duration;
int distance;

Servo myServo;

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  myServo.attach(3);
  myServo.write(90);
  delay(1000);
}

void loop() {
  // Sweep left to right
  for (int angle = 0; angle <= 180; angle += 5) {
    myServo.write(angle);
    delay(100);
    distance = getDistance();
    if (distance > 0 && distance < 10) {
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
    }
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  // Sweep right to left
  for (int angle = 180; angle >= 0; angle -= 5) {
    myServo.write(angle);
    delay(100);
    distance = getDistance();
    if (distance > 0 && distance < 10) {
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
    }
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}
