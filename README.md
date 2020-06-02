# Robot Manager Demo

This repository contains the source materials for reproducing the [multi-robot object transportation demo](), which demonstrates the enabling features of TeMoto Robot Manager.

The demo consist of an heterogeneous multi-robot system that is tasked to transport an object from one point to another. The robots involved in this demo are:
* *xArm7* manipulator with *xArm* two finger gripper
* *UR5* manipulator with *Kinova KG-3* gripper
* *Clearbot* mobile base

In the course of the demo
1. xArm7 manipulator picks up an object located on top of a table
2. Clearbot navigates under the xArm7 manipulator
3. xArm7 manipulator places the object on top of Clearbot
4. Clearbot navigates towards the UR5 manipulator
5. UR5 manipulator picks up the object from the Clearbot using the kinova gripper 

# Structure of This Repository
This repository is distributed on *4 branches* as follows: 

## 1. master branch
Contains the common base code that is shared across all platforms in the demo, including launch files for launcing TeMoto and TeMoto Robot Manager (TRM).

## 2. operator branch
The operator branch contains the workspace intended for the operator (user). This branch contains the action neccessary for coordinating the whole multi-robot system and the transportation task. 

## 3. manipulators branch
The manipulators branch contains all of the packages and configuration files required for controlling the manipulatios and grippers. The xArm, UR5 and Kinova-ros repositories are included as submodules. 
TODO: The xarm7_wgrip_moveit and ur5_with_kinova_gripper have a robot_description.yaml file that contains the configuration for each arm, with the respective driver and controller executables. 

## 4. robotont branch
This branch contains the configuration files for setting up TeMoto on Clearbot. The robot_description.yaml file contains the configuration of the navigation feature. 

# Setting Up and Running the Demo
TODO: add the figures
Create a catkin workspace for each workstation 

### Opertor workstation:
``` bash
cd your_catkin_workspace/src
git clone -b operator https://github.com/temoto-telerobotics-demos/robot_manager_mrs_demo.git
cd your_catkin_workspace
catkin build
export ROS_IP='http://192.168.0.131'
roslaunch operator_tws temoto.launch
```

### Manipulators workstation:
``` bash
cd your_catkin_workspace/src
git clone -b manipulators https://github.com/temoto-telerobotics-demos/robot_manager_mrs_demo.git
cd your_catkin_workspace
catkin build
export ROS_MASTER_URI='http://192.168.0.131'
export ROS_IP='http://192.168.0.173'
roslaunch manipulators_tws temoto.launch
```

### Robotont workstation:
``` bash
cd your_catkin_workspace/src
git clone -b robotont https://github.com/temoto-telerobotics-demos/robot_manager_mrs_demo.git
cd your_catkin_workspace
catkin build
export ROS_MASTER_URI='http://192.168.0.131'
export ROS_IP='http://192.168.0.102'
roslaunch robotont_ws temoto.launch
```


Once the three instances of TeMoto are running, it is necessary to trigger the action
``` bash
# In another terminal of the opertor workstation:
roslaunch ta_demo_1 action_test_separate.launch wake_workd:=operator_tws
```

