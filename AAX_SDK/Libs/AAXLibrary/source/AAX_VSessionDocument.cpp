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
/*================================================================================================*/

#include "AAX_VSessionDocument.h"
#include "AAX_VDataBufferWrapper.h"
#include "AAX_IACFSessionDocument.h"
#include "AAX_Assert.h"
#include "acfunknown.h"
#include "acfextras.h"


//---------------------------------------------------------------------------------
#if 0
#pragma mark - AAX_VSessionDocument::VTempoMap
#endif
//---------------------------------------------------------------------------------

AAX_VSessionDocument::VTempoMap::~VTempoMap() = default;

AAX_VSessionDocument::VTempoMap::VTempoMap(IACFUnknown & inDataBuffer)
: mDataBuffer{std::make_unique<AAX_VDataBufferWrapper const>(&inDataBuffer)}
{
	AAX_CTypeID dataType{0};
	if ((AAX_SUCCESS != mDataBuffer->Type(&dataType)) || (kAAX_DataBufferType_TempoBreakpointArray != dataType)) {
		AAX_ASSERT(false);
		mDataBuffer = nullptr; // can't use this data
	}
}

int32_t AAX_VSessionDocument::VTempoMap::Size() const
{
	int32_t numBytes{0};
	if (!mDataBuffer || (AAX_SUCCESS != mDataBuffer->Size(&numBytes))) {
		return 0;
	}
	AAX_ASSERT(0 == numBytes % static_cast<decltype(numBytes)>(sizeof(AAX_CTempoBreakpoint)));
	return numBytes / static_cast<decltype(numBytes)>(sizeof(AAX_CTempoBreakpoint));
}

AAX_CTempoBreakpoint const * AAX_VSessionDocument::VTempoMap::Data() const
{
	void const * buffer{nullptr};
	if (!mDataBuffer || (AAX_SUCCESS != mDataBuffer->Data(&buffer))) {
		return nullptr;
	}
	return reinterpret_cast<AAX_CTempoBreakpoint const *>(buffer);
}


//---------------------------------------------------------------------------------
#if 0
#pragma mark - AAX_VSessionDocument
#endif
//---------------------------------------------------------------------------------

AAX_VSessionDocument::AAX_VSessionDocument(IACFUnknown * iUnknown)
{
	if (iUnknown) {
		iUnknown->QueryInterface(IID_IAAXSessionDocumentV1, (void **)&mSessionDocumentV1);
	}
}

AAX_VSessionDocument::~AAX_VSessionDocument() = default;

void AAX_VSessionDocument::Clear()
{
	mSessionDocumentV1 = nullptr;
}

bool AAX_VSessionDocument::Valid() const
{
	return (nullptr != mSessionDocumentV1);
}

std::unique_ptr<AAX_ISessionDocument::TempoMap const> AAX_VSessionDocument::GetTempoMap()
{
	if (!mSessionDocumentV1) {
		return nullptr;
	}
	IACFUnknown * unk = nullptr;
	if (AAX_SUCCESS != this->GetDocumentData(AAX_DocumentDataType_TempoMap, &unk)) {
		return nullptr;
	}
	if (!unk) {
		return nullptr;
	}
	return std::make_unique<VTempoMap const>(*unk);
}

AAX_Result AAX_VSessionDocument::GetDocumentData(AAX_DocumentData_UID const & inDataType, IACFUnknown ** outData)
{
	if (mSessionDocumentV1) {
		return mSessionDocumentV1->GetDocumentData(inDataType, outData);
	}
	return AAX_ERROR_NULL_OBJECT;
}
