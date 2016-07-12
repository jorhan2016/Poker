#pragma once
#include "stdafx.h"
#include "Jugador.h"
#include "Mesa.h"
#include "Combinaciones.h"

using namespace std;

class Juego {

private:

	int totalTurnos;
	int numeroTurno;
	int numeroJugadores;
	list<Jugador*> losJugadores;
	Mesa* laMesa;

public:

	Juego();
	~Juego();
	void iniciarJuego();
	void ingresarNumeroJugadores();
	void crearJugadores();
	void declararGanadorJuego();
	bool continuaElJuego();
	bool existeAlMenosUnJugadorConDinero();
	bool seHaAlcanzadoElNumeroMaximoDeTurnos();
};
