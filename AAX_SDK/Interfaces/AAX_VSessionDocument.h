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
 *	\file   AAX_VSessionDocument.h
 */ 
/*================================================================================================*/

#pragma once
#ifndef AAX_VSessionDocument_H
#define AAX_VSessionDocument_H

#include "AAX_ISessionDocument.h"
#include "ACFPtr.h"

class AAX_IACFSessionDocument;
class AAX_IDataBufferWrapper;

class AAX_VSessionDocument : public AAX_ISessionDocument
{
public:
	explicit AAX_VSessionDocument(IACFUnknown * iUnknown);
	~AAX_VSessionDocument() AAX_OVERRIDE;

	class VTempoMap : public AAX_ISessionDocument::TempoMap
	{
	public:
		~VTempoMap() AAX_OVERRIDE;
		explicit VTempoMap(IACFUnknown & inDataBuffer);
		int32_t Size() const AAX_OVERRIDE;
		AAX_CTempoBreakpoint const * Data() const AAX_OVERRIDE;
	private:
		std::unique_ptr<AAX_IDataBufferWrapper const> mDataBuffer;
	};

	/** 
	 * \brief Release all interface references
	 */
	void Clear();

	bool Valid() const AAX_OVERRIDE;
	std::unique_ptr<AAX_ISessionDocument::TempoMap const> GetTempoMap() AAX_OVERRIDE;
	AAX_Result GetDocumentData(AAX_DocumentData_UID const & inDataType, IACFUnknown ** outData) AAX_OVERRIDE;

private:
	ACFPtr<AAX_IACFSessionDocument> mSessionDocumentV1;
};

#endif // AAX_VSessionDocument_H
