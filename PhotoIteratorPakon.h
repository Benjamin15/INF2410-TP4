///////////////////////////////////////////////////////////
//  PhotoIteratorPakon.h
//  Implementation of the Class PhotoIteratorPakon
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_PHOTO_ITERATOR_PAKON_)
#define _HEADER_PHOTO_ITERATOR_PAKON_

#include "PhotoIterator.h"

#include<list>
#include <memory>

typedef typename std::list<std::shared_ptr<Photo>>::const_iterator PakonContainerPhotoIterator;

class PhotoIteratorPakon : public PhotoIterator
{
	std::list<std::shared_ptr<Photo>>::const_iterator m_iterator;

public:
	friend bool operator==(const PhotoIteratorPakon& mdg, const PhotoIteratorPakon& mdd);
	friend bool operator!=(const PhotoIteratorPakon& mdg, const PhotoIteratorPakon& mdd);

	PhotoIteratorPakon(const std::list<std::shared_ptr<Photo>>::const_iterator& iter);
	virtual ~PhotoIteratorPakon() {};

	virtual void incremente(void);
	virtual const Photo& get(void) const;
};
#endif // !defined(_HEADER_PHOTO_ITERATOR_PAKON_)
#pragma once
