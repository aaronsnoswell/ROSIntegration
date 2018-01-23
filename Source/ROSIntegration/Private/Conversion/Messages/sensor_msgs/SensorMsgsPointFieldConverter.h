// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Conversion/Messages/BaseMessageConverter.h"
#include "sensor_msgs/PointField.h"
#include "SensorMsgsPointFieldConverter.generated.h"


UCLASS()
class ROSINTEGRATION_API USensorMsgsPointFieldConverter: public UBaseMessageConverter
{
	GENERATED_UCLASS_BODY()

public:
	virtual bool ConvertIncomingMessage(const ROSBridgePublishMsg* message, TSharedPtr<FROSBaseMsg> &BaseMsg);
	virtual bool ConvertOutgoingMessage(TSharedPtr<FROSBaseMsg> BaseMsg, bson_t** message);


	// Helper function to append a ROSMessages::sensor_msgs::PointField to an initialized bson_t
	static void _bson_append_pointfield(bson_t *b, ROSMessages::sensor_msgs::PointField *pf)
	{
		BSON_APPEND_UTF8(b, "name", TCHAR_TO_UTF8(*pf->_name));
		BSON_APPEND_INT32(b, "offset", pf->_offset);
		BSON_APPEND_INT32(b, "datatype", (uint8)(pf->_datatype));
		BSON_APPEND_INT32(b, "count", pf->_count);
	}


	// Helper function to append a TArray<ROSMessages::sensor_msgs::PointField> to an initialized bson_t
	static void _bson_append_pointfield_tarray(bson_t *b, const char *key, TArray<ROSMessages::sensor_msgs::PointField> tarray)
	{
		bson_t arr;
		const char *element_key;
		char str[16];
		BSON_APPEND_ARRAY_BEGIN(b, key, &arr);
		for (int i = 0; i != tarray.Num(); ++i)
		{
			bson_uint32_to_string(i, &element_key, str, sizeof str);
			_bson_append_pointfield(b, &(tarray[i]));
		}
		bson_append_array_end(b, &arr);
	}

};

