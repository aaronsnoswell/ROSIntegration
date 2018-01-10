#include "Conversion/Messages/sensor_msgs/SensorMsgsPointFieldConverter.h"



USensorMsgsPointFieldConverter::USensorMsgsPointFieldConverter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	_MessageType = "sensor_msgs/PointField";
}

bool USensorMsgsPointFieldConverter::ConvertIncomingMessage(const ROSBridgePublishMsg* message, TSharedPtr<FROSBaseMsg> &BaseMsg) {
	return false;
}

bool USensorMsgsPointFieldConverter::ConvertOutgoingMessage(TSharedPtr<FROSBaseMsg> BaseMsg, bson_t** message) {

	auto PointField = StaticCastSharedPtr<ROSMessages::sensor_msgs::PointField>(BaseMsg);

	bson_init(*message);
	_bson_append_pointfield(*message, PointField.Get());

	/*
	*message = BCON_NEW(
		"name", BCON_UTF8(TCHAR_TO_UTF8(*PointField->name)),
		"offset", BCON_INT32(PointField->offset),
		"datatype", BCON_INT32((uint8)(PointField->datatype)),
		"count", BCON_INT32(PointField->count)
	);
	*/
	
	return true;

}