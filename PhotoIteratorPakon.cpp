#include "PhotoIteratorPakon.h"

bool operator==(const PhotoIteratorPakon& mdg, const PhotoIteratorPakon& mdd)
{
	return (mdg.m_iterator == mdd.m_iterator);
}

bool operator!=(const PhotoIteratorPakon& mdg, const PhotoIteratorPakon& mdd)
{
	return ! (mdg == mdd);
}

PhotoIteratorPakon::PhotoIteratorPakon(const std::list<std::shared_ptr<Photo>>::const_iterator& iter)
	: m_iterator(iter) 
{
}

void PhotoIteratorPakon::incremente(void) 
{ 
	m_iterator++; 
};

const Photo& PhotoIteratorPakon::get(void) const
{
	return *((*m_iterator).get());
};
