#include "ImagerWin.hpp"
#include <cstring>

ImagerWin::ImagerWin() {
	// TODO Auto-generated constructor stub

}

ImagerWin::~ImagerWin() {
	// TODO Auto-generated destructor stub
}

int ImagerWin::takeImage() {
	int result = 0;
	std::cout << "Taking  image...\n";
	std::string str = "dism /Capture-Image /ImageFile:\"" + this->imgFile
			+ "\" /CaptureDir:" + this->disk + " /Name:MyData";
	this->ex= NULL;
	try {
		result= system(str.c_str());
	} catch (std::exception &e) {
		std::cout << "'takeImage' throwed: " << e.what() << '\n';
		this->ex= &e;
	}
	return result;
}

int ImagerWin::writeImage() {
	int result = 0;
	std::cout << "Writing  image...\n";
	std::string str = "dism /mount-wim /wimfile:\"" + this->imgFile
			+ "\" /Index:1 /mountdir:" + this->disk + "Data";
	std::string str1 = "md " + this->disk + "\\Data";
	this->ex= NULL;
	try {
		result=system(str1.c_str());
		if (result== 0){
			result= system(str.c_str());
		}
	} catch (std::exception &e) {
		std::cout << "'writeImage' throwed: " << e.what() << '\n';
		this->ex= &e;
	}
	return result;
}

int ImagerWin::format(int ch) {
	int result = 0;
	std::string str = "";
	std::cout << "Formatting the USB....\n";
	std::string disk= this->disk.c_str();
	char s=this->disk[0];
	std::string j(1, s);
	this->ex= NULL;
	try {
		if (ch == 0) {
			str = "format /fs:ntfs " + j+ ":";
		} else if (ch== 1){
			str = "format /fs:Fat32 " + j + ":";
		}else{
			str = "format /fs:Ext4 " + j + ":";
		}
		result=system(str.c_str());
	} catch (std::exception &e) {
		std::cout << "'formattingImage' throwed: " << e.what() << '\n';
		this->ex= &e;
	}
	return result;
}


