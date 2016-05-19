#include "stdafx.h"
#include "Mesa.h"


Mesa::Mesa() {

}

Mesa::~Mesa() {

}

void Mesa::setCartasComunitarias(vector<Carta> cartasComunitarias) {

	this->cartasComunitarias = cartasComunitarias;
	
}

void Mesa::setApuesta(int cantidadCiega, int turno) {

	if (turno == 1) {

		this->apuesta = cantidadCiega;

	}
	else {

		this->apuesta = cantidadCiega*(1 + 0.1*(turno-1));

	}

}

void Mesa::setDineroMesa(int dineroMesa) {
	this->dineroMesa = dineroMesa;

}

vector<Carta> Mesa::getCartasComunitarias() {

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
