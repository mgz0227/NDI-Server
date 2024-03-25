/*================================================================================================*/
/*
 *	Copyright 2009-2015, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   AAX_Map.h
 *
 *	\author Mykola Kryvonos
 *
 */ 
/*================================================================================================*/

#pragma once

#ifndef AAX_MAP_H
#define AAX_MAP_H

#include "AAX.h"

#include AAX_ALIGN_FILE_BEGIN
#include AAX_ALIGN_FILE_ALG
#include AAX_ALIGN_FILE_END

//==============================================================================
class AAX_Map
{
public:
	AAX_Map() {};
	~AAX_Map() {};

	void SetCoefficients(int aSize, double* aInpX, double* aInpY);
	void GetCoefficient(int aIndex, double* aOutX, double* aOutY);
	int GetUpperBoundIndex(double inp);
	inline double GetX(int aIndex) {return mX[aIndex];};
	inline double GetY(int aIndex) {return mY[aIndex];};
	inline double GetFirstX() {return mX[0];};
	inline double GetFirstY() {return mY[0];};
	inline double GetLastX() {return mX[mSize - 1];};
	inline double GetLastY() {return mY[mSize - 1];};
	inline int GetSize() {return mSize;};

private:

	static const int mMaxSize = 13;

	int mSize;

	double mX[mMaxSize];
	double mY[mMaxSize];
};

#include AAX_ALIGN_FILE_BEGIN
#include AAX_ALIGN_FILE_RESET
#include AAX_ALIGN_FILE_END

#endif //AAX_MAP_H
