#include "stdafx.h"
#include "Mazo.h"
#include "Carta.h"
#include <list>


Mazo::Mazo() {

	void setBaraja();
}

Mazo::~Mazo() {

}


void Mazo::setBaraja() {


	for (int a = 0; a <= 3; a++) {

		for (int b = 0; b <= 13; b++) {

			this->misCartas.push_front(new Carta(b, a));

		}

	}

}

list<Carta *> Mazo::getBaraja() {

	return this->misCartas;

}

void Mazo::revolverCartas() {

	srand(time(NULL));

	for (int i = 0; i < 1000; i++) {

		list<Carta*>::iterator it1 = misCartas.begin();
		list<Carta*>::iterator it2 = misCartas.begin();

		int limite1 = rand() % misCartas.size();
		int limite2 = rand() % misCartas.size();

		for (int i = 0; i < limite1; i++) {

			++it1;
		}

		for (int i = 0; i < limite2; i++) {

			++it2;
		}

		Carta *temporal = *it1;
		*it1 = *it2;
		*it2 = temporal;


	}
}

Carta* Mazo::devolverPrimeraCarta() {

	Carta* cartaTemporal = misCartas.front();
	misCartas.pop_front();
	return cartaTemporal;


}