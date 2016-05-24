#pragma once
#include <vector>
#include "Carta.h"
using namespace std;

Class Mesa {

private:

	vector<Carta> cartasComunitarias;
	int apuesta;
	int dineroMesa;

private:

	vector<Carta> cartasComunitarias;
	int apuesta;
	int dineroMesa;

public:

	Mesa();
	~Mesa();
	void setCartasComunitarias(vector<Carta>);
	void setApuesta(int, int);
	void setDineroMesa(int);
	vector<Carta> getCartasComunitarias();
	int getApuesta();
	int getDineroMesa();
	void limpiarDineroMesa();

};
