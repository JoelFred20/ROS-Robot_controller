# ROS-Robot_controller

Cloning the repo

      mkdir -p catkin_ws/src
      cd catkin_ws/src
      git clone https://github.com/JoelFred20/ROS-Robot_controller.git

Updating Dependencies

       cd ~/catkin_ws/
       rosdep update
       rosdep install --from-paths src --ignore-src -r -y --rosdistro noetic

Installing Controllers For Robot

       sudo apt-get update
       sudo apt-get install ros-noetic-ros-controllers

Building tutorial package

       cd ~/catkin_ws
       catkin build tutorial
       source devel/setup.bash

Launch the robot

       roslaunch tutorial gazebo.launch

To run the project

       cd ~/catkin_ws
       source devel/setup.bash
       rosrun tutorial my_publisher
