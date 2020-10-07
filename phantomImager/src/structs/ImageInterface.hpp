#ifndef IMAGEINTERFACE_HPP_
#define IMAGEINTERFACE_HPP_
#include <filesystem>

class ImageInterface {
protected:
	std::string disk, imgFile;
	std::exception* ex;
	bool overwrite;
	int bufferSize;
	int fs;
public:
	ImageInterface() {
		overwrite = false;
		bufferSize = 128;
		fs = 1;
		ex= NULL;
	}
	virtual ~ImageInterface() {
	}
	virtual int takeImage() = 0;
	virtual int writeImage() = 0;
	virtual int format(int) = 0;
	virtual int getClassType()= 0;


	inline void setBufferSize(int bufferSize) {
		if (bufferSize > 0) {
			this->bufferSize = bufferSize;
		}
		return;
	}

	inline const std::string& getDisk() const {
		return disk;
	}

	inline void setDisk(const std::string &disk) {
		this->disk = disk;
	}

	inline const std::string& getImgFile() const {
		return imgFile;
	}

	inline void setImgFile(const std::string &out) {
		this->imgFile = out;
	}

	inline bool isOverwrite() const {
		return overwrite;
	}

	inline void setOverwrite(bool overwrite = false) {
		this->overwrite = overwrite;
	}

	inline std::exception*& getException()  {
		return ex;
	}

};

#endif /* IMAGEINTERFACE_HPP_ */
