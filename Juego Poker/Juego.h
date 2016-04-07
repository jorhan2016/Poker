#ifndef JUEGO_H
#define	JUEGO_H
#include <sstream>
using namespace std;

class Juego {

public:

	Juego();
	void iniciarJuego();

	virtual ~Juego();

private:

	Dealer elDealer;
	Jugador jugadores[];
	Mesa laMesa;

	Jugador[] getJugadoresActivos();
	void mandarIgualarApuestas();
	boolean hayGanadorJuego();
	Jugador verificarGanadorRonda();
	int CANTIDAD_JUGADORES = 5;
	int RONDAS = 15;
	int DINERO_INICIAL_JUGADOR = 1000;
	int TURNOS_POR_RONDAS = 3;

}