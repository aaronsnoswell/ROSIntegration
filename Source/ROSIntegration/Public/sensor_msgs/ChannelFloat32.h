#pragma once 

#include "ROSBaseMsg.h"

namespace ROSMessages{
	namespace sensor_msgs {
		class ChannelFloat32: public FROSBaseMsg {
		public:
			ChannelFloat32() {
				_MessageType = "geometry_msgs/ChannelFloat32";

				// The size of values is undefined initially
				//values.init(0, 0);
			}

			FString name;
			TArray<float> values;

		};
	}
}
