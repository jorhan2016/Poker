#include "stdafx.h"
#include "Dealer.h"


Dealer::Dealer()
{
}

Dealer::~Dealer()
{
}

Dealer(Dealer& otro)
{
	this->ciega = otro.ciega;
	this->mazo = otro.mazo;
	this->dineroTurno = otro.dineroTurno;
	this->contadorMazo = otro.contadorMazo;
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

void Dealer::setDineroTurno(int& dinero)
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

int Dealer::determinarGanador(vector<Jugador>& jugadores, vector<Carta>& cartasComunitarias)
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
		Carta cartaVacia;
		cartaVacia.setNumero(0);
		cartaVacia.setPalo(0);
		vector<Carta> auxiliar;
		auxiliar.push_back(cartaVacia);
		manoJugador.clear();
		manoGanadora = 0;
		for(int i = 0 ; i < jugadorGanador.size() ; i++)
		{
  			combinacion.setCartas(jugadores[jugadorGanador[i]].getCartasJugador() , auxiliar);
			manoJugador.push_back(combinacion.obtenerCartaAlta());
		}
		jugadorGanador.clear();
		for(int j = 0 ; j < manoJugador.size() ; j++)
		{
			if(manoJugador[j] > manoGanadora)
			{
				manoGanadora = manoJugador[j];
				jugadorGanador.push_back(j);
			}
		}
		return jugadorGanador[jugadorGanador.size()-1] + 1;
	}
}

