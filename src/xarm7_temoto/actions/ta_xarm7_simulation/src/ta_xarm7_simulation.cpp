
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
#include "ta_xarm7_simulation/temoto_action.h"
#include "ta_xarm7_simulation/macros.h"

#include "temoto_robot_manager/robot_manager_interface.h"

/* 
 * ACTION IMPLEMENTATION of TaXarm7Simulation 
 */
class TaXarm7Simulation : public TemotoAction
{
public:

robot_manager::RobotManagerInterface<TaXarm7Simulation> rmi_;
const std::string robot_name_ = "xarm7_robot_sim";

// Constructor. REQUIRED BY TEMOTO
TaXarm7Simulation()
{
  // ---> YOUR CONSTRUCTION ROUTINES HERE <--- //
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
 
  // =================== Similar to test_pose ===================
  target_pose1.pose.position.x = 0.00019109;
  target_pose1.pose.position.y = 0.31125;
  target_pose1.pose.position.z = 0.50067;
  target_pose1.pose.orientation.x = 0.70691;
  target_pose1.pose.orientation.y = 0.70644;
  target_pose1.pose.orientation.z = -0.024783;
  target_pose1.pose.orientation.w = 0.024728;
  rmi_.plan(target_pose1,"xarm7");  
  rmi_.execute();
  // ============================================================

  TEMOTO_INFO_STREAM(rmi_.getEndEffPose("base_link","tool0"));  
  TEMOTO_INFO_STREAM("=====End Action ======"); 

}

// Destructor
~TaXarm7Simulation()
{
  // ---> YOUR CONSTRUCTION ROUTINES HERE <--- //
  TEMOTO_PRINT_OF("Destructor", getUmrfPtr()->getName());
}

}; // TaXarm7Simulation class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaXarm7Simulation, ActionBase);
