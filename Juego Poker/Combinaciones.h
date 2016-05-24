#pragma once
#include "Carta.h"

using namespace std;

class Combinaciones
{
public:
	Combinaciones();
	~Combinaciones();
	Combinaciones(Combinaciones& otro);

	void setNumeroTurno(int turno);
	int getNumeroTurno();
	list<Carta> getEscalera();
	void setCartas(list<Carta> jugador, list<Carta> comunitarias);
	list<Carta> getCartas();
	void ordenarCartas();
	bool verificarColor();
	bool verificarEscalera();
	int obtenerCartaAlta();
	void setMatrizRepeticiones();
	list<list<int>> getMatrizRepeticiones();
	void setNumeroMano();
	int getNumeroMano();

private:
	list<Carta> cartas;
	list<Carta> escalera;
	list<list<int>> matrizRepeticiones;
	int numeroMano;
	int numeroTurno;
	void setMatrizRepeticiones(list<Carta>::iterator inicio, list<list<int>> matriz);
	bool verificarEscalera(list<Carta>::iterator inicio);
};