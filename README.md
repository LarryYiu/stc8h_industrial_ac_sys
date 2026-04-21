# STC8H Industrial Air Conditioning System Prototype
This document provides an overview of the STC8H project of making a production level industrial air conditioning system prototype.

## Table of Contents
- [1 Introduction](#1-introduction)
  - [1.0 Overview](#10-overview)
  - [1.1 Project Objective](#11-project-objective)
  - [1.2 Project Structure](#12-project-structure)
  - [1.3 Key Modules](#13-key-modules)

# 1 Introduction

## 1.0 Project Objective
The main purpose of this project is to develop a prototype of an industrial air conditioning system using the STC8H microcontroller. The system will include features such as temperature control, user interface, and communication capabilities, demonstrating the practical application of embedded systems in industrial settings.

## 1.1 Project Structure
The project is organized into several directories, each serving a specific purpose:

- `APP`: Contains application-level code that utilizes the modules for their specific functionalities in the industrial air conditioning system.

- `DRIVER`: Contains the driver code for the hardware modules.

- `LIB`: Contains library code that may be shared across different modules of the project, such as wrappers for GPIOs.

- `STC8H_LIB`: Contains the library code specific to the STC8H microcontroller PROVIDED by the manufacturer, including register definitions and low-level hardware interactions, abstracting hardware details.

## 1.2 Key Modules
- `TouchKey`: This module handles the touch key input for the user interface of the air conditioning system. It includes functions for configuring the touch key hardware, scanning for key presses, and retrieving key status and data.

- `Temperature&Humidity Control (I2C)`: This module manages the temperature and humidity control logic, including reading temperature and humidity sensors, controlling the cooling/heating elements, and implementing control algorithms.

- `User Interface (LCD)`: This module manages the user interface, including displaying information on an LCD screen and handling user input through the touch keys.

- `Data storage (EEPROM)`: This module handles data storage using EEPROM, allowing the system to preserve settings and other important data. CRC is implemented for data integrity in EEPROM storage.

- `Communication (UART/Modbus RTU)`: This module manages communication with external devices using UART and Modbus RTU protocol, enabling features such as remote monitoring and control. Modbus RTU uses RS485 for long-distance communication, UART(TTL) for debugging and short-distance communication. CRC is implemented for data integrity in Modbus RTU communication.
