#include "Conversion/Messages/geometry_msgs/GeometryMsgsPoint32Converter.h"


UGeometryMsgsPoint32Converter::UGeometryMsgsPoint32Converter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	_MessageType = "geometry_msgs/Point32";
}

bool UGeometryMsgsPoint32Converter::ConvertIncomingMessage(const ROSBridgePublishMsg* message, TSharedPtr<FROSBaseMsg> &BaseMsg) {
	return true;
}

bool UGeometryMsgsPoint32Converter::ConvertOutgoingMessage(TSharedPtr<FROSBaseMsg> BaseMsg, bson_t** message) {
	
	auto Point32 = StaticCastSharedPtr<ROSMessages::geometry_msgs::Point32>(BaseMsg);

	bson_init(*message);
	_bson_append_point32(*message, Point32.Get());

	return true;
}