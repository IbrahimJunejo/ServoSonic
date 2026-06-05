# ServoSonic — Wiring / Connection Table

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

## ⚠️ Important Notes

1. Power servo from separate 5V adapter — NOT Arduino 5V pin
2. Connect adapter GND to Arduino GND (common ground)
3. Use 220 ohm resistor with LED to prevent burning
4. TRIG and ECHO pins must not be swapped
