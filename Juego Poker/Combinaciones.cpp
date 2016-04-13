#include "stdafx.h"
#include "Combinaciones.h"


Combinaciones::Combinaciones()
{
}

Combinaciones::~Combinaciones()
{
}

void Combinaciones::setNumeroTurno(int turno)
{
	numeroTurno = turno;
}

int Combinaciones::getNumeroTurno()
{
	return numeroTurno;
}

void Combinaciones::setCartas(vector<Carta> jugador, vector<Carta> comunitarias)
{
	for (int i = 0; i < jugador.size(); i++)
	{
		comunitarias.push_back(jugador[i]);
	}
	cartas = comunitarias;
}

vector<Carta> Combinaciones::getCartas()
{
	return cartas;
}

void Combinaciones::ordenarCartas()
{
	bool ordenado = false;
	while (!ordenado)
	{
		int contador = 0;
		for (int i = 0; i < cartas.size()-1; i++)
		{	
			if (cartas[i].getNumeroCarta() > cartas[i + 1].getNumeroCarta())
			{
				contador++;
				Carta temporal = cartas[i];
				cartas[i] = cartas[i + 1];
				cartas[i + 1] = temporal;
			}
		}
		if (contador == 0)
		{
			ordenado = true;
		}
	}
}

bool Combinaciones::verificarColor()
{
	bool booleano = false;
	for (int i = 0; i < cartas.size(); i++)
	{
		int contador = 0;
		for (int j = 0; j < cartas.size(); j++)
		{
			if (cartas[i].getPaloCarta == cartas[j].getPaloCarta)
			{
				contador++;
			}
		}
		if (contador >= numeroTurno+1)
		{
			booleano = true;
			break;
		}
	}
	return booleano;
}

bool Combinaciones::verificarEscalera()
{
	return false;
}

int Combinaciones::obtenerCartaAlta()
{
	return 0;
}

vector<int> Combinaciones::obtenerRepeticiones()
{
	return vector<int>();
}

void Combinaciones::setNumeroMano()
{
}

int Combinaciones::getNumeroMano()
{
	return 0;
}

