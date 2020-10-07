#include "ImagerMain.hpp"

int main(int argc, char **argv) {
	/* Get OS here. */
	/***
	 * Unix-based Systems
	 */
//	std::string disk= "/dev/sdd1";
//	std::string imgFile= "/home/dm/Desktop/ubuntu.iso";
	/***
	 * Windows paths
	 */
	std::string disk = "G:\\";
	std::string imgFile = "C:\\Users\\mouta\\Desktop\\img2.wim";

	/***
	 * MacOS paths
	 */
//	std::string disk= "/dev/rdisk2";
//	std::string out= "/Users/root1/Desktop/tom.iso";
	int result = 0;
	Imager *imager = NULL;
	try {
		std::cout << "Starting constructor.\n";
		imager = new Imager(disk, imgFile, true);
		imager->setBufferSize(512);
		std::cout << "Imager class type:'" << imager->getClassType() << "'\n";
	} catch (std::exception &e) {
		std::cout << "Constructor throwed: " << e.what() << '\n';
	}
	try {
		result = imager->takeImage();
		std::cout << "taking image result:'" << result << "'\n";
	} catch (std::exception &e) {
		std::cout << "takeImage throwed: " << e.what() << '\n';
	}
	try {
		int choice = 1;
		std::cout << "Select one:\n";
		std::cout << "0. NTFS or 1.Fat32/64 or 2.Ext4\n";
		std::cout << ">";
		std::cin >> choice;
		if (choice == 0) {
			result = imager->format(0);
		} else if (choice== 1){
			result = imager->format(1);
		}else if (choice== 2){
			result= imager->format(2);
		}
		std::cout << "formatting result:'" << result << "'\n";
	} catch (std::exception &e) {
		std::cout << "formattingUsb throwed: " << e.what() << '\n';
	}
	try {
		result = imager->writeImage();
		std::cout << "writing image result:'" << result << "'\n";
	} catch (std::exception &e) {
		std::cout << "writingImage throwed: " << e.what() << '\n';
	}
//		try {
//			result = imager->makeBootable();
//			std::cout << "makeBootable result:'" << result << "'\n";
//		} catch (std::exception &e) {
//			std::cout << "makeBootable throwed: " << e.what() << '\n';
//		}
	//system("PAUSE");
	delete (imager);
	return 0;
}

ImagerMain::ImagerMain() {
	// TODO Auto-generated constructor stub

}

ImagerMain::~ImagerMain() {
	// TODO Auto-generated destructor stub
}

