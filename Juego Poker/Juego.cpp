#include "stdafx.h"
#include "Juego.h"
#include <list>

Juego::Juego(){

	Mesa* laMesa = new Mesa();
	Dealer* elDealer = new Dealer();
	totalTurnos = 3;
	totalRondas = 10;
	numeroRonda = 1;
}

Juego::~Juego(){

	for (list<Jugador *>::iterator it = losJugadores.begin(); it != losJugadores.end(); ++it) {

		delete *it;

	}
	delete laMesa;
	delete elDealer;

}

void Juego::iniciarJuego(){

	cout << "Bienvenido al juego de poker" << endl;
	ingresarNumeroJugadores();
	crearJugadores();

	while (continuaElJuego()) {

		cout << "Estoy aca" << endl;
		cout << "Inicia la ronda: " << numeroRonda << "del juego" << endl;
		numeroTurno = 1;

		while (continuaLaRonda()) {
			cout << "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCc" << endl;

			elDealer->setCiega(); //El Dealer establece el monto de la ciega
			cout << "El monto establecido por el Dealer es: " << elDealer->getCiega() << endl;
			
			reducirDineroDeJugadores(elDealer->getCiega());

			cout << "Se reduce el dinero a cada jugador activo" << endl;
			laMesa->setApuesta(elDealer->getCiega(), numeroRonda); //Se estable la apuesta del turno

			colocarCartasComunitarias();
			entregarCartasAJugadores();
			determinarApuestasJugadores();
			
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

		losJugadores.push_front(new Jugador(i+1));
		
	}

}

void Juego::declararGanadorJuego(){

	Jugador* jugadorConMasDinero = losJugadores.front();
	for (list<Jugador *>::iterator it = losJugadores.begin(); it != losJugadores.end(); ++it) {

		if ((*it)->getDinero() > jugadorConMasDinero->getDinero()) {

			jugadorConMasDinero = (*it);
		}

	}

	cout << "El ganador del juego es: " << jugadorConMasDinero->ID << endl;

}

void Juego::declararGanadorRonda(){

	list<Jugador> jugadoresActivos;
	list<Jugador> jugadoresOrdenadosPorMejorMano;
	int numeroJugadoresActivos = 0;
	for (list<Jugador *>::iterator it = losJugadores.begin(); it != losJugadores.end(); ++it) {

		if ((*it)->getParticipaEnRonda()) {

			jugadoresActivos.push_front((**it));
			numeroJugadoresActivos++;
		}

	}
	
	//list<Jugador> jugadoresOrdenadosPorMejorMano();
	//jugadoresOrdenadosPorMejorMano = elDealer->determinarGanador(jugadoresActivos, laMesa->getCartasComunitarias());

	cout << "El ganador de la ronda es: " << elDealer->determinarGanador(jugadoresActivos, laMesa->getCartasComunitarias()).front().ID << endl;
	jugadoresOrdenadosPorMejorMano.front().setDinero(laMesa->getDineroMesa());
	
}

void Juego::reducirDineroDeJugadores(int montoDinero){

	for (list<Jugador *>::iterator it = losJugadores.begin(); it != losJugadores.end(); ++it) {

		if ((*it)->getDinero() >= montoDinero) {

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

		laMesa->setCartaComunitaria(elDealer->entregarCarta());
		laMesa->setCartaComunitaria(elDealer->entregarCarta());
		laMesa->setCartaComunitaria(elDealer->entregarCarta());


	}
	else {
		laMesa->setCartaComunitaria(elDealer->entregarCarta());
	}

}

void Juego::entregarCartasAJugadores(){

	for (list<Jugador*>::iterator it = losJugadores.begin(); it != losJugadores.end(); ++it) {

		if ((*it)->getParticipaEnRonda()){

			(*it)->setCartasJugador(elDealer->repartirCartasJugador());

		}

	}

}

void Juego::determinarApuestasJugadores(){

	Combinaciones combinacionCartas;
	for (list<Jugador *>::iterator it = losJugadores.begin(); it != losJugadores.end(); ++it) {

		if ((*it)->getParticipaEnRonda()) {

			combinacionCartas.setCartas((*it)->getCartasJugador(), laMesa->getCartasComunitarias());
			int numeroMano = combinacionCartas.getNumeroMano();

			if ((*it)->decidirApuesta(laMesa->getApuesta(), numeroMano, numeroTurno)) {

				(*it)->reducirDinero(laMesa->getApuesta());
				laMesa->setDineroMesa(laMesa->getApuesta());

			}
			else {

				(*it)->setParticipaEnRonda(false);
			}

		}

	}

}

bool Juego::continuaElJuego(){
	
	return (existeAlMenosUnJugadorConDinero() && seHaAlcanzadoElNumeroMaximoDeRondas());


}

bool Juego::seHaAlcanzadoElNumeroMaximoDeRondas() {

	return numeroRonda != totalRondas;
}

bool Juego::existeAlMenosUnJugadorConDinero(){
	
	int jugadoresConDinero = 0;
	for (list<Jugador *>::iterator it = losJugadores.begin(); it != losJugadores.end(); ++it) {

		if ((*it)->getDinero() > 0) {
			jugadoresConDinero++;
		}

	}
	
	return (jugadoresConDinero > 1);
}



bool Juego::continuaLaRonda(){
	cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
	int jugadoresActivos = 0;
	for (list<Jugador *>::iterator it = losJugadores.begin(); it != losJugadores.end(); ++it) {

		if ((*it)->getParticipaEnRonda()) {
			jugadoresActivos++;
		}

	}
	cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" << endl;

	if (jugadoresActivos > 0) {

		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	if (numeroRonda <= totalRondas ) {

		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return (jugadoresActivos>0 &&  numeroRonda<=totalRondas);
}



