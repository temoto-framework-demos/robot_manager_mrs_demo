
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
#include "ta_xarm7_move/temoto_action.h"
#include "ta_xarm7_move/macros.h"

#include "temoto_robot_manager/robot_manager_interface.h"


/* 
 * ACTION IMPLEMENTATION of TaXarm7Move 
 */
class TaXarm7Move : public TemotoAction
{
public:

robot_manager::RobotManagerInterface<TaXarm7Move> rmi_;



const std::string robot_name_ = "xarm7_robot";
// const std::string robot_name_ = "panda";

// Constructor. REQUIRED BY TEMOTO
TaXarm7Move()
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
  
  // rmi_.plan("xarm7");
  //rmi_.plan("panda_arm");

  geometry_msgs::PoseStamped target_pose1;
  
  target_pose1.pose = rmi_.getEndEffPose("base_link","tool0");
  

  // Close coordinate near initial position
  // target_pose1.pose.position.x = 0.25;
  // target_pose1.pose.position.y = 0.48;
  // target_pose1.pose.position.z = 0.5;

  
  // rmi_.plan(target_pose1,"panda_arm");  

  //rmi_.plan(target_pose1,"xarm7");  
  //rmi_.execute();


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

  
  //TEMOTO_INFO_STREAM( "TARGET POSE " << target_pose1.pose.position.x);
  //TEMOTO_INFO_STREAM( "GETMOVEITRVIZCONF" << rmi_.getMoveitRvizConfig());
  //rmi_.plan(target_pose1,"xarm7");  
  //rmi_.getEndEffPose("base_link","tool0");

  TEMOTO_INFO_STREAM(rmi_.getEndEffPose("base_link","tool0"));  
  TEMOTO_INFO_STREAM("=====End Action ======"); 
  
}

// Destructor
~TaXarm7Move()
{
  // ---> YOUR CONSTRUCTION ROUTINES HERE <--- //
  TEMOTO_INFO_STREAM("Destructor " << getUmrfPtr()->getName());
}

}; // TaXarm7Move class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaXarm7Move, ActionBase);
