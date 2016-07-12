#include "stdafx.h"
#include "Juego.h"
#include <list>

Juego::Juego(){

	Mesa* laMesa = new Mesa();
	totalTurnos = 10;
	numeroTurno = 0;
}

Juego::~Juego(){
}

void Juego::iniciarJuego(){

	cout << "Bienvenido al juego de poker" << endl;
	ingresarNumeroJugadores();
	crearJugadores();

	//Es importante aclarar que una cosa es ganador juego y otra ganador ronda
	while (continuaElJuego()) {


	}

	declararGanadorJuego();
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

bool Juego::continuaElJuego(){
	
	return (existeAlMenosUnJugadorConDinero() || seHaAlcanzadoElNumeroMaximoDeTurnos());


}

bool Juego::existeAlMenosUnJugadorConDinero(){
	
	int jugadoresConDinero = 0;
	for (list<Jugador *>::iterator it = losJugadores.begin(); it != losJugadores.end(); ++it) {

		if ((*it)->getDinero > 0) {
			jugadoresConDinero++;
		}

	}
	
	return (jugadoresConDinero > 1);
}

bool Juego::seHaAlcanzadoElNumeroMaximoDeTurnos(){

	return numeroTurno != totalTurnos;
}



