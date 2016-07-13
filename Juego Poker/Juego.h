#pragma once
#include "stdafx.h"
#include "Jugador.h"
#include "Mesa.h"
#include "Combinaciones.h"
#include "Dealer.h"

using namespace std;


//En esta clase se desarrollara todo el juego de poker de modo que lo unico que se hace en el main sera llamar a esta clase.
class Juego {

//Atributos de la clase.
private:
	//Almacena la cantidad de rondas que se pueden jugar.
	int totalRondas;
	//Almacena el numero de la ronda que se esta jugando.
	int numeroRonda;
	//Almacena la cantidad de turnos que se pueden jugar.
	int totalTurnos;
	//Almacena el numero del turno que se esta jugando.
	int numeroTurno;
	//Almacena el numero de jugadores del juego.
	int numeroJugadores;
	//Lista que almacena los jugadores del juego.
	list<Jugador*> losJugadores;
	//Almacenara la mesa del juego.
	Mesa* laMesa;
	//Almacena el dealer del juego.
	Dealer* elDealer;

	//Metodos de la clase:
public:
	//Constructor por defecto.
	Juego();
	//Destructor.
	~Juego();
	//Parte de la interfaz del juego  interaccion con el usuario. Inicia el juego. No recibe nada.
	void iniciarJuego();
	//Asigna el numero de jugadores que habra en el juego (lo decide el usuario), guardandolo en el atributo numeroJugadores. No recibe nada.
	void ingresarNumeroJugadores();
	//Crea la cantidad de jugadores que indique el atributo numeroJugadores. No recibe nada.
	void crearJugadores();
	//Determina cual es el jugador ganador del juego. No recibe nada.
	void declararGanadorJuego();
	//Determina cual es el jugador ganador por ronda. No recibe nada.
	void declararGanadorRonda();
	//Determina si el juego sigue o no, devolviendo un booleano respectivo. Para lo que emplea los siguientes metodos. No recibe nada.
	bool continuaElJuego();
	//Determina si existe al menos un jugador con dinero en el juego. No recibe nada.
	bool existeAlMenosUnJugadorConDinero();
	//Determina si las rondas del juego se acabaron o no, y devuelve un booleano respectivo. No recibe nada.
	bool seHaAlcanzadoElNumeroMaximoDeRondas();
	/*Determina si se continua con el actual turno del juego. Ya que puede darse que ninguno de los jugadores tenga el dinero 
	suficiente para apostar lo que diga la ciega. No recibe nada.*/
	bool continuaElTurno();
};
