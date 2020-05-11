
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
const std::string robot_name_1 = "xarm7_robot";

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
  TEMOTO_INFO_STREAM("loading " << robot_name_1);
  rmi_.loadRobot(robot_name_1);
  TEMOTO_INFO_STREAM(robot_name_1 << " initialized");  
  
  geometry_msgs::PoseStamped target_pose1;
  
  rmi_.planManipulation(robot_name_1,"xarm7","test_pose");
  rmi_.execute();
  target_pose1.pose = rmi_.getEndEffPose(robot_name_1);

  rmi_.controlGripperPosition(robot_name_1,800);   //open

  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.51192;
  rmi_.planManipulation(robot_name_1,"xarm7",target_pose1);  
  rmi_.execute();

  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.21;
  rmi_.planManipulation(robot_name_1,"xarm7",target_pose1);  
  rmi_.execute();

  rmi_.controlGripperPosition(robot_name_1,400);   //close

  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.52;
  rmi_.planManipulation(robot_name_1,"xarm7",target_pose1);  
  rmi_.execute();


  rmi_.planManipulation(robot_name_1,"xarm7","test_pose");  
  rmi_.execute();

  TEMOTO_INFO_STREAM(rmi_.getEndEffPose(robot_name_1));
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
