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
 *	\file   AAX_IACFSessionDocument.h
 */ 
/*================================================================================================*/

#pragma once
#ifndef AAX_IACFSessionDocument_H
#define AAX_IACFSessionDocument_H

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include "AAX_UIDs.h"
#include "AAX.h"
#include "acfunknown.h"

/**
 * \brief Interface representing information in a host session document
 * 
 * Plug-in implementations should use \ref AAX_ISessionDocument , which
 * provides specific convenience methods for supported data types.
 */
class AAX_IACFSessionDocument : public IACFUnknown
{
public:
	/**
	 * \brief Get data from the document
	 * 
	 * \copydetails AAX_ISessionDocument::GetDocumentData
	 */
	virtual AAX_Result GetDocumentData(AAX_DocumentData_UID const & inDataType, IACFUnknown ** outData) = 0;
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // AAX_IACFSessionDocument_H
