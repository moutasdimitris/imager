#ifndef SKELETON_IMAGERWIN_HPP_
#define SKELETON_IMAGERWIN_HPP_

#include <string>
#include <iostream>

#include "../structs/ImageInterface.hpp"

class ImagerWin: public ImageInterface {
	friend class ImageInterface;
public:
	ImagerWin();
	virtual ~ImagerWin();
	int takeImage();
	int writeImage();
	int format(int);
	int makeBootable();
	inline int getClassType() {
		return 2;
	}
};

#endif /* SKELETON_IMAGERWIN_HPP_ */
