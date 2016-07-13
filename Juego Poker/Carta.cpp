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

void Carta::setPalo(int palo){
	this->palo = palo;
}

int Carta::getNumero() {

	return this->numero;
}


int Carta::getPalo() {

	return this->palo;
}

void Carta::setNumero(int numero){
	this->numero = numero;
}

bool Carta::operator==(const Carta &c) const
{
    return this->palo == c.palo && this->numero == c.numero;
}
