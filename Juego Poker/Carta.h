#pragma once
#include "stdafx.h"

using namespace std;

//Esta clase es para crear el objeto Carta en el juego, la cual se compone de el numero y el tipo de palo.

class Carta{ 

 //estos son los atributos de la carta
private:			
	//Sera un numero entero del 1 al 4 segun la carta sea Corazones->1, Espadas ->2, Treboles->3 o Diamantes->4.
	int palo;
	//Sera un entero del 2 al 14 correspondiente al numero de la carta, a la carta J le corresponde el 11, a la Q 12, al K 13 y al As 14.
	int numero;	

	//Estos son los metodos de la clase.
public:			

	//Este es el constructor por parametros de la Carta, recibe dos enteros por parametro (el numero y el palo).
	Carta(int, int);	
	//El constructor por defecto
	Carta();			
	//El destructor
	~Carta();		
	//Metodo que le asigna el tipo de palo a la carta, recibe por parametro el entero que representa el tipo de palo.
	void setPalo(int);	
	//Retorna el tipo de palo de la carta. No recibe parametros.
	int getPalo();			
	//Metodo que le asigna el numero a la carta, recibe por parametro el entero que sera dicho numero y no devuelve nada.
	void setNumero(int);	
	//Retorna el nemero de la carta. No recibe parametros.
	int getNumero();		
	//sobre caraga del operador ==, recibe por parametro un elemento tipo Carta. Devuelve un booleano.
	bool operator==(const Carta& carta) const;		

};
