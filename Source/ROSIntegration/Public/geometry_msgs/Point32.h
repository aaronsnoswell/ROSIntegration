#pragma once 

#include "ROSBaseMsg.h"

namespace ROSMessages{
	namespace geometry_msgs {
		class Point32: public FROSBaseMsg {
		public:
			Point32() {
				_MessageType = "geometry_msgs/Point32";
			}

			Point32(double x, double y, double z) : x(x), y(y), z(z){
				_MessageType = "geometry_msgs/Point32";
			}

			float x;
			float y;
			float z;

		};
	}
}
