#include "Conversion/Messages/sensor_msgs/SensorMsgsChannelFloat32Converter.h"


USensorMsgsChannelFloat32Converter::USensorMsgsChannelFloat32Converter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	_MessageType = "sensor_msgs/ChannelFloat32";
}

bool USensorMsgsChannelFloat32Converter::ConvertIncomingMessage(const ROSBridgePublishMsg* message, TSharedPtr<FROSBaseMsg> &BaseMsg) {
	UE_LOG(LogTemp, Warning, TEXT("ROSIntegration: ChannelFloat32 receiving not implemented yet"));
	return false;
}

bool USensorMsgsChannelFloat32Converter::ConvertOutgoingMessage(TSharedPtr<FROSBaseMsg> BaseMsg, bson_t** message) {

	auto ChannelFloat32 = StaticCastSharedPtr<ROSMessages::sensor_msgs::ChannelFloat32>(BaseMsg);

	assert(ChannelFloat32->values.Num() >= 1);

	bson_init(*message);
	_bson_append_channelfloat32(*message, ChannelFloat32.Get());

	return true;

}