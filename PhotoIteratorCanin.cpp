#include "PhotoIteratorCanin.h"

bool operator==(const PhotoIteratorCanin& mdg, const PhotoIteratorCanin& mdd)
{
	return (mdg.m_iterator == mdd.m_iterator);
}

bool operator!=(const PhotoIteratorCanin& mdg, const PhotoIteratorCanin& mdd)
{
	return ! (mdg == mdd);
}

PhotoIteratorCanin::PhotoIteratorCanin(const std::vector<std::shared_ptr<Photo>>::const_iterator& iter)
	: m_iterator(iter) 
{
}

void PhotoIteratorCanin::incremente(void) 
{ 
	m_iterator++; 
};

const Photo& PhotoIteratorCanin::get(void) const
{
	return *((*m_iterator).get());
};
