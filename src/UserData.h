/*
 * UserData.h
 *
 *  Created on: Nov 19, 2017
 *      Author: Henry
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifndef USERDATA_H_
#define USERDATA_H_

class UserData {
private:
	string firstName;
	string lastName;
	string userCed;
	string fullName;
	string newUser;
	const string sampleCed = "11-1111-1111";
	const string filename = "userData1.txt";
	bool salir;
	bool wrongCed;
	bool dupCed;
	bool salida;

public:
	string userRegistration();
	string getName();
	string pideCedula();
	bool validCed(string userCed, const string sampleCed);
	bool salirRegistro();
	bool findDupCed(const string filename);
	bool salirCed();
	bool getInvChars();
	bool identifyUser(const string filename);
	bool searchPlayer(string fileName, string playerId);
	void Option1();

};

#endif /* USERDATA_H_ */
