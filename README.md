
## ROS Installation
Refer to https://github.com/catachiii/ROS_Course/blob/main/Other%20Materials/HowToSetupDeveloperPC_20-04.pdf

## Exercise 1
The task is to create a launch with Robocup14 world and control the robot using keyboard teleop for twist robots.
The final scene from my implementation looks like this:
![Robot moving in robocup14 field](imgs/Ex1_sol.png)

## Exercise 2
I implemented laser input to the robot and the visualization in rviz tool. I also incorporate parameters for the robot and subscribers.
![Robot laser scan](imgs/Ex2_sol.png)

## Exercise 3
I perceive the distance and position of nearest object (pillar). A simple P controller is implemented to navigate to the nearest object and 3D points are visualization in rviz tool.
![Robot navigating to pillar](imgs/Ex3_sol.png)

## Exercise 4
Here, I worked with ros bag, their ploting with rqt and the visualization of robot motion from a saved rosbag.
![Loading saved robot motion](imgs/Ex4_sol.png)