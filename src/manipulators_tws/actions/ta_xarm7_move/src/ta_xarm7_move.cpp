
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
#include <xarm_driver.h>



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

  ros::NodeHandle nh_;  
  ros::ServiceClient gripper_config_client_0 = nh_.serviceClient<xarm_msgs::GripperState>("/xarm7_temoto/robot_manager/robots/xarm7_robot/xarm/gripper_state");
  ros::ServiceClient gripper_config_client = nh_.serviceClient<xarm_msgs::GripperConfig>("/xarm7_temoto/robot_manager/robots/xarm7_robot/xarm/gripper_config");
  ros::ServiceClient gripper_config_client_2 = nh_.serviceClient<xarm_msgs::GripperMove>("/xarm7_temoto/robot_manager/robots/xarm7_robot/xarm/gripper_move");
  xarm_msgs::GripperState srv_0;
  gripper_config_client_0.call(srv_0);

  xarm_msgs::GripperConfig srv_1;
  srv_1.request.pulse_vel = 1500;
  gripper_config_client.call(srv_1);

  //Start
  geometry_msgs::PoseStamped target_pose1;
  
  rmi_.planManipulation(robot_name_,"xarm7","test_pose");
  rmi_.execute();
  target_pose1.pose = rmi_.getEndEffPose(robot_name_);

  
  xarm_msgs::GripperMove srv2;
  srv2.request.pulse_pos = 200;
  gripper_config_client_2.call(srv2);

  
  srv2.request.pulse_pos = 800;
  gripper_config_client_2.call(srv2);

  
  //Centro ++
  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.51192;

  rmi_.planManipulation(robot_name_,"xarm7",target_pose1);  
  rmi_.execute();

  // ros::Duration(1).sleep();

  // target_pose1.pose.orientation.x= 0.71858;
  // target_pose1.pose.orientation.y= -0.69456;
  // target_pose1.pose.orientation.z= -0.034127;
  // target_pose1.pose.orientation.w= 0.0086347;

  // rmi_.plan(robot_name_,"xarm7",target_pose1);  
  // rmi_.execute();

  // Abre gripper
  // srv2.request.pulse_pos = 800;
  // gripper_config_client_2.call(srv2);

  // Baja   
  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.21;
  rmi_.planManipulation(robot_name_,"xarm7",target_pose1);  
  rmi_.execute();

  //cierra 
  ros::Duration(3).sleep();
  srv2.request.pulse_pos = 700;
  gripper_config_client_2.call(srv2);
  ros::Duration(1).sleep();

  //sube 
  target_pose1.pose.position.x = 0.61288;
  target_pose1.pose.position.y = 0.042255;
  target_pose1.pose.position.z = 0.52;
  rmi_.planManipulation(robot_name_,"xarm7",target_pose1);  
  rmi_.execute();


  rmi_.planManipulation(robot_name_,"xarm7","test_pose");  
  rmi_.execute();

  

  // Close coordinate near initial position
  // //================ WITHOUT BASE - WITHOUT GRIPPER ======================
  // for (int i=0; i<3;i++){
  //   target_pose1.pose.position.x = 0.20;
  //   target_pose1.pose.position.y = -0.15;
  //   target_pose1.pose.position.z = 0.25;
    
  //   // rmi_.plan(robot_name_,target_pose1,"panda_arm");  

  //   rmi_.plan(target_pose1,"xarm7");  
  //   rmi_.execute();

  //   target_pose1.pose.position.x = 0.20;
  //   target_pose1.pose.position.y = 0.15;
  //   target_pose1.pose.position.z = 0.25;
    
  //   // rmi_.plan(robot_name_,target_pose1,"panda_arm");  

  //   rmi_.plan(robot_name_,target_pose1,"xarm7");  
  //   rmi_.execute();
  // }
  // //=====================================

  
  // =================== Similar to test_pose ===================
  // =================== triangle ===================

  /*target_pose1.pose.position.x= 0.000342619;
  target_pose1.pose.position.y= 0.311218;
  target_pose1.pose.position.z= 0.500637;
  // target_pose1.pose.orientation.x= 0.706598;
  // target_pose1.pose.orientation.y= 0.706749;
  // target_pose1.pose.orientation.z= -0.0247646;
  // target_pose1.pose.orientation.w= 0.0247535;
  rmi_.plan(robot_name_,target_pose1,"xarm7");  
  rmi_.execute();

  target_pose1.pose.position.x= 0.18276;
  target_pose1.pose.position.y= 0.32375;
  target_pose1.pose.position.z= 0.68065;  
  rmi_.plan(robot_name_,target_pose1,"xarm7");  
  rmi_.execute();

  target_pose1.pose.position.x= -0.22708;
  target_pose1.pose.position.y= 0.32407;
  target_pose1.pose.position.z= 0.68047;  
  rmi_.plan(robot_name_,target_pose1,"xarm7");  
  rmi_.execute();

  target_pose1.pose.position.x= 0.000342619;
  target_pose1.pose.position.y= 0.311218;
  target_pose1.pose.position.z= 0.500637;
  // target_pose1.pose.orientation.x= 0.706598;
  // target_pose1.pose.orientation.y= 0.706749;
  // target_pose1.pose.orientation.z= -0.0247646;
  // target_pose1.pose.orientation.w= 0.0247535;
  rmi_.plan(robot_name_,target_pose1,"xarm7");  
  rmi_.execute();*/
 
  // rmi_.plan(robot_name_,"xarm7","home_pose");
  // rmi_.execute();


  TEMOTO_INFO_STREAM(rmi_.getEndEffPose(robot_name_));  
  TEMOTO_INFO_STREAM("=====End Action ======"); 

  // gripper
  //  /xarm7_temoto/robot_manager/robots/xarm7_robot/xarm/gripper_config
  //  /xarm7_temoto/robot_manager/robots/xarm7_robot/xarm/gripper_move
  //  /xarm7_temoto/robot_manager/robots/xarm7_robot/xarm/gripper_state

  

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
