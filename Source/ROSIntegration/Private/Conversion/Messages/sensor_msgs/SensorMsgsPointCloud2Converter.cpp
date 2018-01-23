#include "Conversion/Messages/sensor_msgs/SensorMsgsPointCloud2Converter.h"

#include "Conversion/Messages/std_msgs/StdMsgsHeaderConverter.h"
#include "Conversion/Messages/sensor_msgs/SensorMsgsPointFieldConverter.h"

#include "sensor_msgs/PointCloud2.h"


USensorMsgsPointCloud2Converter::USensorMsgsPointCloud2Converter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	_MessageType = "sensor_msgs/PointCloud2";
}

bool USensorMsgsPointCloud2Converter::ConvertIncomingMessage(const ROSBridgePublishMsg* message, TSharedPtr<FROSBaseMsg> &BaseMsg) {
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

	//UE_LOG(LogTemp, Warning, TEXT("ROSIntegration: PointCloud2 receiving not implemented yet"));
	//return false;
}

bool USensorMsgsPointCloud2Converter::ConvertOutgoingMessage(TSharedPtr<FROSBaseMsg> BaseMsg, bson_t** message) {

	auto PointCloud2 = StaticCastSharedPtr<ROSMessages::sensor_msgs::PointCloud2>(BaseMsg);

	assert(PointCloud2->fields.Num() >= 1);
	assert(PointCloud2->data.Num() >= 1);

	bson_init(*message);

	UStdMsgsHeaderConverter::_bson_append_child_header(*message, "header", &(PointCloud2->header));
	BSON_APPEND_INT32(*message, "height", PointCloud2->height);
	BSON_APPEND_INT32(*message, "width", PointCloud2->width);
	USensorMsgsPointFieldConverter::_bson_append_pointfield_tarray(*message, "fields", PointCloud2->fields);
	BSON_APPEND_BOOL(*message, "is_bigendian", PointCloud2->is_bigendian);
	BSON_APPEND_INT32(*message, "point_step", PointCloud2->point_step);
	BSON_APPEND_INT32(*message, "row_step", PointCloud2->row_step);
	_bson_append_uint8_tarray(*message, "data", PointCloud2->data);
	BSON_APPEND_BOOL(*message, "is_dense", PointCloud2->is_dense);
		
	return true;

}