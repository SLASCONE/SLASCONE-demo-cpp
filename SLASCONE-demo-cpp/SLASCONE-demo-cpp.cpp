// SLASCONE-demo-cpp.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "SLASCONE-demo-cpp.h"
#include "Helper.h"
#include "LicenseXmlHelper.h"

using namespace std;
using namespace SLASCONE_demo_cpp;

int main(int argc, const char *argv[])
{
    Helper helper;
    string input;

    cout << "Slascone client app example" << endl;
    cout << "===========================" << endl << endl;
    cout << "Unique Client-Id for this device: " << helper.get_device_id() << endl;
    cout << "Operating system: " << helper.get_os_name() << endl;

    while (true)
    {
        cout << endl;
        cout << "-- MAIN" << endl;
        cout << "    1: Activate license (can be done only once per device)" << endl;
        cout << "    2: Add license heartbeat" << endl;
        cout << "    3: Temporary disconnection: Read local license file (only available after at least one license heartbeat)" << endl;
        cout << "    4: Unassign license from device (has to be activated again then)" << endl;
        cout << "-- ANALYTICS" << endl;
        cout << "    5: Add analytical heartbeat" << endl;
        cout << "    6: Add usage heart beat" << endl;
        cout << "    7: Add consumption heartbeat" << endl;
        cout << "-- FLOATING" << endl;
        cout << "    8: Open session" << endl;
        cout << "    9: Find open session (temporary disconnection)" << endl;
        cout << "    10: Close session" << endl;
        cout << "-- OFFLINE LICENSE" << endl;
        cout << "    11: Validate license file (signature check)" << endl;
        cout << "    12: Read license file" << endl;
        cout << "x: Exit" << endl << "> ";
        cin >> input;

        if (input == "x")
        {
            break;
        }
        
		if (input == "1")
        {
            // Activate license
            cout << "-- Activating license..." << endl;
			helper.activate_license();
        }
        else if (input == "2")
        {
            // Add license heartbeat
            cout << "-- Adding license heartbeat..." << endl;
			helper.send_license_heartbeat();
        }
        else if (input == "3")
        {
            // Read local license file
            cout << "-- Reading local license file..." << endl;
            helper.find_temp_offline_license();
        }
        else if (input == "4")
        {
            // Unassign license from device
            cout << "-- Unassigning license from device..." << endl;
			helper.unassign_token();
        }
        else if (input == "5")
        {
            // Add analytical heartbeat
            cout << "-- Adding analytical heartbeat..." << endl;
            // Add your code here
			cout << "Not implemented yet." << endl;
        }
        else if (input == "6")
        {
            // Add usage heart beat
            cout << "-- Adding usage heartbeat..." << endl;
            // Add your code here
			cout << "Not implemented yet." << endl;
        }
        else if (input == "7")
        {
            // Add consumption heartbeat
            cout << "-- Adding consumption heartbeat..." << endl;
            // Add your code here
			cout << "Not implemented yet." << endl;
        }
        else if (input == "8")
        {
            // Open session
            cout << "-- Opening session..." << endl;
			helper.open_session();
        }
        else if (input == "9")
        {
            // Find open session
            cout << "-- Finding open session..." << endl;
            helper.find_open_session();
        }
        else if (input == "10")
        {
            // Close session
            cout << "-- Closing session..." << endl;
			helper.close_session();
        }
        else if (input == "11")
        {
            // Validate license file
            cout << "-- Validating license file..." << endl;
            helper.verify_file("/workspaces/SLASCONE-demo-cpp/Assets/License-91fad880-90c4-46cb-8d8b-0a12445c6f0e.xml");
            // Validate manipulated license file
            cout << "-- Validating manipulated license file..." << endl;
            helper.verify_file("/workspaces/SLASCONE-demo-cpp/Assets/License-91fad880-90c4-46cb-8d8b-0a12445c6f0e_scam.xml");
            // Validate activation file
            cout << "-- Validating activation file..." << endl;
            helper.verify_file("/workspaces/SLASCONE-demo-cpp/Assets/ActivationFile.xml");
        }
        else if (input == "12")
        {
            // Read license file
            cout << "Reading license file..." << endl;
			LicenseXmlHelper::print_license_infos("/workspaces/SLASCONE-demo-cpp/Assets/License-91fad880-90c4-46cb-8d8b-0a12445c6f0e.xml");
        }
    }
    return 0;
}
