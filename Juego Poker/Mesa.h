#pragma once
#include "stdafx.h"
#include "Carta.h"

using namespace std;

/*Hara el papel de la mesa en el juego de poker, almacenara las cartas comunitarias, el dinero que los jugadores apuesten en cada
turno(al final del turno tal dinero	pasara a manos del Dealer) y decidira la apuesta por turno.*/
class Mesa {

//Atributos de la clase:
private:
	//Almacena las cartas comunitarias del juego.
	list<Carta> cartasComunitarias;
	//Almacena la cantidad de apuesta por turno.
	int apuesta;
	//Almacena el "dinero" que los jugadores ponen en la mesa (las apuestas).
	int dineroMesa;

//Metodos de la clase:
public:
	//Constructor por defecto.
	Mesa();
	//Destructor de la clase.
	~Mesa();
<<<<<<< HEAD
	void setCartaComunitaria(Carta);
=======
	//Asigna al atributo cartasComunitarias la lista de cartas que le entra por parametro y no devuelve nada.
	void setCartasComunitarias(list<Carta>);
	/*Define el monto de la apuesta segun el turno, para el primer turno el valor de la apuesta sera la ciega 
	dictada por el Dealer y de ahi en adelante la apuesta ira aumentando en un 10% cada turno. Recibira por parametro el
	valor de la ciega dictada por el Dealer y el numero de turno. Y no devuelve nada*/
>>>>>>> Jorhan
	void setApuesta(int, int);
	//Al atributo dineroMesa le sumara el valor del parametro. No devuelve nada.
	void setDineroMesa(int);
	//Retornara una lista con las cartas comunitarias. No recibe parametros.
	list<Carta> getCartasComunitarias();
	//Retorna el monto de la apuesta. No recibe parametros.
	int getApuesta();
	//Retorna el monto que hay en la mesa. No recibe parametros.
	int getDineroMesa();
	//Le asigna al atributo dineroMesa el valor 0. No recibe parametros.
	void limpiarDineroMesa();

};
