
#include <iostream>
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
	bool salirJuego(int); //en el  dise�o no recibe parametros, pero debe recibir la apuesta.

	
	
	Jugador::Jugador()
	{
	}
	Jugador::~Jugador()
	{
	}
};