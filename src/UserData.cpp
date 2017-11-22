/*
 * UserData.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: Henry
 */

#include "UserData.h"
#include "Juego.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void UserData::Option1()
{
	bool cont =true;
	int temp = 1;
	while (cont == true){
		ofstream writeFile (filename, ios::out | ios::app);
		string newuser = userRegistration();
		writeFile << newuser << endl;
		writeFile.close();
		cout << endl;
		cout << "Desea Agregar Otro Jugador? " << endl;
		cout << "1- Si" << endl;
		cout << "2- No" << endl;
		cout << "Decision: " << flush;
		cin >> temp;
		while (temp <1 || temp > 2){
			cout << "Error: opciones disponibles 1 o 2" << endl;
			cout << "Decision: " << flush;
			cin >> temp;
		}
		if (temp == 1){
			cont = true;
		} else {
			cont = false;
		}
		cout << endl;
	}
}






string UserData::userRegistration()
{

	salir = false;
	while (salir == false){
		fullName = getName();
		userCed = pideCedula();
		wrongCed = validCed(userCed,sampleCed);
		dupCed =findDupCed(filename);
		while( (wrongCed == true)|| (dupCed == true) )
		{
			userCed = pideCedula();
			wrongCed = validCed(userCed,sampleCed);
			dupCed =findDupCed(filename);
		}
		newUser = userCed+' '+fullName;
		salir = true;
		}
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "Jugador registrado exitosamente......" << endl;
	return newUser;
}


















/*
string UserData::userRegistration()
{

	salir = false;
	while (salir == false){
		fullName = getName();
		userCed = pideCedula();
		wrongCed = validCed(userCed,sampleCed);
		dupCed =findDupCed(filename);
		while( (wrongCed == true)|| (dupCed == true) )
		{
			salida = salirCed();
			if(salida == true)
			{
				salir = salirRegistro();
				if(salir ==  true){
					break;
				}
				//return 0;
			}
			userCed = pideCedula();
			wrongCed = validCed(userCed,sampleCed);
			dupCed =findDupCed(filename);
		}
		salida = salir;
		if(salida == true){
		newUser = userCed+' '+fullName;
		salir = true;
		} else {
		newUser = userCed+' '+fullName;
		salir = false;
		}
	}
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "The end" << endl;
	return newUser;

}

*/
string UserData::getName()
{
	cout << "Escriba su nombre: ";
	cin >> firstName;
	cout << "Escriba su apellido: ";
	cin >> lastName;
	fullName = firstName+' '+lastName;
	return fullName;
}

string UserData::pideCedula()
{
	cout << endl;
	cout << "------------------------------INSTRUCCIONES-----------------------------" << endl;
	cout << "El numero de cedula usa el siguiente formato: 11-1111-1111" << endl;
	cout << "Si su cedula no contiene 10 digitos, agregue un cero '0' delante." << endl;
	cout << "Ejemplo ced 2-225-135 => 02-0225-0135." << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Ingrese el numero de cedula del jugador: " << flush;
	//string userCed;
	cin >> userCed;
	return userCed;
}

bool UserData::validCed(string userCed, const string sampleCed)
{
	size_t found = userCed.find_first_not_of("0123456789-"); // caracteres validos
	bool invChar = getInvChars();
	if (userCed.length() != sampleCed.length())  // primero valida si el largo de la palabra es igual al formato correcto
	{
		cout << "*********************************************************************************" << endl;
		cout << "Error #1: solo se permiten numeros y el caracter '-' " << endl;
		cout << "*********************************************************************************" << endl;
		return true;
	} else  if ( ( userCed.at(2) != sampleCed.at(2)  || userCed.at(7) != sampleCed.at(7) )) //luego valida que los  '-' esten es las posiciones correctas
	{
		cout << "*********************************************************************************" << endl;
		cout << "Error #2: valide la posicion del caracter '-' " << endl;
		cout << "*********************************************************************************" << endl;
		return true;
		// valida que el caracter '-' no ocupe el espacio correspondiente a numero
	}  else if ( ((userCed.at(0) == sampleCed.at(2)) || (userCed.at(0) == sampleCed.at(7))) ||
			((userCed.at(1) == sampleCed.at(2)) || (userCed.at(1) == sampleCed.at(7))) ||
			((userCed.at(3) == sampleCed.at(2)) || (userCed.at(3) == sampleCed.at(7))) ||
			((userCed.at(4) == sampleCed.at(2)) || (userCed.at(4) == sampleCed.at(7))) ||
			((userCed.at(5) == sampleCed.at(2)) || (userCed.at(5) == sampleCed.at(7))) ||
			((userCed.at(6) == sampleCed.at(2)) || (userCed.at(6) == sampleCed.at(7))) ||
			((userCed.at(8) == sampleCed.at(2)) || (userCed.at(8) == sampleCed.at(7))) ||
			((userCed.at(9) == sampleCed.at(2)) || (userCed.at(9) == sampleCed.at(7))) ||
			((userCed.at(10) == sampleCed.at(2)) || (userCed.at(10) == sampleCed.at(7))) ||
			((userCed.at(11) == sampleCed.at(2)) || (userCed.at(1) == sampleCed.at(7))) )
	{
		cout << "*********************************************************************************" << endl;
		cout << "Error #3: inserto el caracter '-' en un espacio para numero....." << endl;
		cout << "*********************************************************************************" << endl;
		return true;
	}  else if (invChar == true)  // valida que no hayan caracteres invalidos
	{
		cout << "*********************************************************************************" << endl;
		std::cout << "Error #4: se encontro el caracter invalido '" << userCed[found] << "'...." << '\n';
		cout << "*********************************************************************************" << endl;
		return true;
	}

	return false;
}



