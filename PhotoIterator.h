///////////////////////////////////////////////////////////
//  PhotoIterator.h
//  Implementation of the Class PhotoIterator
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_PHOTO_ITERATOR_)
#define _HEADER_PHOTO_ITERATOR_

#include "Photo.h"

class PhotoIterator
{
public:
	PhotoIterator(void) {};
	virtual ~PhotoIterator() {};

	virtual void incremente(void) = 0;
	virtual const Photo& get(void) const = 0;
};
#endif // !defined(_HEADER_PHOTO_ITERATOR_)
#pragma once
