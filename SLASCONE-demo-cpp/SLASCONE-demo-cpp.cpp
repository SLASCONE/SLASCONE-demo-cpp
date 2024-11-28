// SLASCONE-demo-cpp.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "SLASCONE-demo-cpp.h"
#include "Helper.h"

using namespace std;
using namespace SLASCONE_demo_cpp;

int main(int argc, const char *argv[])
{
	Helper helper;
	string input;

	while (true)
	{
		cout << "Menu Options:" << endl;
		cout << "1: Send license heartbeat" << endl;
		cout << "2: Get license by ID" << endl;
		cout << "3: Validate offline license file signature" << endl;
		cout << "4: Print license infos" << endl;
		cout << "x: Exit" << endl;
		cout << "> ";
		cin >> input;

		if (input == "x")
		{
			break;
		}

		if (input == "1")
		{
			helper.send_heartbeat();
		}
		else if (input == "2")
		{
			helper.get_license_by_id();
		}
		else if (input == "3")
		{
			cout << "Verify the signature of a valid license file:" << endl;
			helper.verify_file("/workspaces/SLASCONE-demo-cpp/Assets/License-91fad880-90c4-46cb-8d8b-0a12445c6f0e.xml");

			cout << "Verify the signature of an invalid license file:" << endl;
			helper.verify_file("/workspaces/SLASCONE-demo-cpp/Assets/License-91fad880-90c4-46cb-8d8b-0a12445c6f0e_scam.xml");

			cout << "Verify the signature of a license avtivation file:" << endl;
			helper.verify_file("/workspaces/SLASCONE-demo-cpp/Assets/ActivationFile.xml");
		}
		else if (input == "4")
		{
			cout << "Option 4 selected" << endl;
			// Call method for Option 2
		}
		else 
		{
			cout << "Invalid choice, please try again." << endl;
		}
	}
	return 0;
}
