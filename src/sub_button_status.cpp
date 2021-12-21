#include "ros/ros.h"
#include "robot_model/button_msg.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <std_msgs/String.h>
#include <actionlib/client/simple_action_client.h>
#include <sstream>
#include <iostream>
// #include <string>

// void chatterCallback(const robot_model::button_msg::ConstPtr& msg)
// {
//     ROS_INFO("I heard button_name: [%s]", msg->button_name.c_str());
//     ROS_INFO("I heard status: [%d]", msg->status);
//     move_base_msgs::MoveBaseGoal goal;
//     try{
//         goal.target_pose.pose.position.x = 1;
//         goal.target_pose.pose.position.y = 0;
//         goal.target_pose.pose.orientation.w = 1;
//     }
//     catch(int e){


//         goal.target_pose.pose.position.x = 1.0;
//         goal.target_pose.pose.position.y = 1.0;
//         goal.target_pose.pose.orientation.w = 1.0;
//     }
//     goal_pub.publish(goal);

// }

// void spin(){

// }

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class Goal_calc{
public:
    Goal_calc();
    void buttonCallback(const std_msgs::String& b);
    
private: 
    ros::NodeHandle n;
    ros::Publisher goal_pub;
    ros::Subscriber sub;
    
    
    MoveBaseClient ac;

    int status;
    std::string button_name;
    ros::Time time;
    void init_variables();
};

Goal_calc::Goal_calc() : ac("move_base", true){
    init_variables();
    while(!ac.waitForServer(ros::Duration(5.0))){
        ROS_INFO("Waiting for the move_base action server");
	}
    goal_pub = n.advertise<move_base_msgs::MoveBaseGoal>("goal", 50);
    sub = n.subscribe("demo_msg_topic", 50, &Goal_calc::buttonCallback, this);

    // ac("move_base", true);



}


void Goal_calc::init_variables(){
    time = ros::Time::now();
    status = 0;
    button_name = "";

}

void Goal_calc::buttonCallback(const std_msgs::String& b){
    button_name = b.data;
 
    ROS_INFO("I heard button_name: [%s]", button_name.c_str());

    move_base_msgs::MoveBaseGoal goal;

	goal.target_pose.header.frame_id = "map";
	goal.target_pose.header.stamp = ros::Time::now();

    if(button_name == "button_1"){
        // try{
        goal.target_pose.pose.position.x = -0.004;
        goal.target_pose.pose.position.y = -0.517;
        goal.target_pose.pose.orientation.w = 0.999;
        goal.target_pose.pose.orientation.z = -0.043;
        // }
        // catch(int e){


        //     goal.target_pose.pose.position.x = 1.0;
        //     goal.target_pose.pose.position.y = 1.0;
        //     goal.target_pose.pose.orientation.w = 1.0;
        // }

        goal_pub.publish(goal);
    }
    else if(button_name == "button_2"){
        goal.target_pose.pose.position.x = 0.518;
        goal.target_pose.pose.position.y = 1.723;
        goal.target_pose.pose.orientation.w = 0.7;
        goal.target_pose.pose.orientation.z = 0.7;
        // }
        // catch(int e){


        //     goal.target_pose.pose.position.x = 1.0;
        //     goal.target_pose.pose.position.y = 1.0;
        //     goal.target_pose.pose.orientation.w = 1.0;
        // }
        goal_pub.publish(goal);
    }

    ac.sendGoal(goal);
    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Robot has arrived to the goal position");
    else{
        ROS_INFO("The base failed for some reason");
    }

}

int main(int argc, char **argv)
{
    

    ros::init(argc, argv, "demo_msg_subscriber");
    

    Goal_calc obj;

  
 
    ros::spin();

    return 0;
}