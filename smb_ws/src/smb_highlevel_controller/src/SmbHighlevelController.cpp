#include <smb_highlevel_controller/SmbHighlevelController.hpp>

namespace smb_highlevel_controller {

void SmbHighlevelController::scanCallback(const sensor_msgs::LaserScan& scan){
	ROS_INFO_STREAM("Scan callback" << scan);
}


SmbHighlevelController::SmbHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{
	scansubscriber_ = nodeHandle_.subscribe("scan", 10, &SmbHighlevelController::scanCallback, this);
}

SmbHighlevelController::~SmbHighlevelController()
{
}

} /* namespace */
