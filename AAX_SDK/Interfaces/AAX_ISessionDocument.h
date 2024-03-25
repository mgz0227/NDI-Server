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
 *	\file   AAX_ISessionDocument.h
 */ 
/*================================================================================================*/

#pragma once
#ifndef AAX_ISessionDocument_H
#define AAX_ISessionDocument_H

#include "AAX_SessionDocumentTypes.h"
#include "AAX_UIDs.h"
#include "AAX.h"
#include <memory>

class IACFUnknown;

/**
 * \brief Interface representing information in a host session document
 * 
 * This interface wraps the versioned interfaces defined in
 * \ref AAX_IACFSessionDocument.h and provides additional convenience
 * functions providing session data back in the expected format.
 *
 * \sa \ref AAX_ISessionDocumentClient
 */
class AAX_ISessionDocument
{
public:
	virtual ~AAX_ISessionDocument() = default;

	class TempoMap
	{
	public:
		virtual ~TempoMap() = default;
		virtual int32_t Size() const = 0;
		virtual AAX_CTempoBreakpoint const * Data() const = 0;
	};

	/**
	 * \brief Check whether this session document is valid
	 */
	virtual bool Valid() const = 0;

	/**
	 * \brief Get a copy of the document's tempo map
	 * 
	 * \return A TempoMap interface representing a copy of the current
	 * tempo map.
	 * \return \c nullptr if the host does not support tempo map data or if
	 * an error occurred.
	 */
	virtual std::unique_ptr<TempoMap const> GetTempoMap() = 0;

	/** Get document data of a generic type
	 * 
	 * Similar to \c QueryInterface() but uses a data type identifier rather
	 * than a true IID
	 * 
	 * The provided interface has already had a reference added, so be careful
	 * not to add an additional reference:
	 * 
	 * \code
	 * ACFPtr<MyType> ptr;
	 * IACFUnknown * docDataPtr{nullptr};
	 * if (AAX_SUCCESS == doc->GetDocumentData(dataUID, &docDataPtr) && docDataPtr) {
	 *   ptr.attach(std::static_cast<MyType*>(docDataPtr)); // attach does not AddRef
	 * }
	 * \endcode
	 * 
	 * 
	 * \param[in] inDataType
	 * The type of the document data requested
	 * 
	 * \param[out] outData
	 * An interface providing the requested data, or \c nullptr if the host
	 * does not support or cannot provide the requested data type. The
	 * reference count has been incremented on this object on behalf of the
	 * caller, so the caller must not add an additional reference
	 * count and must decrement the reference count on this object to
	 * release it. For information about which interface to expect for each
	 * requested data type, see the documentation for that data type.
	 */
	virtual AAX_Result GetDocumentData(AAX_DocumentData_UID const & inDataType, IACFUnknown ** outData) = 0;
};

#endif // AAX_ISessionDocument_H
