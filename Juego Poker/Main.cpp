// Juego Poker.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Juego.h"

int main() {

#if _DEBUG
	pruebas();
#endif

	Juego j;
	j.iniciarJuego();

    return 0;
}

int pruebas() {

	// Pruebas para la clase Carta
	// PruebaCarta pC;
	// pC.probar();



}

