#include "stdafx.h"
#include "Mesa.h"

Mesa::Mesa() {
	this->dineroMesa = 0;

}

Mesa::~Mesa() {

}

void Mesa::setCartaComunitaria(Carta* cartaComunitaria) {

	this->cartasComunitarias.push_front(cartaComunitaria);

}

void Mesa::setApuesta(int cantidadCiega, int turno) {

	if (turno == 1) {

		this->apuesta = cantidadCiega;

	}
	else {
		
		this->apuesta = (int)(cantidadCiega*(1 + 0.1*(turno - 1)));

	}

}

void Mesa::setDineroMesa(int dineroMesa) {
	this->dineroMesa = this->dineroMesa + dineroMesa;

}

list<Carta*> Mesa::getCartasComunitarias() {

	return cartasComunitarias;

}

int Mesa::getApuesta() {

	return apuesta;

}

int Mesa::getDineroMesa() {

	return dineroMesa;

}

void Mesa::limpiarDineroMesa() {

	this->dineroMesa = 0;

}
