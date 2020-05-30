# Line Following Robot - Arduino Project 

## Introduction

I built an Arduino robot that uses infrared sensors and an ultrasonic sensor to follow a solid black line. The robot was created for the final summative project in my Grade 11 Computer Engineering Class, where we had to create an Arduino system that would accomplish a task using three different sensors. The Arduino robot would constantly receive on inputs from both the infrared and ultrasonic sensors, creating a combination that allowed the robot to manuever efficiently and avoid any obstacles. 

## Equipment 
* 1 Arduino Uno
* 2 DC Motors
* 3 QTI Infrared Sensors
* 1 Ultrasonic Sensor
* 1 L293d Motor Driver Chip

The QTI Infrared Sensor would use the reflectance value of the surface beneath the robot to determine the robot's position relative to the line. Since the line was solid black, the robot was always looking for the lowest values. 


## Circuit Diagram 

Below is the diagram representing the circuit I built for the three sensors. The circuit is powered by two 9-volt batteries connected in series. One 9-volt battery provided enough voltage but failed to produce the current needed to power the circuit, so two batteries were need. 

![Circuit Diagram](https://user-images.githubusercontent.com/43073112/83340370-1f7fe380-a2a5-11ea-8dec-b866fe69d56b.png)
