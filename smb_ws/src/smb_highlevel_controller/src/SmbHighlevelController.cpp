#include <smb_highlevel_controller/SmbHighlevelController.hpp>

namespace smb_highlevel_controller {

void SmbHighlevelController::scanCallback(const sensor_msgs::LaserScan& scan){
	ROS_INFO_STREAM("Scan callback" << scan);
}

void SmbHighlevelController::getAllParameters(){
	
	if(!nodeHandle_.getParam("topic_name_", topic_name_)){
		ROS_ERROR("Could not find topic_name_ parameter");
	}

	if(!nodeHandle_.getParam("queue_size_", queue_size_)){
		ROS_ERROR("Could not find queue_size_ parameter");
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
