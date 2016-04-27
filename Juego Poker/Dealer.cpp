#include "stdafx.h"
#include "Dealer.h"


Dealer::Dealer()
{
}

Dealer::~Dealer()
{
}

Dealer::Dealer(Dealer& otro)
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

void Dealer::limpiarDineroTurno()
{
	dineroTurno = 0;
}

Carta Dealer::colocarCartaComunitaria()
{
	//LLAMAR METODO devolverPrimeraCrta y luego al metodo borrarPrimeraCarta
	return mazo[contadorMazo];
	contadorMazo++;
}

vector<Carta> Dealer::repartirCartasJugador()
{
	//LLAMAR METODO devolverPrimeraCrta y luego al metodo borrarPrimeraCarta
	vector<Carta> cartasJugador;
	cartasJugador.assign(mazo[contadorMazo]);
	contadorMazo++;
	cartasJugador.push_back(mazo[contadorMazo]);
	contadorMazo++;
	return cartasJugador;
}

vector<Jugador> Dealer::determinarGanador(vector<Jugador> jugadores, vector<Carta> cartasComunitarias)
{
	Combinaciones combinacion;
	combinacion.setNumeroTurno(4);
	vector<int> manoJugador;
	int manoGanadora = 0;
	vector<Jugador> jugadorGanador;
	vector<vector<Carta>> cartasJugadorGanador;
	int contador = 0;
	for (int i = 0; i < jugadores.size(); i++)
	{
		combinacion.setCartas(jugadores[i].getCartasJugador(), cartasComunitarias);
		combinacion.setNumeroMano();
		manoJugador.push_back(combinacion.getNumeroMano());
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
			jugadorGanador.push_back(jugadores[i]);
			contador++;
		}
	}
	if (contador == 1)
	{
		return jugadorGanador;
	}
	else
	{
		Carta cartaVacia;
		cartaVacia.setNumero(0);
		cartaVacia.setPalo(0);
		vector<Carta> auxiliar;
		auxiliar.push_back(cartaVacia);
		vector<Jugador> jugadorGanadorFinal;
		manoJugador.clear();
		manoGanadora = 0;
		for (int i = 0; i < jugadorGanador.size(); i++)
		{
			combinacion.setCartas(jugadorGanador[i].getCartasJugador(), auxiliar);
			manoJugador.push_back(combinacion.obtenerCartaAlta());
		}

		for (int j = 0; j < manoJugador.size(); j++)
		{
			if (manoJugador[j] > manoGanadora)
			{
				manoGanadora = manoJugador[j];

			}
		}

		for (int j = 0; j < manoJugador.size(); j++)
		{
			if (manoJugador[j] == manoGanadora)
			{
				jugadorGanadorFinal.push_back(jugadorGanador[j]);
			}
		}

		return jugadorGanadorFinal;
	}
}
