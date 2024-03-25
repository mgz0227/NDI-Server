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
 *	\file  AAX_ISessionDocumentClient.h
 */ 
/*================================================================================================*/

#pragma once
#ifndef AAX_ISessionDocumentClient_H
#define AAX_ISessionDocumentClient_H

#include "AAX_IACFSessionDocumentClient.h"
#include "AAX.h"
#include "CACFUnknown.h"


/**
 * \brief Interface representing a client of the session document interface
 * 
 * For example, a plug-in implementation that makes calls on the session
 * document interface provided by the host.
 */
class AAX_ISessionDocumentClient :	public AAX_IACFSessionDocumentClient,
									public CACFUnknown
{	
public:
	ACF_DECLARE_STANDARD_UNKNOWN()
	
	ACFMETHOD(InternalQueryInterface)(const acfIID & riid, void **ppvObjOut) override;
	
	// CACFUnknown does not support operator=()
	AAX_DELETE(AAX_ISessionDocumentClient& operator= (const AAX_ISessionDocumentClient&));
};

#endif //AAX_ISessionDocumentClient_H
