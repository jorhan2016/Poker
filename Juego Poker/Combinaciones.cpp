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
		color.clear();
		int contador = 0;
		for (int j = 0; j < cartas.size(); j++)
		{
			if (cartas[i].getPaloCarta == cartas[j].getPaloCarta)
			{
				color.push_back (cartas[j].getNumeroCarta());
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
	return Combinaciones::verificarEscalera(1);
}

bool Combinaciones::verificarEscalera(int inicio)
{
	bool booleano = false;
	if (inicio < cartas.size())
	{
		int contador = 0;
		escalera.assign (cartas[inicio-1]);
		for (int i = inicio; i < cartas.size(); i++)
		{	
			if (cartas[i].getNumeroCarta() == cartas[i-1].getNumeroCarta()+1)
			{
				contador++;
				escalera.push_back (cartas[i]);
				if (contador >= numeroTurno)
				{
					booleano = true;
					break;
				}
			}
			else
			{
				verificarEscalera(i+1);
			}
		}
	}
	return booleano;
}

int Combinaciones::obtenerCartaAlta()
{
	return cartas[cartas.size()-1].getNumeroCarta();
}

vector<vector<int>> Combinaciones::obtenerRepeticiones()
{
	vector<vector<int>> repeticiones;
	return Combinaciones::obtenerRepeticiones(1,repeticiones);
}

vector<vector<int>> Combinaciones::obtenerRepeticiones(int inicio, vector<vector<int>> matriz)
{
	if(inicio < cartas.size())
	{
		int contador = 1;
		for (int i = inicio; i < cartas.size(); i++)
		{
			vector<int> auxiliar;
			if (cartas[i].getNumeroCarta() == cartas[i-1].getNumeroCarta())
			{
				contador++;
				auxiliar.assign (cartas[i-1].getNumeroCarta(),contador);
			}
			else
			{
				matriz.push_back (auxiliar);
				Combinaciones::obtenerRepeticiones(i+1,matriz);
			}
		}
	}
	else
	{
		return matriz;
	}
}

void Combinaciones::setNumeroMano()
{
	Combinaciones::ordenarCartas();
	if (Combinaciones::verificarEscalera())
	{
		if (Combinaciones::verificarColor())
		{
			if (escalera[0].getNumeroCarta() == 10)
			{
				numeroMano = 10;
			}
			else
			{
				numeroMano = 9;
			}
		}
		else
		{
			numeroMano = 5;
		}
	}
	else
	{
		vector<vector<int>> matrizRepeticiones = Combinaciones::obtenerRepeticiones();
		if(matrizRepeticiones.size() != 0)
		{
			vector<int> mayorRepeticion = {0,0};
			for (int i = 0; i < matrizRepeticiones.size(); i++)
			{
				if (matrizRepeticiones[i][1] > mayorRepeticion[1])
				{
					mayorRepeticion = matrizRepeticiones[i];
				}
			}
			if (mayorRepeticion[1] == 4)
			{
				numeroMano = 8;
			}
			else
			{
				if (mayorRepeticion[1] == 3)
				{
					numeroMano = 4;
					for (int i = 0; i < matrizRepeticiones.size(); i++)
					{
						if (matrizRepeticiones[i][1] == 2)
						{
							numeroMano = 7;
							break;
						}
					}
				}
				else
				{
					numeroMano = 2;
					for (int i = 0; i < matrizRepeticiones.size(); i++)
					{

						if (matrizRepeticiones[i][0] != mayorRepeticion[0] && matrizRepeticiones[i][1] == 2)
						{
							numeroMano = 3;
							break;
						}
					}
				}
			}
		}
		else
		{
			if (Combinaciones::verificarColor())
			{
				numeroMano = 6;
			}
			else
			{
				numeroMano = 1;
			}
		}
	}
}

int Combinaciones::getNumeroMano()
{
	return numeroMano;
}

