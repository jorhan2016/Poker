	#pragma once
#include "Mazo.h"
#include "Carta.h"
#include "Jugador.h"
#include <vector>
using namespace std;

class Dealer {

public:

	Dealer();
	virtual ~Dealer();

	void setCiega();
	void setMazo();
	void setDineroTurno(int dinero);
	int getCiega();
	Mazo getMazo();
	int getDineroTurno();
	void limpiarDineroTurno();
	Carta colocarCartaComunitaria();
	vector<Carta> repartirCartasJugador();
	int determinarGanador(vector<Jugador>);

private:

	int ciega;
	Mazo mazo;
	int dineroTurno;
	
}
