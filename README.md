# Robot Manager Demo

This repository contains the TeMoto Robot Manager package and a demo to show the capabilities of TRM to control manipulators, mobile bases and grippers. 
### Hardware used
* xArm7 with gripper
* UR5
* Clearbot
* Kinova KG-3 gripper

It is distribute on 4 branches as follow: 

## Master
Contains a empty space with the necessary packages to start a new project using TeMoto Robot Manager (TRM)

## operator
The operator branch contains the workspace intended for the user. It has an action with a series of instructions to execute the transportation task. 

## manipulators
The manipulator branck contains all of the packages required for manipulation and gripper purposes. The original repositories of xArm, UR5 and Kinova-ros were added as submodule. 
The xarm7_wgrip_moveit and ur5_with_kinova_gripper have a robot_description.yaml file that contains the configuration for each arm, with the respective driver and controller executables. 


## robotont
This branch represent an instance of TeMoto running on the Clearbot robot. The robot_description.yaml file contains the configuration of the navigation feature for the mobile base. 


## Demo
The demo consist of an heterogeneous multi-robot system controlled to transport an object from one point to another. 
The xArm7 robot picks up an object located on top of a table, the clearbot navigates under the xArm robot, which puts the object on top of clearbot. Then Clearbot navigates towards the UR5 robot, and when it reaches the goal, the UR5 takes the object from the clearbot using the kinova gripper. 

![Demo Architecture](/home/fabianparra/Pictures/TeMoto_arch_demo.png)
Format: ![Alt Text](url)

# How to run it

``` bash
Opertor station:
git clone -b operator https://github.com/temoto-telerobotics-demos/robot_manager_mrs_demo.git
roslaunch operator_tws temoto.launch
```

``` bash
manipulator station:
git clone -b manipulators https://github.com/temoto-telerobotics-demos/robot_manager_mrs_demo.git

roslaunch manipulators_tws temoto.launch
```

``` bash
robotont station:
git clone -b robotont https://github.com/temoto-telerobotics-demos/robot_manager_mrs_demo.git
roslaunch robotont_ws temoto.launch
```

Once the three instance of TeMoto are running, it is necessary to trigger the action
``` bash
Opertor station:
roslaunch ta_demo_1 action_test_separate.launch wake_workd:=operator_tws
```

