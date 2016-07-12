#pragma once
#include "stdafx.h"
#include "Jugador.h"
#include "Mesa.h"
#include "Combinaciones.h"
#include "Dealer.h"

using namespace std;

class Juego {

private:

	int totalRondas;
	int numeroRonda;

	int totalTurnos;
	int numeroTurno;

	int numeroJugadores;
	list<Jugador*> losJugadores;
	Mesa* laMesa;
	Dealer* elDealer;

public:

	Juego();
	~Juego();
	void iniciarJuego();
	void ingresarNumeroJugadores();
	void crearJugadores();
	void declararGanadorJuego();
	void declararGanadorRonda();
	bool continuaElJuego();
	bool existeAlMenosUnJugadorConDinero();
	bool seHaAlcanzadoElNumeroMaximoDeRondas();
	bool continuaElTurno();
};
