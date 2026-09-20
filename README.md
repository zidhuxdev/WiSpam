# WiSpam

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-C%2B%2B-blue?style=for-the-badge&logo=arduino" alt="ESP32 C++">
  <img src="https://img.shields.io/badge/Platform-Arduino-00979D?style=for-the-badge&logo=arduino" alt="Arduino">
  <img src="https://img.shields.io/github/stars/zidhuxdev/WiSpam?style=for-the-badge&logo=github" alt="GitHub stars">
  <img src="https://img.shields.io/github/forks/zidhuxdev/WiSpam?style=for-the-badge&logo=github" alt="GitHub forks">
</p>

<p align="center">
  <b>ESP32 Wi-Fi beacon research project</b><br>
  Broadcasts test beacon frames with configurable example SSIDs for authorized lab experiments.
</p>

<p align="center">
  <a href="https://github.com/zidhuxdev/WiSpam"><img src="https://img.shields.io/badge/View%20repository-GitHub-181717?style=flat-square&logo=github" alt="View repository"></a>
  <a href="https://github.com/zidhuxdev"><img src="https://img.shields.io/badge/Author-zidhuxdev-111827?style=flat-square&logo=github" alt="Author"></a>
</p>

> **Important:** This project is for education, debugging, and authorized wireless-security testing only. Use it exclusively on hardware and in environments where you have explicit permission. Do not impersonate real networks, disrupt nearby users, or deploy it in public places.

## Features

- Runs on an ESP32 using the Arduino framework.
- Sends IEEE 802.11 beacon frames for controlled lab testing.
- Includes a small example list of phone-style SSIDs.
- Randomizes the test channel and beacon address fields.
- Prints startup information and the device MAC address over Serial.

## Requirements

- ESP32 development board.
- USB data cable.
- Arduino IDE or PlatformIO.
- ESP32 board support installed.
- A permitted test environment, preferably an isolated lab.

## Quick start with Arduino IDE

1. Install the **ESP32 by Espressif Systems** board package in Arduino IDE.
2. Open [`WiSpam.ino`](WiSpam.ino).
3. Select your ESP32 board and the correct USB port.
4. Compile the sketch.
5. Upload it to the board.
6. Open Serial Monitor at **115200 baud**.

The sketch starts after upload and prints basic device information to the Serial Monitor.

## Customizing the test names

Edit the `ssidList` array in [`WiSpam.ino`](WiSpam.ino) and keep the declared count in sync:

```cpp
const int numSSIDs = 3;

const char* ssidList[numSSIDs] = {
  "Lab-Test-01",
  "Lab-Test-02",
  "ESP32-Demo"
};
```

Use clearly fictional names in testing. Never copy the SSID of a nearby real network without explicit authorization.

## Project layout

```text
WiSpam/
├── WiSpam.ino   # ESP32 Arduino sketch
├── README.md    # Project documentation
```

## Troubleshooting

- **Board not detected:** Try another USB data cable, port, or driver.
- **Upload fails:** Confirm the selected board and port; hold the ESP32 boot button if your board requires it.
- **No Serial output:** Select **115200 baud** and press the reset button once.
- **Compilation errors:** Update the ESP32 board package and confirm the sketch is being compiled for an ESP32 board.

## Responsible use

This software can affect how nearby Wi-Fi scanners display networks. Keep experiments controlled, use low-risk lab conditions, and stop immediately if the test affects equipment or users outside your authorization.

## Author

Created by **[zidhuxd](https://github.com/zidhuxdev)**.

- GitHub: [github.com/zidhuxdev](https://github.com/zidhuxdev)
- Repository: [github.com/zidhuxdev/WiSpam](https://github.com/zidhuxdev/WiSpam)

## License

No license has been specified for this repository yet. Until a license is added, all rights are reserved by the author. Do not redistribute or reuse the code outside the repository's permitted terms.
