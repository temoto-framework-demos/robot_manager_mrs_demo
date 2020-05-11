
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
#include "ta_move_clearbot/temoto_action.h"
#include "ta_move_clearbot/macros.h"

#include "temoto_robot_manager/robot_manager_interface.h"

/* 
 * ACTION IMPLEMENTATION of TaMoveClearbot 
 */
class TaMoveClearbot : public TemotoAction
{
public:

robot_manager::RobotManagerInterface<TaMoveClearbot> rmi_;
const std::string robot_name_3 = "clearbot";

// Constructor. REQUIRED BY TEMOTO
TaMoveClearbot()
{
  std::cout << __func__ << " constructed\n";
}

// REQUIRED BY TEMOTO
void executeTemotoAction()
{

  rmi_.initialize(this);
  TEMOTO_INFO_STREAM("loading " << robot_name_3);
  rmi_.loadRobot(robot_name_3);
  TEMOTO_INFO_STREAM(robot_name_3 << " initialized");

  geometry_msgs::PoseStamped target_poseNav;
  target_poseNav.pose.position.x = 0;
  target_poseNav.pose.position.y = -0.8;
  target_poseNav.pose.orientation.z = 0;
  target_poseNav.pose.orientation.w = 1;

  rmi_.navigationGoal(robot_name_3,"map",target_poseNav);  

  ros::Duration(3).sleep();

  target_poseNav.pose.position.x = -0.4;
  target_poseNav.pose.position.y = 0.8;
  
  target_poseNav.pose.orientation.z = 0.7071068;
  target_poseNav.pose.orientation.w = 0.7071068;

  rmi_.navigationGoal(robot_name_3,"map",target_poseNav);

  
  
  TEMOTO_INFO_STREAM("================= End Action ============= ");


}

// Destructor
~TaMoveClearbot()
{
  TEMOTO_INFO("Action instance destructed");
}

}; // TaMoveClearbot class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaMoveClearbot, ActionBase);
