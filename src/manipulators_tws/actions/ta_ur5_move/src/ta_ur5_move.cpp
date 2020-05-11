
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
#include "ta_ur5_move/temoto_action.h"
#include "ta_ur5_move/macros.h"

#include "temoto_robot_manager/robot_manager_interface.h"

/* 
 * ACTION IMPLEMENTATION of TaUr5Move 
 */
class TaUr5Move : public TemotoAction
{
public:

robot_manager::RobotManagerInterface<TaUr5Move> rmi_;
const std::string robot_name_2 = "ur5_robot";


// Constructor. REQUIRED BY TEMOTO
TaUr5Move()
{
  std::cout << __func__ << " constructed\n";
}

// REQUIRED BY TEMOTO
void executeTemotoAction()
{

  rmi_.initialize(this);
  TEMOTO_INFO_STREAM("loading " << robot_name_2);
  rmi_.loadRobot(robot_name_2);
  TEMOTO_INFO_STREAM(robot_name_2 << " initialized");

  // rmi_.planManipulation(robot_name_2,"manipulator","test_pose");
  // rmi_.execute();
  rmi_.planManipulation(robot_name_2,"manipulator","home_pose");
  rmi_.execute();
  
  rmi_.controlGripperPosition(robot_name_2,0);    //open
  geometry_msgs::PoseStamped target_pose2;  
  target_pose2.pose = rmi_.getEndEffPose(robot_name_2); 

  //object
  target_pose2.pose.position.x = 0.61131;
  target_pose2.pose.position.y = 0.12649;
  target_pose2.pose.position.z = 0.34211;   
  rmi_.planManipulation(robot_name_2,"manipulator",target_pose2);
  rmi_.execute();

  TEMOTO_INFO_STREAM(rmi_.getEndEffPose(robot_name_2));  

  TEMOTO_INFO_STREAM("Gripper Kinova");

  rmi_.controlGripperPosition(robot_name_2,50);   //close
  
  // UP
  target_pose2.pose.position.x = 0.61131;
  target_pose2.pose.position.y = 0.12649;
  target_pose2.pose.position.z = 0.60;
  rmi_.planManipulation(robot_name_2,"manipulator",target_pose2);
  rmi_.execute();

  
  TEMOTO_INFO_STREAM("=====End Action ======"); 
  
}

// Destructor
~TaUr5Move()
{
  TEMOTO_INFO("Action instance destructed");
}

}; // TaUr5Move class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaUr5Move, ActionBase);
