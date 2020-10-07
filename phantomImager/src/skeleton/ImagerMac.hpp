#ifndef SRC_SKELETON_IMAGERMAC_HPP_
#define SRC_SKELETON_IMAGERMAC_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include <exception>

#include "../structs/ImageInterface.hpp"

class ImagerMac: public ImageInterface {
	friend class ImageInterface;
public:
	ImagerMac();
	virtual ~ImagerMac();
	int takeImage();
	int writeImage();
	int format(int);
	inline int getClassType() {
		return 3;
	}
};

#endif /* SRC_SKELETON_IMAGERMAC_HPP_ */
