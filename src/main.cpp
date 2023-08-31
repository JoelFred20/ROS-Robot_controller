#include <iostream>
#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "my_little_node");

  ros::NodeHandle n;

  ros::Publisher armPub = n.advertise<std_msgs::Float64>("left_arm_controller/command", 1000);
  ros::Publisher rightArmPub = n.advertise<std_msgs::Float64>("right_arm_controller/command", 1000);
  ros::Publisher headPub = n.advertise<std_msgs::Float64>("head_controller/command", 1000);

  while (ros::ok()) {
    char in;
    std::cout << "Enter a command (a: move left hand, b: move right hand, c: move head, d: stop left hand, e: stop right hand, f: stop head): ";
    std::cin >> in;

    switch (in) {
      case 'a': {
        std_msgs::Float64 speedMsg;
        speedMsg.data = 1.0;
        armPub.publish(speedMsg);
        break;
      }
      case 'b': {
        std_msgs::Float64 speedMsg;
        speedMsg.data = 1.0;
        rightArmPub.publish(speedMsg);
        break;
      }
      case 'c': {
        std_msgs::Float64 speedMsg;
        speedMsg.data = 1.0;
        headPub.publish(speedMsg);
        break;
      }
      case 'd': {
        std_msgs::Float64 speedMsg;
        speedMsg.data = 0.0;
        armPub.publish(speedMsg);
        break;
      }
      case 'e': {
        std_msgs::Float64 speedMsg;
        speedMsg.data = 0.0;
        rightArmPub.publish(speedMsg);
        break;
      }
      case 'f': {
        std_msgs::Float64 speedMsg;
        speedMsg.data = 0.0;
        headPub.publish(speedMsg);
        break;
      }
      default:
        std::cout << "Invalid command.\n";
    }
  }

  return 0;
}

