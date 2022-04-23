#define _CRT_SECURE_NO_WARNINGS
/* Citation and Sources...
OOP244 Final Project
Module: Utils
Filename: Utils.cpp
Version 1.2
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 2020/07/25
Preliminary release: 2020/07/09
Revised History:
-First release
-Added "yes()" function
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Utils.h"
using namespace std;

namespace sdds {
	bool yes() {
		bool status = false;
		bool validInput = false;
		string input = "";

		do {

			cin >> input;

			if (input == "y" || input == "Y") {
				status = true;
				validInput = true;
			}
			else if (input == "n" || input == "N") {
				status = false;
				validInput = true;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				validInput = false;
			}
		} while (!validInput);

		return status;
	}

	void toUpperCase(char* c) {
		int i = 0;
		int len = strlen(c);
		
		for (i = 0; i < len; i++) {
			c[i] = toupper(c[i]);
		}
	}
}