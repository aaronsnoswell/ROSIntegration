#include "Conversion/Messages/sensor_msgs/SensorMsgsPointFieldConverter.h"



USensorMsgsPointFieldConverter::USensorMsgsPointFieldConverter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	_MessageType = "sensor_msgs/PointField";
}

bool USensorMsgsPointFieldConverter::ConvertIncomingMessage(const ROSBridgePublishMsg* message, TSharedPtr<FROSBaseMsg> &BaseMsg) {
	UE_LOG(LogTemp, Warning, TEXT("ROSIntegration: PointField receiving not implemented yet"));
	return false;
}

bool USensorMsgsPointFieldConverter::ConvertOutgoingMessage(TSharedPtr<FROSBaseMsg> BaseMsg, bson_t** message) {

	auto PointField = StaticCastSharedPtr<ROSMessages::sensor_msgs::PointField>(BaseMsg);

	bson_init(*message);
	_bson_append_pointfield(*message, PointField.Get());
	
	return true;

}