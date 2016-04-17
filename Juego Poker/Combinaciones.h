	#pragma once
#include "Carta.h"
#include <vector>
using namespace std;

class Combinaciones
{
public:
	Combinaciones();
	~Combinaciones();

	void setNumeroTurno(int turno);
	int getNumeroTurno();
	void setCartas(vector<Carta> jugador, vector<Carta> comunitarias);
	vector<Carta> getCartas();
	void ordenarCartas();
	bool verificarColor();
	bool verificarEscalera();
	int obtenerCartaAlta();
	vector<vector<int>> obtenerRepeticiones();
	void setNumeroMano();
	int getNumeroMano();

private:
	vector<Carta> cartas;
	vector<Carta> escalera;
	int numeroMano;
	int numeroTurno;
	vector<vector<int>> obtenerRepeticiones(int inicio, vector<vector<int>> matriz);
	bool verificarEscalera(int inicio);
};

