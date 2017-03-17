///////////////////////////////////////////////////////////
//  PhotoIteratorCanin.h
//  Implementation of the Class PhotoIteratorCanin
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_PHOTO_ITERATOR_Canin_)
#define _HEADER_PHOTO_ITERATOR_Canin_

#include "PhotoIterator.h"

#include<vector>
#include <memory>

typedef typename std::vector<std::shared_ptr<Photo>>::const_iterator CaninContainerPhotoIterator;

class PhotoIteratorCanin : public PhotoIterator
{
	std::vector<std::shared_ptr<Photo>>::const_iterator m_iterator;

public:
	friend bool operator==(const PhotoIteratorCanin& mdg, const PhotoIteratorCanin& mdd);
	friend bool operator!=(const PhotoIteratorCanin& mdg, const PhotoIteratorCanin& mdd);

	PhotoIteratorCanin(const std::vector<std::shared_ptr<Photo>>::const_iterator& iter);
	virtual ~PhotoIteratorCanin() {};

	virtual void incremente(void);
	virtual const Photo& get(void) const;
};
#endif // !defined(_HEADER_PHOTO_ITERATOR_Canin_)
#pragma once
