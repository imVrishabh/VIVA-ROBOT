# 🤖 VIVA Robot V1

VIVA V1 is the first prototype of a voice-ready Bluetooth-controlled robot built using Arduino UNO. It supports manual control, automatic obstacle avoidance, and a servo-based hand movement. This version is designed as the foundation for future AI and voice assistant features.

---

# 🚀 Features

- Bluetooth Control (HC-05)
- Auto Obstacle Avoidance
- Manual Driving Mode
- Servo Hand Movement
- Ultrasonic Distance Detection
- 4 Wheel Drive
- Arduino UNO Based
- Easy Upgrade for AI & Voice
- LED Eyes

---

# 🛠 Hardware Used

| Component | Quantity |
|-----------|----------|
| Arduino UNO | 1 |
| L298N Motor Driver | 1 |
| HC-05 Bluetooth Module | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| SG90 Servo Motor | 1 |
| BO Motors | 4 |
| Robot Chassis | 1 |
| Wheels | 4 |
| Castor Wheel | 1 |
| 3 × 18650 Battery | 1 Pack |
| Switch | 1 |
| Jumper Wires | As Required |
|LED Eyes | 2 | 

---

# 📌 Bluetooth Commands

| Command | Function |
|----------|----------|
| F | Forward |
| B | Backward |
| L | Left |
| R | Right |
| S | Stop |
| A | Auto Mode |
| M | Manual Mode |
| H | Hand Movement |

---

# ⚙ Working

### Manual Mode

The robot receives commands from the HC-05 Bluetooth module and moves accordingly.

- Forward
- Backward
- Left
- Right
- Stop

---

### Auto Mode

The ultrasonic sensor continuously checks for obstacles.

- No obstacle → Move Forward
- Obstacle within 40 cm → Stop → Reverse → Turn Right → Continue

---

### Hand Movement

The SG90 servo rotates from 90° to 180° and back when the **H** command is received.

---

# 📂 Project Structure

```
VIVA-V1/
│
├── Arduino_Code/
│   └── VIVA_V1.ino
│
├── Images/
│
├── README.md
│
└── LICENSE
```

---

# 🔌 Pin Connections

| Arduino | Component |
|----------|-----------|
| D2 | HC-05 TX |
| D3 | HC-05 RX |
| D5 | ENA |
| D6 | ENB |
| D7 | SG90 Servo |
| D8 | IN1 |
| D9 | IN2 |
| D10 | IN3 |
| D11 | IN4 |
| D12 | Trig |
| D13 | Echo |

---

# 🔋 Power

Motors

- 3 × 18650 Battery → L298N

Arduino

- USB Cable (Development)
- Future: LM2596 Buck Converter

---

# Future Versions

## V2

- Voice Control
- DFPlayer Mini
- Robot Voice
- Battery Monitoring

## V3

- AI Assistant
- ESP32
- Wi-Fi Control
- Mobile App
- ChatGPT Integration

## V4

- Face Detection
- Object Tracking
- Gesture Recognition
- Autonomous Navigation

---

# 📸 Prototype

Current Version: **VIVA V1 Prototype**

Status:

✅ Moving

✅ Bluetooth Working

✅ Obstacle Avoidance

✅ Servo Hand

🔄 Voice Module (Next Version)

---

# 👨‍💻 Developer

**Vrishabh Deshmukh**

B.Tech CSE (AI)

Robotics Club

Project: **VIVA Robot**

Version: **1.0**

---

## ⭐ Future Goal

Build an AI-powered humanoid assistant capable of voice interaction, autonomous navigation, computer control, and smart automation.

**VIVA – Your Intelligent Robotics Companion**