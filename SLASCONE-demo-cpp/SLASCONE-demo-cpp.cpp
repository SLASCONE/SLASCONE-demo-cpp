// SLASCONE-demo-cpp.cpp : Defines the entry point for the application.
//

#include "SLASCONE-demo-cpp.h"
#include "Helper.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace SLASCONE_demo_cpp;

int main(int argc, const char* argv[]) {

    // XML file to check must be provided as an argument
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <xml-file>" << std::endl;
        return -1;
    }

    Helper helper;

    /* Verify XML file */
	if (helper.verify_file(argv[1]) < 0) {
        return(-1);
    }

    return 0;
}
