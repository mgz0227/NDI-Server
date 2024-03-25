/*================================================================================================*/
/*
 *
 * Copyright 2023 Avid Technology, Inc.
 * All rights reserved.
 * 
 * CONFIDENTIAL: this document contains confidential information of Avid. Do
 * not disclose to any third party. Use of the information contained in this
 * document is subject to an Avid SDK license.
 *
 */

/**  
 * \file  AAX_VDataBufferWrapper.cpp
 */ 
/*================================================================================================*/

#include "AAX_VDataBufferWrapper.h"

#include "AAX_IACFDataBuffer.h"
#include "AAX_UIDs.h"
#include "acfextras.h"

AAX_VDataBufferWrapper::AAX_VDataBufferWrapper(IACFUnknown * iUnknown)
{
	if (iUnknown) {
		iUnknown->QueryInterface(IID_IAAXDataBufferV1, (void **)&mDataBufferV1);
	}
}

AAX_VDataBufferWrapper::~AAX_VDataBufferWrapper() = default;

AAX_Result AAX_VDataBufferWrapper::Type(AAX_CTypeID * oType) const
{
	if (mDataBufferV1) {
		return mDataBufferV1->Type(oType);
	}
	return AAX_ERROR_NULL_OBJECT;
}

AAX_Result AAX_VDataBufferWrapper::Size(int32_t * oSize) const
{
	if (mDataBufferV1) {
		return mDataBufferV1->Size(oSize);
	}
	return AAX_ERROR_NULL_OBJECT;
}

AAX_Result AAX_VDataBufferWrapper::Data(void const ** oBuffer) const
{
	if (mDataBufferV1) {
		return mDataBufferV1->Data(oBuffer);
	}
	return AAX_ERROR_NULL_OBJECT;
}
