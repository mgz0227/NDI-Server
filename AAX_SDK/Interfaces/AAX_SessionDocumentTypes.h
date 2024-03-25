/*================================================================================================*/
/*
 *
 *	Copyright 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file   AAX_SessionDocumentTypes.h
 */ 
/*================================================================================================*/

#pragma once
#ifndef AAX_SessionDocumentTypes_H
#define AAX_SessionDocumentTypes_H

#include "AAX.h"
#include <stdint.h>

AAX_CONSTEXPR AAX_CTypeID kAAX_DataBufferType_TempoBreakpointArray = 'AXtB';

#include AAX_ALIGN_FILE_BEGIN
#include AAX_ALIGN_FILE_HOST
#include AAX_ALIGN_FILE_END

struct AAX_CTempoBreakpoint
{
	int64_t mSampleLocation{0};
	float mValue{0.f};
};
static_assert(16 == sizeof(AAX_CTempoBreakpoint), "Unexpected size for AAX_CTempoBreakpoint");

#include AAX_ALIGN_FILE_BEGIN
#include AAX_ALIGN_FILE_RESET
#include AAX_ALIGN_FILE_END

#endif // AAX_SessionDocumentTypes_H
