#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

namespace smb_highlevel_controller {

/*!
 * Class containing the Husky Highlevel Controller
 */
class SmbHighlevelController {
public:
	/*!
	 * Constructor.
	 */
	SmbHighlevelController(ros::NodeHandle& nodeHandle);

	void scanCallback(const sensor_msgs::LaserScan& scan);

	/*!
	 * Destructor.
	 */
	virtual ~SmbHighlevelController();

private:
	ros::NodeHandle nodeHandle_;
	ros::Subscriber scansubscriber_; // private variable for subscriber
};

} /* namespace */
