#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

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
	void getAllParameters();

	/*!
	 * Destructor.
	 */
	virtual ~SmbHighlevelController();

private:
	ros::NodeHandle nodeHandle_;
	ros::Subscriber scansubscriber_; // private variable for subscriber
	int queue_size_;
	std::string topic_name_;
	ros::Publisher pillar_publisher_;
	geometry_msgs::Twist pillar_twist_;
	float vel_x;
	float p_gains;
};

} /* namespace */
