// Juego Poker.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Carta.h"
#include "Combinaciones.h"


int main()
{
	Carta carta1(1, 1);
	Carta carta2(2, 1);
	Carta carta3(2, 0);
	Carta carta4(0, 1);
	Carta carta5(3, 1);

	list<Carta> lista1 = {carta1, carta2};
	list<Carta> lista2 = {carta3, carta4, carta5};

	Combinaciones combi;

	combi.setCartas(lista1, lista2);


    return 0;
}

