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
	//NECESITO METODO PARA VER PRIMERA CARTA DE MAZO Y BORRARLA
	return mazo.front();
	mazo.pop_front();
}

list<Carta> Dealer::repartirCartasJugador()
{
	//NECESITO METODO PARA VER PRIMERA CARTA DE MAZO Y BORRARLA
	list<Carta> cartasJugador;
	cartasJugador.push_front(mazo.front());
	mazo.pop_front();
	cartasJugador.push_front(mazo.front());
	mazo.pop_front();
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
	for (int i = 0; i < jugadores.size(); i++)
	{
		combinacion.setCartas(jugadores.front().getCartasJugador(), cartasComunitarias);
		combinacion.setNumeroMano();
		manoJugador.push_back(combinacion.getNumeroMano());
		jugadores2.push_front(jugadores.front());
		jugadores.pop_front();
	}
	for (int i = 0; i < manoJugador.size(); i++)
	{
		if (manoJugador.front() > manoGanadora)
		{
			manoGanadora = manoJugador.front();
		}
		manoJugador2.push_front(manoJugador.front());
		manoJugador.pop_front();
	}
	for (int i = 0; i < manoJugador2.size(); i++)
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
		for (int i = 0; i < jugadorGanador.size(); i++)
		{
			combinacion.setCartas(jugadorGanador.front().getCartasJugador(), auxiliar);
			manoJugador.push_back(combinacion.obtenerCartaAlta());
			jugadorGanador2.push_front(jugadorGanador.front());
			jugadorGanador.pop_front();
		}

		for (int j = 0; j < manoJugador.size(); j++)
		{
			if (manoJugador.front() > manoGanadora)
			{
				manoGanadora = manoJugador.front();
			}
			manoJugador2.push_front(manoJugador.front());
			manoJugador.pop_front();
		}

		for (int j = 0; j < manoJugador.size(); j++)
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




