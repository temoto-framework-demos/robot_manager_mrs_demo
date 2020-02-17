
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
const std::string robot_name_ = "ur5_robot";


// Constructor. REQUIRED BY TEMOTO
TaUr5Move()
{
  std::cout << __func__ << " constructed\n";
}

// REQUIRED BY TEMOTO
void executeTemotoAction()
{

  rmi_.initialize(this);
  TEMOTO_INFO_STREAM("loading " << robot_name_);
  rmi_.loadRobot(robot_name_);
  TEMOTO_INFO_STREAM(robot_name_ << " initialized");
  
  geometry_msgs::PoseStamped target_pose1;
  
  target_pose1.pose = rmi_.getEndEffPose("base_link","tool0");

  target_pose1.pose.position.x = 0.23;
  target_pose1.pose.position.y = 0.56;
  target_pose1.pose.position.z = 0.55; 

  rmi_.plan(target_pose1,"manipulator");  
  rmi_.execute();

  TEMOTO_INFO_STREAM(rmi_.getEndEffPose("base_link","tool0"));  
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
