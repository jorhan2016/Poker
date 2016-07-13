#pragma once
#include "stdafx.h"
#include "Carta.h"

using namespace std;

class Mesa {

private:

	list<Carta> cartasComunitarias;
	int apuesta;
	int dineroMesa;

public:

	Mesa();
	~Mesa();
	void setCartaComunitaria(Carta);
	void setApuesta(int, int);
	void setDineroMesa(int);
	list<Carta> getCartasComunitarias();
	int getApuesta();
	int getDineroMesa();
	void limpiarDineroMesa();

};
