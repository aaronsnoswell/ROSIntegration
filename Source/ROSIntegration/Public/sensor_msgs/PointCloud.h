#pragma once 

#include "ROSBaseMsg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point32.h"
#include "ChannelFloat32.h"


namespace ROSMessages{
	namespace sensor_msgs {
		class PointCloud: public FROSBaseMsg {
		public:
			PointCloud() {
				_MessageType = "sensor_msgs/PointCloud";

				// The size of points and channels is undefined initially
				//points.init(0, 0);
				//channels.init(0, 0);
			}

			ROSMessages::std_msgs::Header header;
			uint32 seq;
			uint32 step;
			FString frame_id;
			TArray<RosMessages::geometry_msgs::Point32> points;
			TArray<RosMessages::sensor_msgs::ChannelFloat32> channels;
		};
	}
}
