#include <smb_highlevel_controller/SmbHighlevelController.hpp>

namespace smb_highlevel_controller {

void SmbHighlevelController::scanCallback(const sensor_msgs::LaserScan& scan){
	// ROS_INFO_STREAM("Scan callback" << scan);

	int min_range = 10000;
	int scan_len = scan.ranges.size();
	for(int i = 0; i < scan_len; i++){
		if(scan.ranges[i] < min_range){
			min_range = scan.ranges[i];
		}
	}

	ROS_INFO_STREAM("Smallest distance is " << min_range);
}

void SmbHighlevelController::getAllParameters(){
	
	if(!nodeHandle_.getParam("topic_name", topic_name_)){
		ROS_ERROR("Could not find topic_name parameter");
	}

	if(!nodeHandle_.getParam("queue_size", queue_size_)){
		ROS_ERROR("Could not find queue_size parameter");
	}
}

SmbHighlevelController::SmbHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{
	SmbHighlevelController::getAllParameters();
	scansubscriber_ = nodeHandle_.subscribe(topic_name_, queue_size_, &SmbHighlevelController::scanCallback, this);
}

SmbHighlevelController::~SmbHighlevelController()
{
}

} /* namespace */
