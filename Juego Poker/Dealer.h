#pragma once
#include "Mazo.h"
#include "Carta.h"
#include "Jugador.h"
#include "Combinaciones.h"
#include <time.h>

using namespace std;

class Dealer {

public:

	Dealer();
	virtual ~Dealer();
	Dealer(Dealer& otro);

	void setCiega();
	void setMazo();
	void setDineroTurno(int dinero);
	void setContadorMazo();
	int getCiega();
	Mazo getMazo();
	int getDineroTurno();
	int getContadorMazo();
	void limpiarDineroTurno();
	Carta colocarCartaComunitaria();
	vector<Carta> repartirCartasJugador();
	vector<Jugador> determinarGanador(vector<Jugador> jugadores, vector<Carta> cartasComunitarias);

private:

	int ciega;
	Mazo mazo;
	int dineroTurno;
	int contadorMazo;//BORRAR

};