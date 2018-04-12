
#include <ros.h>
#include <std_msgs/Float32MultiArray.h>

std_msgs::Float32MultiArray obstacles_and_holes_msg;
ros::Publisher pub_obstacles_and_holes("obstacles_and_holes", &obstacles_and_holes_msg);
ros::NodeHandle nh;

void setup()
{
  nh.initNode();                                               // ROS node publisher initialization
  obstacles_and_holes_msg.data_length = 3;                    // length of the message (8 IR detectors and 6 sonars)
  nh.advertise(pub_obstacles_and_holes);
}

void loop()
{
  if((millis()%50) == 1){
    for(int i = 0; i<4; ++i) {
      obstacles_and_holes_msg.data[i] = i+1;
    }
    pub_obstacles_and_holes.publish( &obstacles_and_holes_msg );
  }

  nh.spinOnce();
}
