
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
const std::string robot_name_1 = "xarm7_robot_sim";
const std::string robot_name_2 = "ur5_robot_sim";
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

  // xarm7_robot_sim
  

  // ur5_robot  
  TEMOTO_INFO_STREAM("loading " << robot_name_2);
  rmi_.loadRobot(robot_name_2);
  TEMOTO_INFO_STREAM(robot_name_2 << " initialized");


TEMOTO_INFO_STREAM("loading " << robot_name_1);
  rmi_.loadRobot(robot_name_1);
  TEMOTO_INFO_STREAM(robot_name_1 << " initialized");
  // clearbot
  // TEMOTO_INFO_STREAM("loading " << robot_name_3);
  // rmi_.loadRobot(robot_name_3);
  // TEMOTO_INFO_STREAM(robot_name_3 << " initialized");

  
  // =================== Similar to test_pose ===================  
  // geometry_msgs::PoseStamped target_pose1;
  // //target_pose1.pose = rmi_.getEndEffPose(robot_name_1);
  // target_pose1.pose.position.x = 0.00019109;
  // target_pose1.pose.position.y = 0.31125;
  // target_pose1.pose.position.z = 0.50067;
  // target_pose1.pose.orientation.x = 0.70691;
  // target_pose1.pose.orientation.y = 0.70644;
  // target_pose1.pose.orientation.z = -0.024783;
  // target_pose1.pose.orientation.w = 0.024728;
  // rmi_.planManipulation(target_pose1,"xarm7");  
  // // rmi_.execute();
  // TEMOTO_INFO_STREAM(rmi_.getEndEffPose(robot_name_1)); 
  // TEMOTO_INFO_STREAM("================= End Step 1 ============= ");

  // rmi_.planManipulation(robot_name_1,"xarm7","test_pose");
  // rmi_.execute();

  // rmi_.planManipulation(robot_name_2,"manipulator","test_pose");
  // rmi_.execute();

  // rmi_.planManipulation(robot_name_1,"xarm7","home_pose");
  // rmi_.execute();

  // rmi_.planManipulation(robot_name_2,"manipulator","home_pose");
  // rmi_.execute();

  rmi_.controlGripperPosition(robot_name_1,50);
  rmi_.controlGripperPosition(robot_name_2,150);

  // ============================================================

  // =================== Similar to test_pose ===================  
  // geometry_msgs::PoseStamped target_pose2;  
  // target_pose2.pose = rmi_2.getEndEffPose(robot_name_2);
  // target_pose2.pose.position.x = 0.23;
  // target_pose2.pose.position.y = 0.56;
  // target_pose2.pose.position.z = 0.55;
  // rmi_2.planManipulation(target_pose2,"manipulator");  
  // // rmi_2.execute();
  // TEMOTO_INFO_STREAM("================= End Step 2 ============= ");
  // ============================================================

  // ============================================================
  geometry_msgs::PoseStamped target_poseNav;
  target_poseNav.pose.position.x = 0.3;
  target_poseNav.pose.position.y = 0.2;
  target_poseNav.pose.orientation.w = -1.0;
  // rmi_.navigationGoal(robot_name_3,"map",target_poseNav);
  TEMOTO_INFO_STREAM("================= End Step 3 ============= ");
  // ============================================================ 
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
