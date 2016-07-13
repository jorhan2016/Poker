#include "stdafx.h"
#include "Jugador.h"

Jugador::Jugador(int ID){
	
	this->dinero = 5000;
	this->ID = ID;
	this->participaEnRonda = true;
}


Jugador::~Jugador(){
}

void Jugador::setCartasJugador(list<Carta> cartasrepartidas) {
	cartasJugador = cartasrepartidas;
}

list <Carta> Jugador::getCartasJugador()
{
	return cartasJugador;
}

void Jugador::setDinero(int dineroGanado)
{
	dinero = dinero + dineroGanado;
}

int Jugador::getDinero()
{
	return dinero;
}

void Jugador::setParticipaEnRonda(bool condicion){

	this->participaEnRonda = condicion;
}

bool Jugador::getParticipaEnRonda(){
	return participaEnRonda;
}

void Jugador::reducirDinero(int rebaja)
{

	dinero = dinero - rebaja;

}

bool Jugador::decidirApuesta(int apuesta, int numeroMano, int numTurno) //agregué el segundo y tercer parametro, creo que se necesita. es mejor para saber que mano tiene cada jugador y el turno en que van (lo q se obtiene de Combinacion) ya que son casos dependientes de eso.
{
	bool b;
	if (numTurno = 2) {
		if ((numeroMano == 1 || numeroMano == 2) && apuesta <= 55)
			b;
		if ((numeroMano == 3 || numeroMano == 4) && apuesta <= 110)
			b;
		if ((numeroMano == 5 || numeroMano == 6) && apuesta <= 165)
			b;
		if ((numeroMano == 7 || numeroMano == 8) && apuesta <= 220)
			b;
		if ((numeroMano == 9 || numeroMano == 10) && apuesta <= 275)
			b;
	}
	else  b = false;

	if (numTurno = 3) {
		if ((numeroMano == 1 || numeroMano == 2) && apuesta <= 56)
			b;
		if ((numeroMano == 3 || numeroMano == 4) && apuesta <= 113)
			b;
		if ((numeroMano == 5 || numeroMano == 6) && apuesta <= 173)
			b;
		if ((numeroMano == 7 || numeroMano == 8) && apuesta <= 235)
			b;
		if ((numeroMano == 9 || numeroMano == 10) && apuesta <= 302)
			b;
	}
	else  b = false;

	if (numTurno = 4) {
		if ((numeroMano == 1 || numeroMano == 2) && apuesta <= 57)
			b;
		if ((numeroMano == 3 || numeroMano == 4) && apuesta <= 116)
			b;
		if ((numeroMano == 5 || numeroMano == 6) && apuesta <= 181)
			b;
		if ((numeroMano == 7 || numeroMano == 8) && apuesta <= 251)
			b;
		if ((numeroMano == 9 || numeroMano == 10) && apuesta <= 332)
			b;
	}
	else b = false;

	return b;
}

bool Jugador::salirJuego(int apuesta) // en el  diseño no recibe parametros, pero debe recibir la apuesta.
{
	return dinero >= apuesta;
}

void Jugador::imprimirLista(list <Carta> pareja) // es para probar el set y get .
{
	Carta carta2 = pareja.back();
	Carta carta1 = pareja.front();

	cout << "Carta1 (P1,B1): (" << carta1.getPalo() << "," << carta1.getNumero() << ")" << endl;
	cout << "Carta2 (P2,B2): (" << carta2.getPalo() << "," << carta2.getNumero() << ")" << endl;


}
