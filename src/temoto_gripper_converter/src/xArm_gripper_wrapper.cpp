#include "ros/ros.h"
#include <temoto_robot_manager/GripperControl.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/GripperCommandAction.h>
#include <kinova_msgs/SetFingersPositionAction.h>


std::string kinova_robotType = "m1n6s300_";


bool gripperCb (temoto_robot_manager::GripperControl::Request& req, 
		temoto_robot_manager::GripperControl::Response& res)
{
	ROS_INFO("Kinova gripper request: x=%ld", (long int)req.position);
	req.position;
	return true;
}


int main(int argc, char **argv)
{
ros::init(argc, argv, "kinova_gripper_wrapper");
ros::NodeHandle nh;

ros::ServiceServer gripper_server = nh.advertiseService("gripper_control", gripperCb);

ros::spin();

return 0;
}












