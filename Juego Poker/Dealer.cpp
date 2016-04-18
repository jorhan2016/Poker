#include "stdafx.h"
#include "Dealer.h"


Dealer::Dealer()
{
}

Dealer::~Dealer()
{
}

void Dealer::setCiega()
{
	srand((unsigned int)time(0));
	ciega = rand() % 250 + 1;
}

void Dealer::setMazo()
{
	mazo.setBaraja();
	mazo.revolverCartas();
}

void Dealer::setDineroTurno(int dinero)
{
	dineroTurno += dinero;
}

void Dealer::setContadorMazo()
{
	contadorMazo = 0;
}

int Dealer::getCiega()
{
	return ciega;
}

Mazo Dealer::getMazo()
{
	return mazo;
}

int Dealer::getDineroTurno()
{
	return dineroTurno;
}

int Dealer::getContadorMazo()
{
	return contadorMazo;
}

void limpiarDineroTurno()
{
	dineroTurno = 0;
}

Carta colocarCartaComunitaria()
{
	return mazo[contadorMazo];
	contadorMazo++;
}

vector<Carta> Dealer::repartirCartasJugador()
{
	vector<Carta> cartasJugador;
	cartasJugador.assign (mazo[contadorMazo]);
	contadorMazo++;
	cartasJugador.push_back (mazo[contadorMazo]);
	contadorMazo++;
	return cartasJugador;
}

int Dealer::determinarGanador(vector<Jugador> jugadores, vector<Carta> cartasComunitarias)
{
	Combinaciones combinacion;
	combinacion.setNumeroTurno(4);
	vector<int> manoJugador;
	int manoGanadora = 0;
	vector<int> jugadorGanador;
	int contador = 0;
	for (int i = 0; i < jugadores.size(); i++)
	{
		combinacion.setCartas(jugadores[i].getCartasJugador() , cartasComunitarias);
		combinacion.setNumeroMano();
		manoJugador.push_back (combinacion.getNumeroMano());
	}
	for (int i = 0; i < manoJugador.size(); i++)
	{
		if (manoJugador[i] > manoGanadora)
		{
			manoGanadora = manoJugador[i];
		}
	}
	for (int i = 0; i < manoJugador.size(); i++)
	{
		if (manoJugador[i] == manoGanadora)
		{
			jugadorGanador.push_back (i);
			contador++;
		}
	}
	if (contador == 1)
	{
		return jugadorGanador[0]+1;
	}
	else
	{
		switch (manoGanadora)
		{
			case 1:
  			
  			break;

			case 2:
  			Code to execute if <variable> == that-value
  			break;
			
			case 3:
  			Code to execute if <variable> == that-value
  			break;

			case 4:
  			Code to execute if <variable> == that-value
  			break;

			case 5:
  			Code to execute if <variable> == that-value
  			break;

			case 6:
  			Code to execute if <variable> == that-value
  			break;

			case 7:
  			Code to execute if <variable> == that-value
  			break;

			case 8:
  			Code to execute if <variable> == that-value
  			break;

			case 9:
  			Code to execute if <variable> == that-value
  			break;

			case 10:
  			Code to execute if <variable> == that-value
  			break;
		}
	}
}

