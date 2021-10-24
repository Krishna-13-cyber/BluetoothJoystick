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
* [Theory and Approach](#theory-and-approach)
* [Results and Demo](#results-and-demo)
* [Code Flowchart](#code-flowchart)
* [Future Work](#future-work)
* [Troubleshooting](#troubleshooting)
* [Contributors](#contributors)
* [Acknowledgements and Resources](#acknowledgements-and-resources)
* [License](#license)

<!-- ABOUT THE PROJECT -->
## About The Project
### Aim 
This aim of the project is to make a Bluetooth Joystick using ESP32 which establishes Bluetooth Low Energy (BLE) Connection with the host device to provide controls by providing inputs. The ESP32 is capable of getting a unique signal for each key press. Accordingly it will transmit the signal information over bluetooth to the host device.

### This image illustrates how our hardware looks like at the current stage
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
## Theory and Approach

### Theory:
The main motto of the project is to make the setup wireless.This can be achieved by using the ability of ESP-32 to have BLE within it with which it can be connected over bluetooth to the Computer System and returns the value according to the movement of the joystick.The esp-idf(Espressif's official IoT Development Framework)which was the main resource for our project, has all the information about the pinning system and channels present have to be read and their use have to studied from here.The framework tells us the about the channels which can be used,the usage of pins for different functions(ADC,DAC,GRD) and the channels which are more efficient in bluetooth connectivity are to be used,which is ChannelNo.1 in our case.There is a dual-axis high quality JoyStick Module . It can be used to sense movements in 2 directions(axes). It also has an inbuilt switch which can be activated by pressing the stick.This is the joystick module which we are using in the project.
The values received from the ADC are the voltage values(raw values),as voltage values which are analog are first converted to binary and then to digital format,So it is obtained in the raw form.The ADC values are ranging from 0-4095 as it works on 12 bit,that is it has 4096 values.The values returned depend on the movement of joystick and returns extreme values for the end point movement. The joystick, depending on the requirement of the game or task,its use can be changed and modified in 2-D constraint(joystick supports 2-D movements only).

### Approach:
The approach of the project is quite simple and understandable,first of all its aim is to make a bluetooth joystick.To take a look at the hardware stuff we need a joystick module(2-D module in this project),a ESP-32 microcontroller(according to the version kitc the pinout may vary),jumper wires for connection.For the bluetooth establishment we tried by connecting our esp32 as a mouse.To understand when the connection is established,how does the mouse behave as in the cursor.Next we start to connect the proper pinout connection of the ESP-32 to the Joystick.
So we want the system to know that if a joystick is moved the ESP-32 send or returns some value,for that we have the concept of ADC,this continuously sends the instant voltage values and when we move our joystick in different direction(2-D) it returns different values(extreme values are expected for end movements).Then finally we have integrate both together that is the bluetooth part and joystick returned values(which will tell the movement according to our code).According to the condition we want(the range of values), we can assign a function to send mouse the values(cursor speed,specifications).This will complete our project and can be modified to be used in games.This can be used in games where there is only a 2-D requirement as the joystick supports 2-D use only.
## Code Flowchart
![Flowchart](https://user-images.githubusercontent.com/84867886/138583223-d8353de8-228b-41de-8cc5-d18d5cb22d7a.png)

## Results and Demo
These are the output obtained in initial stage as shown in the link attached to the below mentioned video.
* [ADC Values](https://drive.google.com/file/d/1rm1N4SgXiCJK_13tnsdQ1i77aFfMDrW-/view?usp=sharing)
* [Movement of Cursor by Joystick](https://drive.google.com/file/d/1VwI7GT10AZU_PWkB9DNiD4OaYqe5EC_o/view?usp=sharing)

These are the Output of the Games played with help of Joystick Module.
![Mouse-Game](https://github.com/Krishna-13-cyber/BluetoothJoystick/blob/main/docs/MouseGame.gif)
![Mouse-Game2](https://github.com/Krishna-13-cyber/BluetoothJoystick/blob/main/docs/Game2.gif)
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