bool UserData::salirRegistro()
{
	bool salir = false;
	int decision;
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "Opciones Registro de Usuarios: " << endl;
	cout << "1. Agregar un nuevo usuario" << endl;
	cout << "2. Volver al menu principal" << endl;
	cout << "Digite la opcion deseada: " << flush;
	cin >> decision;
	//cout << "-------------------------------------------------------------------------------------" << endl;
	//cout << "Digite la opcion deseada: " << flush;
	//cin >> decision;

	while (decision < 1 || decision > 2){
		cout << "Error #5: eleccion incorrecta." << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "Opciones Registro de Usuarios: " << endl;
		cout << "1. Agregar un nuevo usuario" << endl;
		cout << "2. Volver al menu principal" << endl;
		cout << "Digite la opcion deseada: " << flush;
		cin >> decision;
		//cout << "-------------------------------------------------------------------------------------" << endl;
	}
	if (decision == 1){
		salir = false;
	} else {
		salir = true;
	}
	return salir;
}


bool UserData::findDupCed(const string filename)
{
	ifstream readfile(filename, ios::in);
	string line;
	int flag = 0;
	int dupFlag =0;
	bool dupId;
	while (getline(readfile, line)) {
		if (getInvChars() == true){
			break;
		} else if (line.find(userCed) != string::npos) {
			flag = 1;
		} else if (line.find(userCed) == string::npos) {
			flag = 0;
		}
		dupFlag = dupFlag + flag;
	}

	if (dupFlag >= 1){
		dupId = true;
		cout << "*********************************************************************************" << endl;
		cout << "Error #6: el numero de cedula '" << userCed <<  "' ya existe en la base de datos. " << endl;
		cout << "*********************************************************************************" << endl;
	} else if (dupFlag==0){
		dupId = false;
	}
	return dupId;
}

bool UserData::salirCed()
{
	bool salir = false;
	int decision;
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "Opciones Cedula: " << endl;
	cout << "1. Volver a ingresar numero de cedula" << endl;
	cout << "2. Salir" << endl;
	cout << "Digite la opcion deseada: ";
	cin >> decision;
	//cout << "-------------------------------------------------------------------------------------" << endl;
	while (decision < 1 || decision > 2){
		cout << "Error #7: eleccion incorrecta." << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "Opciones Cedula: " << endl;
		cout << "1. Volver a ingresar numero de cedula" << endl;
		cout << "2. Volver al menu anterior" << endl;
		cout << "Digite la opcion deseada: ";
		cin >> decision;
	}
	if (decision ==1){
		salir = false;
	} else {
		salir = true;
	}
	return salir;
}

bool UserData::getInvChars()
{
	bool invChar = false;
	size_t found = userCed.find_first_not_of("0123456789-"); // caracteres validos
	if (found !=std::string::npos)  // valida que no hayan caracteres invalidos
	{
		invChar = true;
	} else {
		invChar = false;
	}
	return invChar;
}


// usada en Juego.cpp
bool UserData::searchPlayer(string fileName, string playerId)
{
	string ced, fname, lname;
	ifstream readFile;
	readFile.open(fileName);
	bool found = false;

	for(std::string line;!readFile.eof();std::getline(readFile,line))
	{
		if(line.find(playerId)!=std::string::npos)
		{
			std::cout<< "Bienvenido: "<< line << std::endl;
			found = true;
		}
	}
	if (found == true){
		cout << "Inicia el Juego:" << endl;
		return found;
	} else {
		cout << "Jugador: " << " '" << playerId<< "' "<< "no esta registrado." << endl;
		return found;
	}
}

