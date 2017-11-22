//============================================================================
// Name        : registerUser.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "UserData.h"
#include "Juego.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

int showOptions();
void deleteFile();


int main() {


	const string filename = "userData1.txt";

	UserData newUser;
	string user;
	Juego jugador;

	int option = showOptions();
	while (option != 5) {
		ofstream writeFile (filename, ios::out | ios::app);
		switch (option) {
		case 1:
			newUser.Option1();
			break;
		case 2:
			jugador.juegaRonda();
			cout << endl;
			break;
		case 3:
			cout << "Llama al ranking" << endl;
			cout << endl;
			break;
		case 4:
			deleteFile();
			cout << endl;
			break;
		}
		option = showOptions();
	}

	return 0;
}


void deleteFile()
{
if( remove( "userData1.txt" ) != 0 )
	perror( "Error al borrar el archivo" );
  else
	puts( "Se borro el archivo exitosamente" );
}



int showOptions()
{
int option;
cout << " Opciones del programa\n"
     << " 1 - Registro de Jugadores\n"
     << " 2 - Jugar\n"
     << " 3 - Ver Ranking\n"
	 << " 4 - Borrar Archivo\n"
     << " 5 - Salir" << endl;

	//Introducir solicitud del usuario
	do {
	    cout << "\nOpcion: ";
	    cin >> option;
	}
	while ((option < 1) || (option > 5));
	return option;
}






/*
void procesaOptions(int option){
	cin >> option;
	switch(option){
	case 1:
		const string filename = "userData.txt";
		ofstream writeFile (filename, ios::out | ios::app);
		UserData newUser;
		newUser.userRegistration(writeFile);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
}
*/
