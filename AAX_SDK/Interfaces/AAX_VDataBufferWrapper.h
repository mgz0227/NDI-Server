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
 * \file  AAX_VDataBufferWrapper.h
 */ 
/*================================================================================================*/

#pragma once
#ifndef AAX_VDATABUFFERWRAPPER_H
#define AAX_VDATABUFFERWRAPPER_H

#include "AAX_IDataBufferWrapper.h"
#include "ACFPtr.h"

class IACFUnknown;
class AAX_IACFDataBuffer;

/**
 * \brief Wrapper for an \ref AAX_IDataBuffer
 * 
 * \details
 * Like \ref AAX_IController and similar classes, this class provides a non-ACF
 * interface matching an ACF interface, in this case \ref AAX_IACFDataBuffer .
 * 
 * The implementation of this interface will contain a reference counted pointer
 * to the underlying ACF interface. This interface may be extended with
 * convenience functions that are not required on the underlying ACF interface.
 */
class AAX_VDataBufferWrapper : public AAX_IDataBufferWrapper
{
public:
	explicit AAX_VDataBufferWrapper(IACFUnknown * iUnknown);
	~AAX_VDataBufferWrapper() AAX_OVERRIDE;

	AAX_Result Type(AAX_CTypeID * oType) const AAX_OVERRIDE; ///< \copydoc AAX_IDataBuffer::Type
	AAX_Result Size(int32_t * oSize) const AAX_OVERRIDE; ///< \copydoc AAX_IDataBuffer::Size
	AAX_Result Data(void const ** oBuffer) const AAX_OVERRIDE; ///< \copydoc AAX_IDataBuffer::Data

private:
	ACFPtr<AAX_IACFDataBuffer> mDataBufferV1;
};

#endif // AAX_VDATABUFFERWRAPPER_H