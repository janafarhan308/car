# 🚗 Arduino Bluetooth Controlled & Obstacle Avoidance Car

## 📌 Project Overview

This project is a smart robotic car developed using **Arduino Uno**, combining Bluetooth remote control with autonomous obstacle avoidance.

The car operates in two modes: **Manual Mode**, where users control its movement through Bluetooth commands, and **Autonomous Mode**, where it detects obstacles and automatically selects a suitable direction using an ultrasonic sensor and a servo motor.

The project demonstrates practical applications of embedded systems, robotics, sensor integration, and automation.

## ✨ Key Features

- **Bluetooth Control:** Control the car wirelessly using a smartphone.
- **Dual Operating Modes:** Switch between manual and autonomous driving.
- **Obstacle Detection:** Measure distances using an HC-SR04 ultrasonic sensor.
- **Automatic Obstacle Avoidance:** Detect obstacles and compare available space on both sides.
- **Servo-Based Scanning:** Rotate the ultrasonic sensor to examine different directions.
- **Motor Control:** Move forward, backward, left, right, or stop.

## 🛠️ Hardware Components

- Arduino Uno
- Bluetooth Module
- 2 DC Motors
- Motor Driver Circuit
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- Robot Car Chassis
- Battery / Power Supply
- Jumper Wires

## 💻 Technologies Used

- Arduino IDE
- Embedded C/C++
- Bluetooth Serial Communication
- Ultrasonic Distance Measurement
- Servo Motor Control

## ⚙️ How It Works

### 1. Manual Mode

The car receives commands through Bluetooth serial communication.

| Command | Action |
|---|---|
| `F` | Move Forward |
| `B` | Move Backward |
| `L` | Turn Left |
| `R` | Turn Right |
| `H` | Activate Manual Mode |
| `J` | Activate Autonomous Mode |

In manual mode, unrecognized commands stop the motors.

### 2. Autonomous Mode

When autonomous mode is activated:

1. The ultrasonic sensor measures the distance to objects ahead.
2. If the measured distance is greater than 20 cm, the car moves forward.
3. If an obstacle is detected within 20 cm, the car stops.
4. The servo motor rotates the ultrasonic sensor to scan both sides.
5. The Arduino compares the measured distances.
6. The car turns toward the direction with more available space.
7. The process repeats to continue navigation.

## 🔌 Pin Configuration

| Component | Arduino Pin |
|---|---|
| Motor 1 – Input 1 | D4 |
| Motor 1 – Input 2 | D5 |
| Motor 2 – Input 1 | D6 |
| Motor 2 – Input 2 | D7 |
| Servo Motor | D8 |
| Ultrasonic Echo | D9 |
| Ultrasonic Trigger | D10 |

Bluetooth commands are received through Arduino serial communication at **9600 baud**.

## 📂 Project Structure

`car.ino` – Main Arduino source code containing Bluetooth command handling, motor control, distance measurement, and obstacle avoidance logic.

## 🎯 Learning Outcomes

Through this project, I gained practical experience in:

- Arduino programming and embedded systems.
- Integrating sensors and actuators.
- Implementing Bluetooth-based remote control.
- Designing autonomous decision-making logic.
- Controlling DC motors and servo motors.
- Developing and troubleshooting a robotics project.

## 🚀 Future Improvements

- Add PWM-based speed control.
- Improve obstacle detection and navigation accuracy.
- Add additional sensors for safer movement.
- Develop a custom mobile application for controlling the car.
- Improve handling of invalid ultrasonic sensor readings.

## 👩‍💻 Project Category

**Embedded Systems | Arduino | Robotics | Automation**
