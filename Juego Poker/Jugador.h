#ifndef JUGADOR_H
#define	JUGADOR_H
#include <sstream>
#include "Carta.h"

#include <vector>
using namespace std;

class Jugador {

private:
	vector<Carta> cartasJugador;
	int dinero;

public:

	void Jugador::setCartasJugador(vector<Carta>);
	vector<Carta> getCartasJugador();
	void setDinero();
	int getDinero();
	void reducirDinero(int);
	bool decidirApuesta(int, int, int); //mejor q reciba 3 arametros, ver .cpp
	bool salirJuego(int); //en el  diseño no recibe parametros, pero debe recibir la apuesta.
};