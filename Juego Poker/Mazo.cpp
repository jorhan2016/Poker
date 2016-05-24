#include "stdafx.h"
#include "Mazo.h"
#include "Carta.h"

Mazo::Mazo() {

	void setBaraja();
}

Mazo::~Mazo() {

}


void Mazo::setBaraja() {

	int c = 0;

	for (int a = 0; a <= 3; a++) {

		for (int b = 0; b <= 13; b++) {

			this->misCartas.push_front(new Carta(b, a));
			c++;

		}

	}

}

list<Carta*> Mazo::getBaraja() {

	return this->misCartas;

}

void Mazo::revolverCartas() {

	srand((unsigned int)time(0));

	int j = rand() % 52;

	Carta cartaTemporal;

	for (i = 1; i <= 52; i++) {

		cartaTemporal = misCartas[i];
		misCartas[i] = misCartas[j];
		misCartas[j] = cartaTemporal;

	}
}
