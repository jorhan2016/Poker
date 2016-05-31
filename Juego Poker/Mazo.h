#pragma once
#include "stdafx.h"
#include "Carta.h"


using namespace std;

class Mazo {

private:
	list<Carta> misCartas;

public:

	Mazo();
	~Mazo();
	void setBaraja();
	list<Carta> getBaraja();
	void revolverCartas();
	Carta devolverPrimeraCarta();

};
