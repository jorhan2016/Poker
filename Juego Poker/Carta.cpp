#include "stdafx.h"
#include "Carta.h"


Carta::Carta(int palo, int numero) {

	this->palo = palo;
	this->numero = numero;

}

Carta::Carta() {

};

Carta::~Carta() {

}

int Carta::getNumero() {

	return this->numero;
}


int Carta::getPalo() {

	return this->palo;
}

bool Carta::operator==(const Carta &c) const
{
    return this->palo == c.palo && this->numero == c.numero;
}
