# Lowell Makes Robot!


## The Collaborative Roboic Platform

### Goal ###

To build a software and hardware platform to shocase the technological and aesthetic 
creativity of the members of Lowell Makes.  All code and designs should be open sorce 
and easily extensible.  Eventually we hope this robot will be an embassidor for LM 
possibly greeting people at our door and giving tours.

### High Level Description ###

The LM_Bot is based on ROS in and effort to make the software modular enough for people 
to develop independantly and to allow the hardware to evolve over time.  Adhering to the 
ROS module design should insure code compatibility.

### Current Status ###

Currently the robot is a very basic hardware platform designed around a few servo motors 
and some Ultrasonic range finders driven by an Arduino Due and a Roboclaw motor driver (2x15A).
 The platform currently drives autonomously and can perform ruudimentary collision avoidance (poorly).

### Software TODO ###
  * Install and run ROS on a a Raspberry Pi to act as the ROS Master
  * Import ROS Node library to Arduino Due and publish new Topics
  * Voice Recognition
  * OpenCV face rcognition
  * Voice synthasis (or John Cleese voice samples)
  * Xbox Connect style sensor support

### Hardware TODO ###
  * Scanning type sensor maybe ultrasonic and IR
  * Xbox connect style sensor

### Aestetic Design TODO: ###
  * Everything 
