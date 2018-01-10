#include "Conversion/Messages/sensor_msgs/SensorMsgsChannelFloat32Converter.h"

#include "sensor_msgs/ChannelFloat32.h"


USensorMsgsChannelFloat32Converter::USensorMsgsChannelFloat32Converter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	_MessageType = "sensor_msgs/ChannelFloat32";
}

bool USensorMsgsChannelFloat32Converter::ConvertIncomingMessage(const ROSBridgePublishMsg* message, TSharedPtr<FROSBaseMsg> &BaseMsg) {
	return false;
}

bool USensorMsgsChannelFloat32Converter::ConvertOutgoingMessage(TSharedPtr<FROSBaseMsg> BaseMsg, bson_t** message) {

	auto ChannelFloat32 = StaticCastSharedPtr<ROSMessages::sensor_msgs::ChannelFloat32>(BaseMsg);

	assert(ChannelFloat32->values.Num() >= 1);

	bson_init(*message);
	BSON_APPEND_UTF8(*message, "name", TCHAR_TO_UTF8(*ChannelFloat32->name));
	_bson_append_float_tarray(*message, "values", ChannelFloat32->values);

	return true;

}