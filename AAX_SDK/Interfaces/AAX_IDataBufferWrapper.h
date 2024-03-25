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
 * \file  AAX_IDataBufferWrapper.h
 */ 
/*================================================================================================*/

#pragma once
#ifndef AAX_IDATABUFFERWRAPPER_H
#define AAX_IDATABUFFERWRAPPER_H

#include "AAX.h"

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
class AAX_IDataBufferWrapper
{
public:
	virtual ~AAX_IDataBufferWrapper() = default;

	virtual AAX_Result Type(AAX_CTypeID * oType) const = 0; ///< \copydoc AAX_IDataBuffer::Type
	virtual AAX_Result Size(int32_t * oSize) const = 0; ///< \copydoc AAX_IDataBuffer::Size
	virtual AAX_Result Data(void const ** oBuffer) const = 0; ///< \copydoc AAX_IDataBuffer::Data
};

#endif // AAX_IDATABUFFERWRAPPER_H
