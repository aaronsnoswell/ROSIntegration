#pragma once 

#include "ROSBaseMsg.h"


namespace ROSMessages{
	namespace sensor_msgs {
		class PointField: public FROSBaseMsg {
		public:
			PointField() {
				_MessageType = "sensor_msgs/PointField";
			}

			static const uint8 INT8=1;
			static const uint8 UINT8=1;
			static const uint8 INT16=1;
			static const uint8 UINT16=1;
			static const uint8 INT32=1;
			static const uint8 UINT32=1;
			static const uint8 FLOAT32=1;
			static const uint8 FLOAT64=1;

			string name;
			uint32 offset;
			uint8 datatype;
			uint32 count;
		};


	}
}
