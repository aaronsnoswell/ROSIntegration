#include "Conversion/Messages/sensor_msgs/SensorMsgsPointFieldConverter.h"

#include "PointField.h"


USensorMsgsPointFieldConverter::USensorMsgsPointFieldConverter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	_MessageType = "sensor_msgs/PointField";
}

bool USensorMsgsPointFieldConverter::ConvertIncomingMessage(const ROSBridgePublishMsg* message, TSharedPtr<FROSBaseMsg> &BaseMsg) {
	bool KeyFound = false;

	FString name = GetFStringFromBSON(TEXT("msg.name"), message->full_msg_bson_, KeyFound);
	if (!KeyFound) return false;

	int32 offset = GetInt32FromBSON(TEXT("msg.offset"), message->full_msg_bson_, KeyFound);
	if (!KeyFound) return false;

	int32 _datatype = GetInt32FromBSON(TEXT("msg.datatype"), message->full_msg_bson_, KeyFound);
	if (!KeyFound) return false;
	ROSMessages::sensor_msgs::PointField::EDataType datatype = (ROSMessages::sensor_msgs::PointField::EDataType)_datatype;

	int32 count = GetInt32FromBSON(TEXT("msg.count"), message->full_msg_bson_, KeyFound);
	if (!KeyFound) return false;

	BaseMsg = TSharedPtr<FROSBaseMsg>(new ROSMessages::sensor_msgs::PointField(name, offset, datatype, count));
	return true;
}

bool USensorMsgsPointFieldConverter::ConvertOutgoingMessage(TSharedPtr<FROSBaseMsg> BaseMsg, bson_t** message) {

	auto PointField = StaticCastSharedPtr<ROSMessages::sensor_msgs::PointField>(BaseMsg);

	bson_init(*message);
	_bson_append_pointfield(*message, PointField.Get());
	
	return true;

}