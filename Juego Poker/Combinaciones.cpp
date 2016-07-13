#include "stdafx.h"
#include "Combinaciones.h"

Combinaciones::Combinaciones()
{
}

Combinaciones::~Combinaciones()
{
}

Combinaciones::Combinaciones(Combinaciones& otro)
{
	this->cartas = otro.cartas;
	this->escalera = otro.escalera;
	this->numeroMano = otro.numeroMano;
	this->numeroTurno = otro.numeroTurno;
}

void Combinaciones::setNumeroTurno(int turno)
{
	numeroTurno = turno;
}

int Combinaciones::getNumeroTurno()
{
	return numeroTurno;
}

list<Carta> Combinaciones::getEscalera()
{
	return escalera;
}

bool Combinaciones::getHayEscalera()
{
	return hayEscalera;
}

void Combinaciones::setCartas(list<Carta> jugador, list<Carta> comunitarias)
{
	int tamanoJugador = jugador.size();
	for (int i = 0; i < tamanoJugador; i++)
	{
		comunitarias.push_back(jugador.front());
		jugador.pop_front();
	}
	cartas = comunitarias;
}

list<Carta> Combinaciones::getCartas()
{
	return cartas;
}

void Combinaciones::ordenarCartas(){
/*
	bool ordenado = false;
	while (!ordenado)
	{
		int contador = 0;
		for (list<Carta>::iterator it = cartas.begin(); it != cartas.end(); ++it)
		{
			list<Carta>::iterator it2 = ++it;
			if ((*it).getNumero() > (*it2).getNumero())
			{
				contador++;
				Carta temporal = *it;
				*it = *it2;
				*it2 = temporal;
			}
		}
		if (contador == 0)
		{
			ordenado = true;
		}
	}*/
	int contador = 0;
	for (list<Carta>::iterator it = cartas.begin(); it != cartas.end(); ++it)
	{
		for (list<Carta>::iterator it2 = it; it2 != cartas.end(); ++it2)
		{
			if ((*it).getNumero() > (*it2).getNumero())
			{
				Carta temporal = *it;
				*it = *it2;
				*it2 = temporal;
			}
		}
	}

}

bool Combinaciones::verificarColor()
{
	bool booleano = false;
	for (list<Carta>::iterator it = cartas.begin(); it != cartas.end(); ++it)
	{
		int contador = 0;
		for (list<Carta>::iterator it2 = cartas.begin(); it2 != cartas.end(); ++it2)
		{
			if ((*it).getPalo() == (*it2).getPalo())
			{
				contador++;
			}
		}
		if (contador >= numeroTurno + 1)
		{
			booleano = true;
			break;
		}
	}
	return booleano;
}

void Combinaciones::verificarEscalera()
{
	list<Carta>::iterator inicio = cartas.begin();
	Combinaciones::verificarEscalera(++inicio);
}

void Combinaciones::verificarEscalera(list<Carta>::iterator inicio)
{
	hayEscalera = false;
	if (inicio != cartas.end())
	{
		list<Carta>::iterator anteriorInicio = --inicio;
		int contador = 0;
		escalera.clear();
		escalera.push_back(*anteriorInicio);
		for (list<Carta>::iterator it = inicio; it != cartas.end(); ++it)
		{
			list<Carta>::iterator it2 = --it;
			if ((*it).getNumero() == (*it2).getNumero() + 1)
			{
				contador++;
				escalera.push_back((*it));
				if (contador >= numeroTurno)
				{
					hayEscalera = true;
					break;
				}
			}
			else
			{
				verificarEscalera(it++);
			}
		}
	}
}

int Combinaciones::obtenerCartaAlta()
{
	list<Carta>::iterator it = cartas.end();
	return (*--it).getNumero();
}

void Combinaciones::setMatrizRepeticiones()
{
	list<list<int>> repeticiones;
	Combinaciones::setMatrizRepeticiones(++cartas.begin(), repeticiones);
}

void Combinaciones::setMatrizRepeticiones(list<Carta>::iterator inicio, list<list<int>> matriz)
{
	if (inicio != cartas.end())
	{
		int contador = 1;
		for (list<Carta>::iterator it = inicio; it != cartas.end(); ++it)
		{
			list<int> auxiliar;
			list<Carta>::iterator it2 = --it;
			if ((*it).getNumero() == (*it2).getNumero())
			{
				contador++;
				auxiliar.assign((*it2).getNumero(), contador);
			}
			else
			{
				matriz.push_back(auxiliar);
				Combinaciones::setMatrizRepeticiones(++it, matriz);
			}
		}
	}
	else
	{
		matrizRepeticiones = matriz;
	}
}

list<list<int>> Combinaciones::getMatrizRepeticiones()
{
	return matrizRepeticiones;
}

void Combinaciones::setNumeroMano()
{
	Combinaciones::ordenarCartas();
	Combinaciones::verificarEscalera();
	if (Combinaciones::getHayEscalera())
	{
		if (Combinaciones::verificarColor())
		{
			if ((*escalera.begin()).getNumero() == 10)
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
		Combinaciones::setMatrizRepeticiones();
		list<list<int>> matrizRepeticiones = Combinaciones::getMatrizRepeticiones();
		if (matrizRepeticiones.size() != 0)
		{
			list<int> mayorRepeticion = { 0, 0 };
			for (list<list<int>>::iterator it = matrizRepeticiones.begin(); it != matrizRepeticiones.end(); ++it)
			{
				list<int >::iterator it2 = (*it).begin();
				++it2;
				list<int >::iterator it3 = mayorRepeticion.begin();
				++it3;
				if ((*it2) > (*it3))
				{
					mayorRepeticion = (*it);
				}
			}
			list<int >::iterator it3 = mayorRepeticion.begin();
			list<int >::iterator it5 = ++it3;
			if ((*it5) == 4)
			{
				numeroMano = 8;
			}
			else
			{
				if ((*it5) == 3)
				{
					numeroMano = 4;
					for (list<list<int>>::iterator it = matrizRepeticiones.begin(); it != matrizRepeticiones.end(); ++it)
					{
						list<int >::iterator it2 = (*it).begin();
						++it2;
						if ((*it2) == 2)
						{
							numeroMano = 7;
							break;
						}
					}
				}
				else
				{
					numeroMano = 2;
					for (list<list<int>>::iterator it = matrizRepeticiones.begin(); it != matrizRepeticiones.end(); ++it)
					{
						list<int >::iterator it2 = (*it).begin();
						list<int >::iterator it4 = ++it2;
						if ((*it2) != (*it3) && (*it4) == 2)
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
