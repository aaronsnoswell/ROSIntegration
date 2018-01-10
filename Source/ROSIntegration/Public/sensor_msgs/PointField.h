#pragma once 

#include "ROSBaseMsg.h"


namespace ROSMessages{
	namespace sensor_msgs {
		class PointField: public FROSBaseMsg {
		public:
			PointField() {
				_MessageType = "sensor_msgs/PointField";
			}

			static enum class EDataType : uint8 {
				INT8 = 1,
				UINT8 = 2,
				INT16 = 3,
				UINT16 = 4,
				INT32 = 5,
				UINT32 = 6,
				FLOAT32 = 7,
				FLOAT64 = 8
			};

			FString name;
			uint32 offset;
			EDataType datatype;
			uint32 count;
		};


	}
}
