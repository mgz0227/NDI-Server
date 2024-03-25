/*================================================================================================*/
/*
 *	Copyright 2014-2017, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**
 *  \file  AAX_IMIDINode.h
 *
 *	\brief Declaration of the base MIDI Node interface.
 *
 *	\author by Andriy Goshko
 */
/*================================================================================================*/
/// @cond ignore
#pragma once
#ifndef AAX_IMIDINODE_H
#define AAX_IMIDINODE_H
/// @endcond

#include "AAX.h"
#include "AAX_ITransport.h"

/** \brief Interface for accessing information in a MIDI node
 *	
 *	\details
 *	\hostimp
 *	
 *	\sa AAX_IComponentDescriptor::AddMIDINode
 */
class AAX_IMIDINode 
{
public:
	virtual	~AAX_IMIDINode() {}

	/** \brief Returns a MIDI stream data structure
	 *
	 *	
	 */
	virtual AAX_CMidiStream*		GetNodeBuffer () = 0;
	
	/** \brief Posts an \ref AAX_CMidiPacket to an output MIDI node
	 *
	 *	\compatibility Pro Tools supports the following MIDI events from plug-ins:
	 *	- NoteOn
	 *	- NoteOff
	 *	- Pitch bend
	 *	- Polyphonic key pressure
	 *	- Bank select (controller #0)
	 *	- Program change (no bank)
	 *	- Channel pressure
	 *
	 *
	 *	\param[in] packet
	 *		The MIDI packet to be pushed to a MIDI output node
	 */
	virtual AAX_Result			PostMIDIPacket (AAX_CMidiPacket *packet) = 0;
	
	/** \brief Returns a transport object
	 * 
	 * \warning The returned interface is not versioned. Calling a method on this interface
	 * that is not supported by the host will result in undefined behavior, usually a crash.
	 * You must either check the host version before using this interface or limit the use
	 * of this interface to \ref AAX_IACFTransport "V1 Transport interface" methods.
	 * 
	 * Wherever possible, use a versioned Transport object such as the one created in
	 * \ref AAX_CEffectParameters::Initialize() rather than this unversioned interface.
	 */
	virtual AAX_ITransport*		GetTransport () = 0;
};


/// @cond ignore
#endif // AAX_IMIDINODE_H
/// @endcond
