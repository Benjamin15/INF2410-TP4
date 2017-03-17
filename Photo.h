///////////////////////////////////////////////////////////
//  Photo.h
//  Implementation of the Class Photo
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_PHOTO_)
#define _HEADER_PHOTO_

class Photo
{
	int m_dimX, m_dimY;

public:
	Photo(int dimX, int dimY) { m_dimX = dimX; m_dimY = dimY; };
	virtual ~Photo() {};

	int getTaille(void) const { return m_dimX*m_dimY; }
};
#endif // !defined(_HEADER_PHOTO_)
