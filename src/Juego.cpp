/*
 * Juego.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Henry
 */

#include "Juego.h"
#include "UserData.h"
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

void Juego::juegaRonda()
{
	encabezado();
	getNumPlayers();
	validaJugadores();

}


void Juego::encabezado()
{
	cout << "------------------------------------JUEGO DE TIROS DE LA FINCA LOCA--------------------------------\n" << endl;
	cout << "--------------------------------------------REGLAS DEL JUEGO---------------------------------------\n" << endl;
	cout << "1) En cada ronda pueden participar de 2 hasta 4 jugadores." << endl;
	cout << "2) Cada jugador puede lanzar 2 veces las 3 flechas por ronda." << endl;
	cout << "3) El juego consiste en 5 rondas." << endl;
	cout << "4) El jugador con menor cantidad de puntos es el elegido para el almuerzo de cortes�a.\n"
			"En caso de un empate, el �ltimo jugador con el menor puntaje ser� el perdedor" << endl;
	cout << "5) Para elegir el almuerzo de cortes�a de castigo, el jugador perdedor debe tirar una flecha a \n"
			"a la diana. De acuerdo a los puntos obtenidos se le asignar� un almuerzo seg�n la lista de almuerzos" << endl;
	cout << "---------------------------------------------------------------------------------------------------\n" << endl;
	cout << "--------------------------------------------INICIO DEL JUEGO---------------------------------------\n" << endl;
}

int Juego::getNumPlayers()
{
	cout << "Ingrese el n�mero de Jugadores: " << flush;
	cin >> jugadores;
	while (jugadores < 2 || jugadores > 4){
		cout << "Error: solo se permiten de 2 a 4 jugadores." << endl;
		cout << "Ingrese el n�mero de jugadores: " << flush;
		cin >> jugadores;
	}
	return jugadores;
}

void Juego::validaJugadores()
{
	for (int e = 1; e <= jugadores; e++) {
		cout << "Escriba el numero de cedula del jugador # " << e << " : " << flush;
		UserData user;
		searchId = user.pideCedula();
		wrongCed = user.validCed(searchId,sampleCed);
		findPLayer = user.searchPlayer(filename, searchId);
		//user.dupCed = user.findDupCed(filename);
		while( (wrongCed == true) || (findPLayer == false))
		{
			searchId = user.pideCedula();
			wrongCed = user.validCed(searchId,sampleCed);
			findPLayer = user.searchPlayer(filename, searchId);
		}
		searchId = cedJugador[e];

		ifstream readFile (filename, ios::in);
		searchId = cedJugador[e];
		cedTemp[e] = cedJugador[e];
	}
}

