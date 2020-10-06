#include "ImagerMac.hpp"

ImagerMac::ImagerMac() {
	// TODO Auto-generated constructor stub

}

ImagerMac::~ImagerMac() {
	// TODO Auto-generated destructor stub
}

int ImagerMac::takeImage() {
	int result = 0;
	std::cout << "Taking  image...\n";
	std::string str = "dd if=\"" + this->disk + "\" of=\"" + this->imgFile
			+ "\"  bs=" + std::to_string(this->bufferSize) + "m conv=sync";
	std::string str1 = "diskutil unmountDisk " + this->disk;
	try {
		system(str1.c_str());
		system(str.c_str());
		result = 1;
	} catch (std::exception &e) {
		std::cout << "'takeImage' throwed: " << e.what() << '\n';
	}
	return result;
}

int ImagerMac::writeImage() {
	int result = 0;
	std::cout << "Writing  image...\n";
	std::string str = "dd if=\"" + this->imgFile + "\" of=\"" + this->disk
			+ "\"  bs=" + std::to_string(this->bufferSize) + "m conv=sync";
	std::string str1 = "diskutil unmountDisk " + this->disk;
	//this->ex= NULL;
	try {
		system(str1.c_str());
		system(str.c_str());
		result = 1;
	} catch (std::exception &e) {
		std::cout << "'writingeImage' throwed: " << e.what() << '\n';
		//this->ex= e;
	}
	return result;
}

int ImagerMac::format(int ch) {
	int result = 0;
	std::cout << "Formatting the USB....\n";
	std::string str = "diskutil unmountDisk " + this->disk;
	std::string str1 = "diskutil eraseDisk ExFAT Drive " + this->disk;
	//this->ex= NULL;
	try {
		result= system(str.c_str());
	} catch (std::exception &e) {
		std::cout << "formattingUSB throwed: " << e.what() << "\n";
		//this->ex= e;
	}
	if (this->ex== NULL){
		try {
			result= system(str1.c_str());
		} catch (std::exception &e) {
			std::cout << "formattingUSB throwed: " << e.what() << "\n";
			//this->ex= e;
		}
	}
	return result;
}

int ImagerMac::makeBootable() {
	return 0;
}

