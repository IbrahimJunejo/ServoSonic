# ServoSonic 🔊
### How to Use Ultrasonic Sensor with Servo Motor — Arduino Project

![Arduino](https://img.shields.io/badge/Arduino-Uno-blue)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-green)
![Cost](https://img.shields.io/badge/Cost-Budget%20Friendly-yellow)

---

## 📌 What is ServoSonic?

ServoSonic is a beginner-friendly Arduino project that combines an **HC-SR04 Ultrasonic Sensor** with a **Servo Motor** to create a **180° proximity scanner**.

Instead of detecting objects in just one fixed direction, the servo continuously rotates the ultrasonic sensor — scanning the entire area and triggering a **buzzer** and **LED** when anything comes too close.

---

## 🤔 Why Combine Servo + Ultrasonic?

| Only Ultrasonic Sensor | ServoSonic |
|---|---|
| Detects in 1 direction only | Scans full 180° area |
| Misses side objects | Detects everything in range |
| Fixed position | Rotating scanner |
| Limited use cases | Security / alarm system |

---

## 🛒 Components Required

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno | 1 | Brain of the project |
| HC-SR04 Ultrasonic Sensor | 1 | Measures distance |
| MG90S / SG90 Servo Motor | 1 | Rotates the sensor |
| Buzzer | 1 | Audio alert |
| LED (any color) | 1 | Visual alert |
| 220Ω Resistor | 1 | For LED |
| Breadboard | 1 | Connections |
| Jumper Wires | Several | Connections |
| 5V 2A Power Adapter | 1 | Powers the servo |

---

## 🔌 Wiring / Connection Table

| Component | Pin/Leg | Connects To |
|---|---|---|
| HC-SR04 | VCC | Arduino 5V |
| HC-SR04 | GND | Arduino GND |
| HC-SR04 | TRIG | Arduino Pin 9 |
| HC-SR04 | ECHO | Arduino Pin 8 |
| Servo | Red (VCC) | 5V Adapter + |
| Servo | Black/Brown (GND) | GND |
| Servo | Yellow/Orange (Signal) | Arduino Pin 3 |
| Buzzer | + (Long leg) | Arduino Pin 4 |
| Buzzer | - (Short leg) | GND |
| LED | + (Long leg) | 220Ω → Arduino Pin 5 |
| LED | - (Short leg) | GND |
| 5V Adapter | GND | Arduino GND |
| Arduino | Power | USB / Laptop |

> ⚠️ **Important:** Connect servo to a separate 5V adapter — not Arduino's 5V pin. Servo draws too much current and will interfere with the ultrasonic sensor!

---

## 💻 Code

```cpp
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
```

---

## ⚙️ How It Works

1. Power on Arduino
2. Servo automatically starts sweeping from **0° to 180°** and back
3. At each angle, ultrasonic sensor measures distance
4. If object detected **under 10cm** → LED turns ON + Buzzer beeps
5. Object removed → LED and Buzzer turn OFF, servo continues sweeping
6. Open **Serial Monitor at 9600 baud** to see live angle and distance readings

---

## 📊 Serial Monitor Output

```
Angle: 0   | Distance: 45 cm
Angle: 5   | Distance: 43 cm
Angle: 10  | Distance: 8 cm   ← Object detected!
Angle: 15  | Distance: 7 cm   ← Object detected!
Angle: 20  | Distance: 42 cm
```

---

## 🌍 Real World Uses

- 🔒 **Security / Intruder Alert System**
- 🤖 **Robot Obstacle Detection**
- 🏭 **Object Detection on Conveyor Belt**
- 🎓 **School / College Science Project**
- 🖥️ **Connect with Processing IDE for Visual Radar Display**

---

## 🔧 Troubleshooting

| Problem | Solution |
|---|---|
| Sensor reads 0 constantly | Check TRIG/ECHO wires — may be swapped |
| Buzzer beeping constantly | Servo interfering — power servo separately |
| Servo not moving | Check signal wire on Pin 3 |
| Inconsistent readings | Add 1000uF capacitor across 5V and GND |

---

## 📈 Possible Upgrades

- Add **Processing IDE** for a visual radar screen
- Add **OLED display** to show distance on device
- Add **ESP32** for WiFi alerts on your phone
- Add **PIR sensor** for human-specific detection
- Add **camera module** for a full security system

---

## 👤 Author

Made with ❤️ using Arduino

---

## 📄 License

This project is open source and free to use for educational purposes.
