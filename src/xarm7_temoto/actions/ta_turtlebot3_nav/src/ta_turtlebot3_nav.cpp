
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
#include "ta_turtlebot3_nav/temoto_action.h"
#include "ta_turtlebot3_nav/macros.h"

#include "temoto_robot_manager/robot_manager_interface.h"

/* 
 * ACTION IMPLEMENTATION of TaTurtlebot3Nav 
 */
class TaTurtlebot3Nav : public TemotoAction
{
public:

robot_manager::RobotManagerInterface<TaTurtlebot3Nav> rmi_;

const std::string robot_name_ = "xarm7_robot";

// Constructor. REQUIRED BY TEMOTO
TaTurtlebot3Nav()
{
  // ---> YOUR CONSTRUCTION ROUTINES HERE <--- //
  std::cout << __func__ << " constructed\n";
}

// REQUIRED BY TEMOTO
void executeTemotoAction()
{
  // Input parameters
  double input_1 = GET_PARAMETER("input_1", double);
  double input_0 = GET_PARAMETER("input_0", double);

  rmi_.initialize(this);
  TEMOTO_INFO_STREAM("loading " << robot_name_);
  rmi_.loadRobot(robot_name_);
  TEMOTO_INFO_STREAM(robot_name_ << " initialized");

  TEMOTO_INFO("=== TEST PROGRAM NAVIGATION =====");

  geometry_msgs::PoseStamped target_poseNav;
  target_poseNav.pose.position.x = input_0;
  target_poseNav.pose.position.y = input_1;

  rmi_.navigationGoal(robot_name_,"map",target_poseNav); 

  TEMOTO_INFO_STREAM("=====End Action ======"); 


  // rmi_.planManipulation(robot_name_,"xarm7");
  // geometry_msgs::PoseStamped target_pose1;  
  // target_pose1.pose.position.y -= 0.3;
  // target_pose1.pose.position.z -= 0.2;
  // rmi_.planManipulation(robot_name_,,"xarm7",target_pose1);  
  // rmi_.execute();
  // TEMOTO_INFO_STREAM(rmi_.getEndEffPose("base_link","tool0"));


}

// Destructor
~TaTurtlebot3Nav()
{
  // ---> YOUR CONSTRUCTION ROUTINES HERE <--- //
  TEMOTO_PRINT_OF("Destructor", getUmrfPtr()->getName());
}

}; // TaTurtlebot3Nav class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaTurtlebot3Nav, ActionBase);
