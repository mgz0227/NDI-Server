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
 *	\file  AAX_IACFTransportControl.h
 *
 *	\brief Interface for control over the host's transport state
 */ 
/*================================================================================================*/

#ifndef AAX_IACFTRANSPORTCONTROL_H
#define AAX_IACFTRANSPORTCONTROL_H

#pragma once

#include "AAX.h"
#include "AAX_Enums.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include "acfunknown.h"

/**	\brief Versioned interface to control the host's transport state
 */
class AAX_IACFTransportControl : public IACFUnknown
{
public:

	virtual AAX_Result RequestTransportStart() = 0;	///< \copydoc AAX_ITransport::RequestTransportStart()
	virtual AAX_Result RequestTransportStop() = 0;	///< \copydoc AAX_ITransport::RequestTransportStop()

};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // AAX_IACFTRANSPORTCONTROL_H

