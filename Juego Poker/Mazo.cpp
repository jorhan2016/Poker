#include "stdafx.h"
#include "Mazo.h"
#include "Carta.h"


Mazo::Mazo() {

	void setBaraja();
}

Mazo::~Mazo() {

}


void Mazo::setBaraja() {


	for (int a = 1; a <= 4; a++) {

		for (int b = 2; b <= 14; ++b) {
			
			Carta carta(b, a);
			this->misCartas.push_front(carta);

		}

	}

}

list<Carta> Mazo::getBaraja() {

	return this->misCartas;

}

void Mazo::revolverCartas() {

	srand((unsigned int)time(0));

	for (int i = 0; i < 1000; i++) {

		list<Carta>::iterator it1 = misCartas.begin();
		list<Carta>::iterator it2 = misCartas.begin();

		int limite1 = rand() % misCartas.size();
		int limite2 = rand() % misCartas.size();

		for (int i = 0; i < limite1; i++) {

			++it1;
		}

		for (int i = 0; i < limite2; i++) {

			++it2;
		}

		Carta temporal = *it1;
		*it1 = *it2;
		*it2 = temporal;


	}
}

Carta Mazo::devolverPrimeraCarta() {

	Carta cartaTemporal = misCartas.front();
	misCartas.pop_front();
	return cartaTemporal;


}
