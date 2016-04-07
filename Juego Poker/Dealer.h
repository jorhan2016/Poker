#ifndef DEALER_H
#define	DEALER_H
#include <sstream>
using namespace std;

class Dealer {

public:

	int CTD_CARTAS_POR_JUGADOR = 2;
	Dealer(Mesa mesa);
	void generarApuestaInicial();
	void limpiarAcumulado();
	void colocarCartasComunitarias();
	void revelarCartas();
	Carta[] sacarCartas(int cantidadCartas);

	virtual ~Dealer();

private:

	int APUESTA_MINIMA = 10; *En realidad este valor es especificado
		int APUESTA_MAXIMA = 250;
	Mesa laMesa;
	Mazo elMazo;
	int apuestaInicial;
}