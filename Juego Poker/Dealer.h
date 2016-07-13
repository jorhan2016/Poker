#pragma once
#include "stdafx.h"
#include "Mazo.h"
#include "Carta.h"
#include "Jugador.h"
#include "Combinaciones.h"

using namespace std;

/*Clase toma el papel del Dealer en el juego de poker, le entregara las dos cartas que le corresponden a cada jugador y 
la cartas comunitarias, decidira el valor de la primera apuesta(ciega), almacenara el dinero que se encuentre en la mesa y decidira
el ganador de cada ronda.*/
class Dealer {

//Atributos de la clase:
private:

	//Entero correspondiente a la apuesta inicial que deberan pagar los jugadores para poder participar en la ronda.
	int ciega;
	//Baraja de cartas que se utilizaran para el desarrollo del juego.
	Mazo mazo;
	//Este atributo almacenara el dinero que los jugadores hayan puesto en la mesa para el final del turno (suma de las apuestas).
	int dineroTurno;

//Metodos de la clase:
public:
	//Constructor por defecto.
	Dealer();
	//Destructor virtual.
	virtual ~Dealer();
	//Constructor por parametro, que recibe por parametro un objeto del mismo tipo.
	Dealer(Dealer&);
	//Asigna el valor de la primera apuesta por medio de un numero aleatorioentre 1 y 250. No recibe nada.
	void setCiega();
	//Llama al metodo setBaraja de la clase Mazo, para asi crear un mazo y luego lo revolvera mediante el metodo revolverCartas.No recibe nada.
	void setMazo();
	//Le sumara al atributo dineroTurno el entero recibido por parametro.
	void setDineroTurno(int);
	//Retornara el valor del atributo ciega. No recibe nada.
	int getCiega();
	//Retornara la baraja contenida en el atributo mazo, que es de tipo Mazo. No recibe nada.
	Mazo getMazo();
	//Retornara el valor del atributo dineroTurno. No recibe nada.
	int getDineroTurno();
	//Reinicia el atributo dineroTurno asignandole el numero 0. No recibe nada.
	void limpiarDineroTurno();
<<<<<<< HEAD
	Carta entregarCarta();
=======
	//Retornara una carta comunitaria.
	Carta colocarCartaComunitaria();
	//Retornara una lista de dos Cartas que corresponderan a las cartas asignadas a uno de los jugadores. No recibe nada.
>>>>>>> Jorhan
	list<Carta> repartirCartasJugador();
	/*Determna el(los) ganador(es) por ronda, para lo cual recibe por parametro la lista de jugadores y la lista de cartas. 
	Puede haber un empate de almenos dos jugadores.*/
	list<Jugador> determinarGanador(list<Jugador> , list<Carta> );

};
