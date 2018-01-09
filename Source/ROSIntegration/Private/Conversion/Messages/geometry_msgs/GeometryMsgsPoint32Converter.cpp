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
	return true;
}