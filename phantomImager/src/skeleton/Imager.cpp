#include "Imager.hpp"

Imager::Imager(std::string disk, std::string out, bool overwrite) {
	this->getOsName();
	if (this->imager != NULL) {
		this->imager->setDisk(disk);
		this->imager->setImgFile(out);
		this->imager->setOverwrite(overwrite);
	}
}

Imager::~Imager() {
	// TODO Auto-generated destructor stub
}

int Imager::takeImage() {
	return this->imager->takeImage();
}

int Imager::writeImage() {
	return this->imager->writeImage();
}

int Imager::format(int ch) {
	return this->imager->format(ch);
}

int Imager::getClassType() {
	return this->imager->getClassType();
}

void Imager::setBufferSize(int bs) {
	this->imager->setBufferSize(bs);
	return;
}

void Imager::getOsName() {
#ifdef _WIN32
		imager= new ImagerWin();
	#elif  _WIN64
		imager= new ImagerWin();
	#elif __APPLE__ || __MACH__
	imager = new ImagerMac();
#elif  __linux__
		imager= new ImagerUnix();
	#elif __FreeBSD__
		imager= new ImagerUnix();
	#elif __unix || __unix__
		imager= new ImagerUnix();
	#else
		imager= NULL;
	#endif
}

