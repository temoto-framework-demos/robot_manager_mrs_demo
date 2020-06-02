
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *
 *  The basis of this file has been automatically generated
 *  by the TeMoto action package generator. Modify this file
 *  as you wish but please note:
 *
 *    WE HIGHLIY RECOMMEND TO REFER TO THE TeMoto ACTION
 *    IMPLEMENTATION TUTORIAL IF YOU ARE UNFAMILIAR WITH
 *    THE PROCESS OF CREATING CUSTOM TeMoto ACTION PACKAGES
 *    
 *  because there are plenty of components that should not be
 *  modified or which do not make sence at the first glance.
 *
 *  See TeMoto documentation & tutorials at: 
 *    https://temoto-telerobotics.github.io
 *
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

/* REQUIRED BY TEMOTO */
#include <class_loader/class_loader.hpp>
#include "ta_demo_1/temoto_action.h"
#include "ta_demo_1/macros.h"
#include "temoto_robot_manager/robot_manager_interface.h"

/* 
 * ACTION IMPLEMENTATION of TaDemo1 
 */
class TaDemo1 : public TemotoAction
{
public:

robot_manager::RobotManagerInterface<TaDemo1> rmi_;
const std::string robot_name_1 = "xarm7_robot";
const std::string robot_name_2 = "ur5_robot";
const std::string robot_name_3 = "clearbot";

// Constructor. REQUIRED BY TEMOTO
TaDemo1()
{
  std::cout << __func__ << " constructed\n";
}

// REQUIRED BY TEMOTO
void executeTemotoAction()
{
  // Input parameters
  double input_1 = GET_PARAMETER("input_1", double);

  rmi_.initialize(this);

  // xarm7_robot
  TEMOTO_INFO_STREAM("loading " << robot_name_1);
  rmi_.loadRobot(robot_name_1);
  TEMOTO_INFO_STREAM(robot_name_1 << " initialized");

  // ur5_robot  
  TEMOTO_INFO_STREAM("loading " << robot_name_2);
  rmi_.loadRobot(robot_name_2);
  TEMOTO_INFO_STREAM(robot_name_2 << " initialized");

  // clearbot
  TEMOTO_INFO_STREAM("loading " << robot_name_3);
  rmi_.loadRobot(robot_name_3);
  TEMOTO_INFO_STREAM(robot_name_3 << " initialized");

  
  geometry_msgs::PoseStamped target_pose1;  
  rmi_.planManipulation(robot_name_1,"xarm7","test_pose");
  rmi_.executePlan(robot_name_1);
  target_pose1.pose = rmi_.getEndEffPose(robot_name_1);

  rmi_.controlGripperPosition(robot_name_1,100);   //open

  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.51192;
  rmi_.planManipulation(robot_name_1,"xarm7",target_pose1);  
  rmi_.executePlan(robot_name_1);

  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.18;
  rmi_.planManipulation(robot_name_1,"xarm7",target_pose1);  
  rmi_.executePlan(robot_name_1);

  rmi_.controlGripperPosition(robot_name_1,70);   //partially close

  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.52;
  rmi_.planManipulation(robot_name_1,"xarm7",target_pose1);  
  rmi_.executePlan(robot_name_1);

  rmi_.planManipulation(robot_name_1,"xarm7","test_pose");  
  rmi_.executePlan(robot_name_1);
  
  geometry_msgs::PoseStamped target_poseNav;
  target_poseNav.pose.position.x = 0;
  target_poseNav.pose.position.y = -0.8;
  target_poseNav.pose.orientation.z = 0;
  target_poseNav.pose.orientation.w = 1;
  rmi_.navigationGoal(robot_name_3,"map",target_poseNav);

  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.51192;
  rmi_.planManipulation(robot_name_1,"xarm7",target_pose1);  
  rmi_.executePlan(robot_name_1);

  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.33;
  rmi_.planManipulation(robot_name_1,"xarm7",target_pose1);  
  rmi_.executePlan(robot_name_1);

  rmi_.controlGripperPosition(robot_name_1,100);   //open

  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.52;
  rmi_.planManipulation(robot_name_1,"xarm7",target_pose1);  
  rmi_.executePlan(robot_name_1);

  rmi_.planManipulation(robot_name_1,"xarm7","test_pose");  
  rmi_.executePlan(robot_name_1);

  target_poseNav.pose.position.x = -0.38;
  target_poseNav.pose.position.y = 0.85;  
  target_poseNav.pose.orientation.z = 0.7071068;
  target_poseNav.pose.orientation.w = 0.7071068;

  rmi_.navigationGoal(robot_name_3,"map",target_poseNav);
  
  rmi_.planManipulation(robot_name_2,"manipulator","home_pose");
  rmi_.executePlan(robot_name_2);
  
  rmi_.controlGripperPosition(robot_name_2,100);    //open
  
  geometry_msgs::PoseStamped target_pose2;  
  target_pose2.pose = rmi_.getEndEffPose(robot_name_2); 

  target_pose2.pose.position.x = 0.61131;
  target_pose2.pose.position.y = 0.12649;
  target_pose2.pose.position.z = 0.32;   
  rmi_.planManipulation(robot_name_2,"manipulator",target_pose2);
  rmi_.executePlan(robot_name_2);

  rmi_.controlGripperPosition(robot_name_2,40);   //close
  
  target_pose2.pose.position.x = 0.61131;
  target_pose2.pose.position.y = 0.12649;
  target_pose2.pose.position.z = 0.60;
  rmi_.planManipulation(robot_name_2,"manipulator",target_pose2);
  rmi_.executePlan(robot_name_2);

  TEMOTO_INFO_STREAM(rmi_.getEndEffPose(robot_name_1)); 
  TEMOTO_INFO_STREAM(rmi_.getEndEffPose(robot_name_2));  
}

// Destructor
~TaDemo1()
{
  TEMOTO_INFO("Action instance destructed");
}

}; // TaDemo1 class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaDemo1, ActionBase);
