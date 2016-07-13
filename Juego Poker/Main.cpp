
#include "stdafx.h"
#include "Juego.h"

int main() {

	Juego* juegoPoker = new Juego();
	juegoPoker->iniciarJuego();


	delete juegoPoker;
	system("pause");
    return 0;
}
