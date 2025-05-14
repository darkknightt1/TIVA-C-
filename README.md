# 🔦 Li-Fi Based Security Monitoring System

This project implements a **Li-Fi (Light Fidelity)** communication system using a **TivaC TM4C123** microcontroller to transmit sensor data via **laser light** to an **Arduino** display interface. The system communicates through **UART over light** and integrates multiple sensors for real-time environment monitoring.

---

## 📌 Features

- **Multi-Sensor Security Monitoring:**
  - Ultrasonic Sensor (Intrusion Detection)
  - Flame Sensor (Fire Detection)
  - Magnetic Sensor (Door Status)

- **Li-Fi Communication:**
  - Transmit alerts using laser light via UART protocol
  - Arduino receives data optically for display

- **Dual Communication:**
  - Bluetooth module for wireless debugging/alerts
  - Li-Fi for secure line-of-sight transmission

- **Control Inputs:**
  - Start/Stop push buttons
  - Mute functionality to disable buzzer alerts

---

## 📦 Hardware Setup

| Component         | Description                            |
|------------------|----------------------------------------|
| TivaC TM4C123     | Main microcontroller                   |
| Arduino           | Receiver for Li-Fi signals             |
| Laser Diode       | Transmitter using UART-encoded signals |
| Photodiode        | Light receiver connected to Arduino    |
| HC-05 Bluetooth   | Sends alerts to a paired device        |
| Ultrasonic Sensor | Detects proximity for intrusion        |
| Flame Sensor      | Detects fire via analog input          |
| Magnetic Sensor   | Detects door open/close                |
| LEDs/Buzzer       | Visual and audio alert output          |
| Push Buttons      | Start/Stop and Mute buttons            |

---

## 🔁 Communication Protocol

| Event         | Li-Fi Code | Bluetooth Message     |
|---------------|------------|------------------------|
| Intrusion     | `1` or `A` (muted) | `Intrusion` / `IntrusionMute` |
| Fire          | `3` or `a` (muted) | `FIRE` / `FIREMute`           |
| Door Open     | `0` or `9` (muted) | `DoorOpen` / `DoorOpenMute`   |
| No Detection  | `<`        | `NOTHING`             |

---


## 🧪 Future Improvements

- Implement full duplex (two-way) Li-Fi communication
- Add encrypted message transmission
- Expand sensor suite (e.g., smoke, gas sensors)
- Build an IoT-connected dashboard for real-time monitoring

---


