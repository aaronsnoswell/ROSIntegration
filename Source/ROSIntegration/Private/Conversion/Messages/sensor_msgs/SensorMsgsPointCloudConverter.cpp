#include "Conversion/Messages/sensor_msgs/SensorMsgsPointCloudConverter.h"

#include "Conversion/Messages/std_msgs/StdMsgsHeaderConverter.h"
#include "Conversion/Messages/geometry_msgs/GeometryMsgsPoint32Converter.h"
#include "Conversion/Messages/sensor_msgs/SensorMsgsChannelFloat32Converter.h"

#include "sensor_msgs/PointCloud.h"


USensorMsgsPointCloudConverter::USensorMsgsPointCloudConverter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	_MessageType = "sensor_msgs/PointCloud";
}

bool USensorMsgsPointCloudConverter::ConvertIncomingMessage(const ROSBridgePublishMsg* message, TSharedPtr<FROSBaseMsg> &BaseMsg) {
	return false;
}

bool USensorMsgsPointCloudConverter::ConvertOutgoingMessage(TSharedPtr<FROSBaseMsg> BaseMsg, bson_t** message) {

	auto PointCloud = StaticCastSharedPtr<ROSMessages::sensor_msgs::PointCloud>(BaseMsg);

	assert(PointCloud->points.Num() >= 1);
	assert(PointCloud->channels.Num() >= 1);

	bson_init(*message);

	UStdMsgsHeaderConverter::_bson_append_child_header(*message, "header", &(PointCloud->header));
	BSON_APPEND_INT32(*message, "seq", PointCloud->seq);
	BSON_APPEND_INT32(*message, "step", PointCloud->step);
	BSON_APPEND_UTF8(*message, "frame_id", TCHAR_TO_UTF8(*PointCloud->frame_id));
	UGeometryMsgsPoint32Converter::_bson_append_point32_tarray(*message, "points", PointCloud->points);
	USensorMsgsChannelFloat32Converter::_bson_append_channelfloat32_tarray(*message, "channels", PointCloud->channels);
	
	return true;

}