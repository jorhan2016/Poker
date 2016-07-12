#include "stdafx.h"
#include "Juego.h"
#include <list>

Juego::Juego(){

	Mesa* laMesa = new Mesa();
	totalTurnos = 4;
	totalRondas = 10;
	numeroRonda = 0;
}

Juego::~Juego(){
}

void Juego::iniciarJuego(){

	cout << "Bienvenido al juego de poker" << endl;
	ingresarNumeroJugadores();
	crearJugadores();

	while (continuaElJuego()) {

		numeroTurno = 1;

		while (continuaLaRonda()) {

			elDealer->setCiega(); //El Dealer establece el monto de la ciega
			reducirDineroDeJugadores(elDealer->getCiega());
			laMesa->setApuesta(elDealer->getCiega(), numeroRonda); //Se estable la apuesta del turno
			colocarCartasComunitarias();


			numeroTurno++;
		}

		declararGanadorRonda();
		laMesa->limpiarDineroMesa();

		numeroRonda++;
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

void Juego::declararGanadorRonda(){

	elDealer->determinarGanador(); //falta
}

void Juego::reducirDineroDeJugadores(int montoDinero){

	for (list<Jugador *>::iterator it = losJugadores.begin(); it != losJugadores.end(); ++it) {

		if ((*it)->getDinero >= montoDinero) {

			(*it)->reducirDinero(montoDinero);
			laMesa->setDineroMesa(montoDinero);
		}
		else {
			(*it)->setParticipaEnRonda(false);
		}


	}

}

void Juego::colocarCartasComunitarias(){

	if (numeroTurno == 1) {

		Carta* cartaProvenienteDelDealer = &(elDealer->colocarCartaComunitaria());
		laMesa->setCartaComunitaria(cartaProvenienteDelDealer);

	}
	else {

	}

}

bool Juego::continuaElJuego(){
	
	return (existeAlMenosUnJugadorConDinero() || seHaAlcanzadoElNumeroMaximoDeRondas());


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

bool Juego::seHaAlcanzadoElNumeroMaximoDeRondas(){

	return numeroRonda != totalRondas;
}

bool Juego::continuaLaRonda(){

	return false;
}



