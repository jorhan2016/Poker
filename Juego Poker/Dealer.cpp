#include "stdafx.h"
#include "Dealer.h"
#include "Carta.h"
#include "Mazo.h"

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

void Dealer::limpiarDineroTurno()
{
	dineroTurno = 0;
}

Carta Dealer::colocarCartaComunitaria()
{
	return mazo.devolverPrimeraCarta();
}

list<Carta> Dealer::repartirCartasJugador()
{
	list<Carta> cartasJugador;
	cartasJugador.push_front(mazo.devolverPrimeraCarta());
	cartasJugador.push_front(mazo.devolverPrimeraCarta());
	return cartasJugador;
}

list<Jugador> Dealer::determinarGanador(list<Jugador> jugadores, list<Carta> cartasComunitarias)
{
	list<Jugador> jugadores2;
	Combinaciones combinacion;
	combinacion.setNumeroTurno(4);
	list<int> manoJugador;
	list<int> manoJugador2;
	list<int> manoJugador3;
	int manoGanadora = 0;
	list<Jugador> jugadorGanador;
	list<list<Carta>> cartasJugadorGanador;
	int contador = 0;
	int tamanoJugadores = jugadores.size();
	for (int i = 0; i < tamanoJugadores; i++)
	{
		combinacion.setCartas(jugadores.front().getCartasJugador(), cartasComunitarias);
		combinacion.setNumeroMano();
		manoJugador.push_back(combinacion.getNumeroMano());
		jugadores2.push_front(jugadores.front());
		jugadores.pop_front();
	}
	int tamanoManoJugador = manoJugador.size();
	for (int i = 0; i < tamanoManoJugador; i++)
	{
		if (manoJugador.front() > manoGanadora)
		{
			manoGanadora = manoJugador.front();
		}
		manoJugador2.push_front(manoJugador.front());
		manoJugador.pop_front();
	}
	int tamanoManoJugador2 = manoJugador2.size();
	for (int i = 0; i < tamanoManoJugador2; i++)
	{
		if (manoJugador2.front() == manoGanadora)
		{
			jugadorGanador.push_back(jugadores2.front());
			contador++;
		}
		manoJugador3.push_front(manoJugador2.front());
		manoJugador2.pop_front();
	}
	if (contador == 1)
	{
		return jugadorGanador;
	}
	else
	{
		Carta cartaVacia(0, 0);
		list<Carta> auxiliar;
		auxiliar.push_back(cartaVacia);
		list<Jugador> jugadorGanadorFinal;
		list<Jugador> jugadorGanador2;
		manoJugador.clear();
		manoJugador2.clear();
		manoGanadora = 0;
		int tamanoJugadorGanador = jugadorGanador.size();
		for (int i = 0; i < tamanoJugadorGanador; i++)
		{
			combinacion.setCartas(jugadorGanador.front().getCartasJugador(), auxiliar);
			manoJugador.push_back(combinacion.obtenerCartaAlta());
			jugadorGanador2.push_front(jugadorGanador.front());
			jugadorGanador.pop_front();
		}
		tamanoManoJugador = manoJugador.size();
		for (int j = 0; j < tamanoManoJugador; j++)
		{
			if (manoJugador.front() > manoGanadora)
			{
				manoGanadora = manoJugador.front();
			}
			manoJugador2.push_front(manoJugador.front());
			manoJugador.pop_front();
		}
		tamanoManoJugador = manoJugador.size();
		for (int j = 0; j < tamanoManoJugador; j++)
		{
			if (manoJugador2.front() == manoGanadora)
			{
				jugadorGanadorFinal.push_back(jugadorGanador2.front());
			}
			manoJugador2.pop_front();
		}

		return jugadorGanadorFinal;
	}
}
