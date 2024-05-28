# Lying Posture Tracking System

## Overview

This project aims to develop a lying posture tracking system using the IMU sensor unit embedded in an Arduino board. The system will gather sensor data mimicking various lying postures and implement an algorithm to control the on-board LED, indicating specific lying postures. Accurate estimation of lying postures during sleep is crucial for monitoring a patient's mobility, risk of developing hospital-acquired pressure injuries, and quality of sleep.

The system focuses on detecting three lying postures:
- **Supine** (lying on the back)
- **Prone** (lying on the stomach)
- **Side** (lying on either the right or left side)

The LED will indicate the detected posture as follows:
- **Supine:** LED blinks once
- **Prone:** LED blinks twice
- **Side:** LED blinks three times
- **None of the above postures:** LED remains off

The sensor unit is assumed to be attached to the chest of the user.

## Project Phases

### Phase 1: Reading IMU Sensor Data
Develop code to read the IMU sensor data from the Arduino board and store the signal readings on your computer.

### Phase 2: Data Collection
Collect data for different scenarios by holding the board in orientations that represent various in-bed postures. Ensure to gather enough signal data for each posture.

### Phase 3: Data Visualization and Analysis
Plot the collected data and visually observe the differences among signals for different postures. Develop an ad-hoc algorithm to infer the posture based on these observations.

### Phase 4: Algorithm Implementation
Implement the developed algorithm on the Arduino board to read the IMU sensor data in real-time and control the LED output depending on the detected posture.

## System Requirements

- Arduino board with embedded IMU sensor unit
- Computer with Arduino IDE installed
- USB cable to connect Arduino board to the computer

## Setup

1. **Open the Arduino IDE:**
   - Install the necessary libraries for the IMU sensor: Arduino_LSM9DS1.h
2. **Upload Code to Arduino:**
   - Open the provided `.ino` file in the Arduino IDE.
   - Upload the code to the Arduino board.

## Running the System

1. **Data Collection:**
   - Run the `readData.ino` sketch to read IMU sensor.
   - Run the `readData.py` to collect data and store in csv file.
   - Collect data by holding the board in different orientations representing the supine, prone, and side postures.

2. **Data Analysis:**
   - Use a plotting tool (e.g., Python with Matplotlib) to visualize the collected data.
   - Observe and identify patterns in the data corresponding to each posture.

3. **Algorithm Development:**
   - Develop an algorithm based on the observed patterns to classify the postures.

4. **Posture Detection and LED Control:**
   - Implement the algorithm in the `postureDetection.ino` sketch.
   - Upload the code to the Arduino board.
   - The system will continuously update the LED output based on the detected posture.

## Algorithm Details

- The algorithm processes IMU sensor readings to determine the orientation of the board.
- It classifies the orientation into one of the three postures (supine, prone, side) based on predefined thresholds and patterns.
- The LED is controlled to blink according to the detected posture.

## Results

Below are the results of the lying posture tracking system, showing the detected postures with corresponding images.

| Posture     | Image                                                                                                                               | 
|-------------|-------------------------------------------------------------------------------------------------------------------------------------|
| Supine      | ![Supine](https://github.com/dheerajkallakuri/Lying-Posture-Tracking-System/assets/23552796/23596569-b6b2-4218-8567-a5efba649232)   | 
| Prone       | ![Prone](https://github.com/dheerajkallakuri/Lying-Posture-Tracking-System/assets/23552796/d621ced7-0c4b-4078-ba92-16b13caa19c2)    |
| Left Side   | ![leftside](https://github.com/dheerajkallakuri/Lying-Posture-Tracking-System/assets/23552796/9f8787a1-b27a-449a-89ab-b7a98961cc55) |
| Right Side  | ![Right](https://github.com/dheerajkallakuri/Lying-Posture-Tracking-System/assets/23552796/31dc496b-eee9-4486-b079-e02df8e22d33)    |

## Video Demonstration

For a visual demonstration of this project, please refer to the video linked below:

[Project Video Demonstration](https://youtu.be/mLK39EPm_P0)

[![Project Video Demonstration](https://img.youtube.com/vi/mLK39EPm_P0/0.jpg)](https://www.youtube.com/watch?v=mLK39EPm_P0)
