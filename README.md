# Pico SDK Signal Generation Project

This project demonstrates how to use the Raspberry Pi Pico SDK to generate a signal of 2 Hz with added noise of 100 Hz. The project uses the Pico SDK, which is the official software development kit for the Raspberry Pi Pico.

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Installation](#installation)
- [License](#license)

## Introduction

This project showcases a simple [Butterworth filter](https://en.wikipedia.org/wiki/Butterworth_filter) in discrete time. download the code that emulates a signal generator with noise from [here](https://github.com/your-username/pico-master.git). 

## Requirements

To build and run this project, you'll need:

- [Raspberry Pi Pico](https://www.raspberrypi.org/products/raspberry-pi-pico/)
- [Pico SDK](https://github.com/raspberrypi/pico-sdk)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/BiradarSiddhant02/pico-slave.git
   cd pico
2. Build the binaries
    ```bash
    mkdir build
    cd build
    export PICO_SDK_PATH=../../pico-sdk
    cmake ..
    make -j4

3. Run the master code on a seperate pico. connect it to the slave pico through default SPI connection and power and ground connections. Power is distributed to both the boards. 

4. Connect the USB to the master pico and run serial-plotter in the arduino IDE to plot the noisy signal.

5. Connect the USB to the slave pico and run serial-plotter in the adruino IDE to plot the noisy signal and the noisy signal.

6. Before running serial-plotter for the slave pico, open serial monitor and check if the output is within -2 and +2. If not, reconnect the USB untill it is resolved.

## License

This project is licensed under the [MIT License](LICENSE) - see the [LICENSE](LICENSE) file for details.

# pico-master
