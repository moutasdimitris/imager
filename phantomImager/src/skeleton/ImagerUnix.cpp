#include "ImagerUnix.hpp"

ImagerUnix::ImagerUnix() {
	// TODO Auto-generated constructor stub

}

ImagerUnix::~ImagerUnix() {
	// TODO Auto-generated destructor stub
}

int ImagerUnix::takeImage() {
	int result = 0;
	std::cout << "Taking image...\n";
	std::string str = "dd if=\"" + this->disk + "\" of=\"" + this->imgFile
			+ "\"  bs=" + std::to_string(this->bufferSize) + "K conv=sync";
	result = system(str.c_str());
	return result;
}

int ImagerUnix::writeImage() {
	int result = 0;
	std::cout << "Writing  image...\n";
	std::string str = "dd if=\"" + this->imgFile + "\" of=\"" + this->disk
			+ "\"  bs=" + std::to_string(this->bufferSize) + "K oflag=sync";
	result = system(str.c_str());
	return result;
}

int ImagerUnix::format(int ch) {
	int result = 0;
	std::string str = "";
	std::string unmount = "umount " + this->disk;
	std::string mount = "mount " + this->disk + " /mnt";
	std::cout << "Formatting the USB....\n";
	if (ch == 0) {
		str = "mkfs.ntfs " + this->disk;
	} else if (ch == 1) {
		str = "mkfs.vfat " + this->disk;
	} else {
		str = "mkfs.ext4 " + this->disk;
	}
	result = system(unmount.c_str());
	if (result == 0) {
		result = system(str.c_str()); /* For MS Dos os make "mkfs.vfat"(FAT 32/64). */
		if (result == 0)
			result = system(mount.c_str());
	}
	return result;
}

