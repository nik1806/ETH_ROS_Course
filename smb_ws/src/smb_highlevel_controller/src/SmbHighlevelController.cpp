#include <smb_highlevel_controller/SmbHighlevelController.hpp>

namespace smb_highlevel_controller {

SmbHighlevelController::SmbHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{
	SmbHighlevelController::getAllParameters();
	pillar_publisher_ = nodeHandle_.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
	scansubscriber_ = nodeHandle_.subscribe(topic_name_, queue_size_, &SmbHighlevelController::scanCallback, this);
}

SmbHighlevelController::~SmbHighlevelController()
{
}

void SmbHighlevelController::scanCallback(const sensor_msgs::LaserScan& scan){
	// ROS_INFO_STREAM("Scan callback" << scan);

	float smallest_dist = scan.ranges[0];
	int scan_len = scan.ranges.size();
	int smallest_idx = 0;
	for(int i = 0; i < scan_len; i++){
		if(scan.ranges[i] < smallest_dist){
			smallest_dist = scan.ranges[i];
			smallest_idx = i;
		}
	}

	ROS_INFO_STREAM("Smallest distance is " << smallest_dist);
	
	// For sensor_msgs::LaserScan messages
	// x = r * cos() 
	// y = r * sin()
	// Position of pillar relative to robot position (closest laser point)
	float angle = scan.angle_min + smallest_idx * scan.angle_increment;
	float pillar_x = std::cos(angle) * smallest_dist;
	float pillar_y = std::sin(angle) * smallest_dist;

	// simple P controller
	pillar_twist_.linear.x = vel_x;
	pillar_twist_.angular.z = p_gains * angle;

	ROS_INFO_STREAM("Pillar position is " << pillar_twist_);

	pillar_publisher_.publish(pillar_twist_);
}

void SmbHighlevelController::getAllParameters(){
	
	if(!nodeHandle_.getParam("topic_name", topic_name_)){
		ROS_ERROR("Could not find topic_name parameter");
	}

	if(!nodeHandle_.getParam("queue_size", queue_size_)){
		ROS_ERROR("Could not find queue_size parameter");
	}

	if(!nodeHandle_.getParam("vel_x", vel_x)){
		ROS_ERROR("Could not find vel_x parameter");
	}

	if(!nodeHandle_.getParam("p_gains", p_gains)){
		ROS_ERROR("Could not find p_gains parameter");
	}
}

} /* namespace */
