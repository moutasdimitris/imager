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
	this->ex= NULL;
	try {
		system(str1.c_str());
		system(str.c_str());
		result = 1;
	} catch (std::exception &e) {
		std::cout << "'takeImage' throwed: " << e.what() << '\n';
		this->ex= &e;
	}
	return result;
}

int ImagerMac::writeImage() {
	int result = 0;
	std::cout << "Writing  image...\n";
	std::string str = "dd if=\"" + this->imgFile + "\" of=\"" + this->disk
			+ "\"  bs=" + std::to_string(this->bufferSize) + "m conv=sync";
	std::string str1 = "diskutil unmountDisk " + this->disk;
	this->ex= NULL;
	try {
		system(str1.c_str());
		system(str.c_str());
		result = 1;
	} catch (std::exception &e) {
		std::cout << "'writingeImage' throwed: " << e.what() << '\n';
		this->ex= &e;
	}
	return result;
}

int ImagerMac::format(int ch) {
	int result = 0;
	std::cout << "Formatting the USB....\n";
	std::string str = "";
	this->ex= NULL;
	try {
		if (ch== 0){
			str= "diskutil eraseDisk APFS drive " + this->disk;
		}else if (ch== 1){
			str= "diskutil eraseDisk HFS+ drive " + this->disk;
		}else{
			str= "diskutil eraseDisk ExFat drive " + this->disk;
		}
		result= system(str.c_str());
	}catch (std::exception &e) {
		std::cout << "formattingUSB throwed: " << e.what() << "\n";
		this->ex= &e;
	}
	return result;
}

int ImagerMac::makeBootable() {
	return 0;
}

