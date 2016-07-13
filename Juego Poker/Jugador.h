#pragma once
#include "stdafx.h"
#include "Carta.h"

using namespace std;


/*Esta clase se encargara de hacer el papel de un jugador de poker, almacenara las dos cartas entregadas por el Dealer, 
el dinero que posea de principio a fin del juego y decidirá en cada turno si puede o no apostar.*/
class Jugador {

//Atributos de la clase:
private:
	//Lista que almacena las cartas del jugador, las cuales reparte el dealer.
	list<Carta> cartasJugador;
	//Almacena la cantidad de dinero que posee e ira teniendo el jugador en cada turno/ronda.
	int dinero;
	bool participaEnRonda;


//Metodos de la clase:
public:
	//Asigna la lista de cartas del jugador al atributo cartasJugador, la asignacion sera la lista que reciba por parametro.
	void setCartasJugador(list<Carta>);
	//Retorna la lista de cartas de jugador. No recibe nada.
	list <Carta> getCartasJugador();
<<<<<<< HEAD

	void setDinero(int);
	int getDinero();

	int ID;


	void setParticipaEnRonda(bool);
	bool getParticipaEnRonda();

	void reducirDinero(int);
	bool decidirApuesta(int, int, int); //mejor q reciba 3 parametros, ver .cpp
	bool salirJuego(int); //en el  diseño no recibe parametros, pero debe recibir la apuesta.

	void imprimirLista(list <Carta>); //para el main pruebas


	Jugador(int);
=======
	/*Asigna la cantidad de dinero que tiene el jugador, guardandolo en el atributo dinero; ya que puede ir cambiando por turno/ronda.
	No recibe parametros. No recibe nada.*/
	void setDinero();
	//Retorna un entero, el cual es el monto de dinero que posee un jugador. No recibe nada.
	int getDinero();
	//Reduce la cantidad de dinero de un jugador, le reduce lo que le entra por parametro.
	void reducirDinero(int);
	//Retorna true si un jugador decide apostar y false de lo contrario. Recibe tres enteros por parametros (apuesta, numero de mano, turno).
	bool decidirApuesta(int, int, int); 
	//Retorna true si un jugador sale de la ronda, un false de lo contrario. Recibe por parametro la apuesta del turno.
	bool salirJuego(int); 
	//Metodo que imprime la lista de cartas de un jugador, creado para el main pruebasJugador. Recibe la lista de cartas como parametro.
	void imprimirLista(list <Carta>); 
	//Constructor por defecto.
	Jugador();
	//Destructor.
>>>>>>> Jorhan
	~Jugador();
};
