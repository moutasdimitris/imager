#ifndef IMAGER_HPP_
#define IMAGER_HPP_

#include <string>
#include <iostream>

#include "ImagerPhantom.hpp"
#include "ImagerUnix.hpp"
#include "ImagerWin.hpp"
#include "ImagerMac.hpp"
#include "../structs/ImageInterface.hpp"

class Imager {
private:
	ImageInterface *imager;
	void getOsName();
public:
	Imager(std::string, std::string, bool);
	virtual ~Imager();
	int takeImage();
	int writeImage();
	int format(int);
	int makeBootable();
	int getClassType();
	void setBufferSize(int);
};

#endif /* IMAGER_HPP_ */
