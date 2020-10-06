#ifndef SKELETON_IMAGERPHANTOM_HPP_
#define SKELETON_IMAGERPHANTOM_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "../structs/ImageInterface.hpp"

class ImagerPhantom: public ImageInterface {
	friend class ImageInterface;
public:
	ImagerPhantom();
	virtual ~ImagerPhantom();
	int takeImage();
	int writeImage();
	int format(int);
	int makeBootable();
	inline int getClassType() {
		return 0;
	}
};

#endif /* SKELETON_IMAGERPHANTOM_HPP_ */
