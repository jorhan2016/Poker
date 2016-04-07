#ifndef JUGADOR_H
#define	JUGADOR_H
#include <sstream>
using namespace std;

class Jugador {

public:

	Jugador(Mesa mesa, int dineroInicial)
		void setApostado(int dineroApostado);
	int getApostado();
	boolean getJugando();
	void apostar();
	void jugar();
	Carta[] mostrarCartas();
	void setCartas(Carta[] cartas);
	Mesa getMesa();
	void setMesa();
	void setDinero(int dineroRecibido);
	int getDinero();

	virtual ~Jugador();
private:

	Carta[] cartas;
	Mesa laMesa;
	int dinero;
	int dineroApostado;
	boolean jugando;
	int calcularApuesta();
	void igualarApuesta();
	void salirJuego();

}