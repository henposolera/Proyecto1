/*
 * Juego.h
 *
 *  Created on: Nov 20, 2017
 *      Author: Henry
 */

#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;
#ifndef JUEGO_H_
#define JUEGO_H_

class Juego {
private:
	int jugadores;
	string cedJugador[5];
	string cedTemp[5];
	string nombreCastigo[5];
	string castigoRonda[5];
	string searchId;
	const string filename = "userData1.txt";
	bool wrongCed;
	const string sampleCed = "11-1111-1111";
	bool findPLayer;


public:
	void encabezado();
	int getNumPlayers();
	void validaJugadores();
	void juegaRonda();
};

#endif /* JUEGO_H_ */
