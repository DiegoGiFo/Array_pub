#include <ros.h>
#include <std_msgs/Float32MultiArray.h>

ros::NodeHandle nh;

std_msgs::Float32MultiArray msg_arr;
ros::Publisher msg_arr_pub("/array_msg", &msg_arr);

char dim0_label[] = "message_array";
void setup()
{
  nh.initNode();
  msg_arr.layout.dim = (std_msgs::MultiArrayDimension *)
  malloc(sizeof(std_msgs::MultiArrayDimension)*2);
  msg_arr.data_length = 8;
  msg_arr.layout.dim[0].label = dim0_label;
  msg_arr.layout.dim[0].size = 8;
  msg_arr.layout.dim[0].stride = 1*8;
  msg_arr.layout.data_offset = 0;
  msg_arr.data = (float *)malloc(sizeof(float)*8);
  nh.advertise(msg_arr_pub);
}

void loop()
{
  for(int i = 0; i < 8; i++){
    msg_arr.data[i] = i ;
  }

  if((millis()%50) == 1)
  {
    msg_arr_pub.publish( &msg_arr );
  }

  nh.spinOnce();
}
