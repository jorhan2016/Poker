#pragma once
#include "stdafx.h"
#include "Mazo.h"
#include "Carta.h"
#include "Jugador.h"
#include "Combinaciones.h"
#include "stdafx.h"

using namespace std;

class Dealer {

public:

	Dealer();
	virtual ~Dealer();
	Dealer(Dealer& otro);

	void setCiega();
	void setMazo();
	void setDineroTurno(int dinero);
	int getCiega();
	Mazo getMazo();
	int getDineroTurno();
	void limpiarDineroTurno();
	Carta colocarCartaComunitaria();
	list<Carta> repartirCartasJugador();
	list<Jugador> determinarGanador(list<Jugador> jugadores, list<Carta> cartasComunitarias);

private:

	int ciega;
	Mazo mazo;
	int dineroTurno;

};
