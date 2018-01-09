#pragma once 

#include "ROSBaseMsg.h"
#include "std_msgs/Header.h"
#include "PointField.h"


namespace ROSMessages{
	namespace sensor_msgs {
		class PointCloud2: public FROSBaseMsg {
		public:
			PointCloud2() {
				_MessageType = "sensor_msgs/PointCloud2";

				// The size of fields and data is undefined initially
				//fields.init(0, 0);
				//data.init(0, 0);
			}

			ROSMessages::std_msgs::Header header;
			uint32 height;
			uint32 width;
			TArray<RosMessages::sensor_msgs::PointField> fields;
			bool is_bigendian;
			uint32 point_step;
			uint32 row_step;
			TArray<uint8> data;
			bool is_dense;

		};
	}
}
