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

	Helper helper;

	string input;

	while (true) {
		cout << "Menu Options:" << endl;
		cout << "1: Validate offline license file signature" << endl;
		cout << "2: Print license infos" << endl;
		cout << "3: Option 3" << endl;
		cout << "x: Exit" << endl;
		cout << "> ";
		cin >> input;

		if (input == "x") {
			break;
		}

		if (input == "1") {
			helper.verify_file("/workspaces/SLASCONE-demo-cpp/Assets/License-91fad880-90c4-46cb-8d8b-0a12445c6f0e.xml");
		}
		else if (input == "2") {
			cout << "Option 2 selected" << endl;
			// Call method for Option 2
		}
		else if (input == "3") {
			cout << "Option 3 selected" << endl;
			// Call method for Option 3
		}
		else {
			cout << "Invalid choice, please try again." << endl;
		}
	}
	return 0;
}
