// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Conversion/Messages/BaseMessageConverter.h"
#include "geometry_msgs/Point32.h"
#include "GeometryMsgsPoint32Converter.generated.h"


UCLASS()
class ROSINTEGRATION_API UGeometryMsgsPoint32Converter: public UBaseMessageConverter
{
	GENERATED_UCLASS_BODY()

public:
	virtual bool ConvertIncomingMessage(const ROSBridgePublishMsg* message, TSharedPtr<FROSBaseMsg> &BaseMsg);
	virtual bool ConvertOutgoingMessage(TSharedPtr<FROSBaseMsg> BaseMsg, bson_t** message);


	// Helper function to append a ROSMessages::geometry_msgs::Point32 to an initialized bson_t
	static void _bson_append_point32(bson_t *b, ROSMessages::geometry_msgs::Point32 *p32)
	{
		BSON_APPEND_DOUBLE(b, "x", p32->x);
		BSON_APPEND_DOUBLE(b, "y", p32->y);
		BSON_APPEND_DOUBLE(b, "z", p32->z);
	}


	// Helper function to append a TArray<ROSMessages::geometry_msgs::Point32> to an initialized bson_t
	static void _bson_append_point32_tarray(bson_t *b, const char *key, TArray<ROSMessages::geometry_msgs::Point32> tarray)
	{
		bson_t arr;
		const char *element_key;
		char str[16];
		BSON_APPEND_ARRAY_BEGIN(b, key, &arr);
		for (int i = 0; i != tarray.Num(); ++i)
		{
			bson_uint32_to_string(i, &element_key, str, sizeof str);
			_bson_append_point32(b, &(tarray[i]));
		}
		bson_append_array_end(b, &arr);
	}

};

