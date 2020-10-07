#ifndef SKELETON_IMAGERUNIX_HPP_
#define SKELETON_IMAGERUNIX_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include <exception>

#include "../structs/ImageInterface.hpp"

class ImagerUnix: public ImageInterface {
	friend class ImageInterface;
public:
	ImagerUnix();
	virtual ~ImagerUnix();
	int takeImage();
	int writeImage();
	int format(int);
	inline int getClassType() {
		return 1;
	}
};

#endif /* SKELETON_IMAGERUNIX_HPP_ */
