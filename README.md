# 🤖 Autonomous Rescue Line Robot – Electronic & Firmware
This repository contains the electronic design and embedded C firmware for our autonomous rescue robot built on ATmega128.

## 🏆  Champion of RoboCupJunior 2019 Rescue Line (Open League) 
<p align="center">
  <img src="https://github.com/user-attachments/assets/e92f5f4c-3cf7-4475-9e62-f1a350d7c2ae" alt="Kavosh Robot Poster" width="500"/>
</p>

This repository showcases the **electronic design**, **PCB layouts**, and **embedded code** that powered our award-winning robot, *Kavosh*, which secured **first place** in the **RoboCupJunior Rescue Line (Open League)** in 2019.

The robot was built to autonomously:
- Navigate rescue line tiles (curves, intersections, ramps)
- Detect victims using thermal/color sensors
- Drop rescue kits
- Respond to obstacles in real time

All control logic runs on an **ATmega128 microcontroller**, supported by custom-designed PCBs and modular firmware written in C using **CodeVisionAVR**.
## 🧩 Electronics Design

The robot consists of several custom-designed PCBs:

- **Main Board:**  
  Hosts the ATmega128 MCU, power circuitry, and connectors for peripherals.

- **Sensor Board:**  
  15x IR line sensors, 2x color sensors (APDS-9960), 2x encoders. Communicates with the main board via an 18-wire ribbon cable.

- **Microcontroller Daughterboard:**  
  Small board to mount and replace the ATmega128 easily in case of damage.

- **LCD + Button Interface:**  
  4×20 LCD with 7 buttons for configuration, feedback, and debugging.



> 🧱 Below are the Sendor and Main board used in this project:
![image](https://github.com/user-attachments/assets/04ff485e-752f-4453-80db-e5cb61f25f71)






### 🔍 Key Sensors and Modules
- **Color Detection:** APDS-9960
- **Distance Measurement:** SRF-05 ultrasonic & VL53L0X laser
- **Compass / Tilt Detection:** CMPS12
- **Motor Control:** PWM control of left/right wheels, arm, basket, etc.
## 💻 Firmware & Control Logic

The robot is programmed in **C**, compiled via **CodeVisionAVR**, and optionally simulated with **Proteus**.

### 🔧 Code Architecture

- **Line Following Algorithm:**  
  Based on IR sensor feedback and PID-style logic, handles intersections, curves, and speed control.

- **Obstacle Avoidance:**  
  Ultrasonic sensor (SRF-05) measures front distance and redirects the robot accordingly.

- **Victim Detection:**  
  Thermal and color sensor inputs processed via `vic()` and `contact()` functions to identify red/green areas.

- **Modular Functions:**
  - `Go(left, right)`: Direct motor control
  - `ev_zone()`: Master routine for rescue area
  - `vic()`, `contact()`: Victim and environment detection

### 🧪 Development Flow

Firmware development was split into:
1. **Line Following Mode**
2. **Victim Rescue Mode**

Each mode was modularized for testability and debugging using UART and LCD interfaces.
## 📁 Repository Structure
<pre> <code> robocup-kavosh-electronics/
├── code/
│ └── kavosh_2018_APC.c # Full embedded firmware in C
| └── KavoshLineLibrary.h # Sensors and motors  config in C
├── pcb/
│ ├── main_board.sch # Main board schematic
│ ├── sensor_board.sch # Sensor module schematic
│ └── lcd_board.sch # LCD + button board </code> </pre>
## 🏅 Achievements

- 🥇 1st Place – **RoboCupJunior 2019**, Rescue Line (Open League)
- 🥇 1st Place – **RobocupAsiaPacific 2018**, Rescue Line (Open League)
- 👨‍💻 Custom firmware, sensors & PCB design
- 📊 Efficient real-time performance with modular embedded design

<p align="center">
  <img src="https://github.com/user-attachments/assets/d2defcc8-550b-4082-bba5-fa1b4a43be51" alt="KavoshTeam" width="500"/>
</p>

## 🛠️ Tools Used

- 🧠 Microcontroller: ATmega128
- 💻 IDE: CodeVisionAVR
- 🧪 Simulation: Proteus
- 📐 PCB Design: Altium Designer
- 🧾 Language: C

