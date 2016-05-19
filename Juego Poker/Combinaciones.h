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
	list<list<int>> obtenerRepeticiones();
	void setNumeroMano();
	int getNumeroMano();

private:
	list<Carta> cartas;
	list<Carta> escalera;
	int numeroMano;
	int numeroTurno;
	list<list<int>> obtenerRepeticiones(list<Carta>::iterator inicio, list<list<int>> matriz);
	bool verificarEscalera(list<Carta>::iterator inicio);
};


