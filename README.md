# BluetoothJoystick
Bluetooth Joystick : A wireless joystick with ESP-32 microcontroller and Dual Axis Joystick Module using the Bluetooth connectivity.

<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Tech Stack](#tech-stack)
  * [File Structure](#file-structure)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
* [Usage](#usage)
* [Connections](#connections)
* [Results and Demo](#results-and-demo)
* [Future Work](#future-work)
* [Troubleshooting](#troubleshooting)
* [Contributors](#contributors)
* [Acknowledgements and Resources](#acknowledgements-and-resources)
* [License](#license)

<!-- ABOUT THE PROJECT -->
## About The Project
The Aim of the Project is to make a Bluetooth Joystick using ESP32 which establishes Bluetooth Low Energy (BLE) Connection with the host device to provide controls by providing inputs. 

This image illustrates how our hardware looks like at the current stage
![Hardware](https://user-images.githubusercontent.com/84867886/137713259-8dfb6e91-b3af-45e9-91c0-fc0ee07c7167.jpeg)
 

### Tech Stack
The following technologies have been used for the making of this project.
* [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
* [FreeRTOS](https://sravjti.in/embedded-systems-study-group/week6/week6.html#what-is-an-rtos)
* [Bluetooth Low Energy(BLE)](https://developer.android.com/guide/topics/connectivity/bluetooth/ble-overview) 

### File Structure
    .
    ├── main                    # Contains files used for building and flashing
    ├── docs                    # Documentation files (alternatively `doc`)
    │   ├── report.pdf          # Project report
    │   └── results             # Folder containing screenshots, gifs, videos of results
    ├── src                     # Source files (alternatively `lib` or `app`)
    ├── ...
    ├── test                    # Test files (alternatively `spec` or `tests`)
    │   ├── benchmarks          # Load and stress tests
    │   ├── integration         # End-to-end, integration tests (alternatively `e2e`)
    │   └── unit                # Unit tests
    ├── ...
    ├── tools                   # Tools and utilities
    ├── LICENSE
    ├── README.md 
    ├── Setup.md                # If Installation instructions are lengthy
    
<!-- GETTING STARTED -->
## Getting Started
### Prerequisites
To flash this project install ESP-IDF: https://github.com/espressif/esp-idf
### Cloning the repository
Clone the project by typing the following command in your Terminal/CommandPrompt
```
git clone https://github.com/Krishna-13-cyber/BluetoothJoystick.git

cd BluetoothJoystick
```

## Hardware
### Connections
Connect the ESP32 to your desktop via USB to flash the code in it. And connect the Joystick to ESP32 as per the table given below.
![Connection Illustration](https://user-images.githubusercontent.com/84867886/137712945-33cc0423-3b61-4909-b2e1-0d28a778a47f.png)
JoyStick Pin | ESP32 Pin
--------- | -----------
5V | 3V3
GND | GND
VRx | GPIO39
VRy | GPIO34
SW | GPIO25

You are all set to flash the code after completing the connections.
## Usage
After following the above steps , use the following commands to:
Build
```
idf.py build
```
Flash
```
idf.py -p (PORT) flash monitor
```
Configuration

```
idf.py menuconfig
```
## Results and Demo
The output obtained is shown in the link attached to the below mentioned video.
[ADC Values](https://drive.google.com/file/d/1rm1N4SgXiCJK_13tnsdQ1i77aFfMDrW-/view?usp=sharing)
[Movement of Cursor by Joystick](https://drive.google.com/file/d/1VwI7GT10AZU_PWkB9DNiD4OaYqe5EC_o/view?usp=sharing)
<!-- FUTURE WORK -->
## Future Work
* The following developments are yet to be achieved
- [x] Establishing BlueTooth Connection
- [x] Obtaining ADC Values
- [ ] Moving the Cursor 
- [ ] Controlling a Game

## Troubleshooting
 While Configuring for the first time if you face any problem, check the ESP-IDF's Menu Configuration
 
```
idf.py menuconfig
```
Then go to components/bluetooth and enable bluetooth
Press ctrl+s to save the configuration
then
```
idf.py build
```
## Contributors
* [Krishna Narayanan](https://github.com/Krishna-13-cyber)
* [Om Sheladia](https://github.com/omsheladia)

## Acknowledgements and Resources
* [SRA-VJTI for providing this wonderful opportunity](https://sravjti.in/) Eklavya 2021 
* Special thanks to [Gautam Agrawal](https://github.com/gautam-dev-maker)
* Special thanks to [Dhairya Shah](https://github.com/dhairyashah1) 
* https://github.com/nkolban/esp32-snippets
* [Krishna's Notes](https://docs.google.com/document/d/1IP-aztx2PFOdQ0YAVJ_k0vlUyVbuh3PO7OZ1GM7nCuU/edit?usp=sharing)
* [Om's Notes](https://docs.google.com/document/d/1GOzxKsOPQXyTHjrb4r8Ifgxr5I2fEamjWZOJTkD3TnQ/edit?usp=sharing)

## License
The [License](https://github.com/Krishna-13-cyber/BluetoothJoystick/blob/main/LICENSE) Used for this Project.

