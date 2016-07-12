#include "stdafx.h"
#include "Juego.h"
#include <list>

Juego::Juego(){

	Mesa* laMesa = new Mesa();
	
}

Juego::~Juego(){
}

void Juego::iniciarJuego(){

	cout << "Bienvenido al juego de poker" << endl;
	ingresarNumeroJugadores();
	crearJugadores();

}

void Juego::ingresarNumeroJugadores(){

	//Esto es necesario porque hay que validar que el numero de jugadores sean como minimo 2 y maximo 6.
	do {
		cout << "Para iniciar digite el numero de jugadores humanos que participaran" << endl;
		cin >> numeroJugadores;
	} while (numeroJugadores < 2 || numeroJugadores > 6);

}

void Juego::crearJugadores(){

	for (int i = 0; i < numeroJugadores; i++) {

		losJugadores.push_front(new Jugador());
		
	}

}

