#pragma once
#include "stdafx.h"
#include "Carta.h"

using namespace std;

class Jugador {

private:
	list<Carta> cartasJugador;
	int dinero;
	bool participaEnRonda;

public:

	void setCartasJugador(list<Carta>);

	list <Carta> getCartasJugador();

	void setDinero(int);
	int getDinero();

	int ID;


	void setParticipaEnRonda(bool);
	bool getParticipaEnRonda();

	void reducirDinero(int);
	bool decidirApuesta(int, int, int); //mejor q reciba 3 parametros, ver .cpp
	bool salirJuego(int); //en el  diseño no recibe parametros, pero debe recibir la apuesta.

	void imprimirLista(list <Carta>); //para el main pruebas


	Jugador(int);
	~Jugador();
};
