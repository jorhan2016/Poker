#pragma once
#include "stdafx.h"
#include "Carta.h"
using namespace std;


//Clase encargada de reunir 52 cartas en posicion aleatoria necesarias para el correcto desarrollo del juego.
class Mazo {

//Atributo de la clase.
private:
	//Lista donde se almacenaran las 52 cartas.
	list<Carta> misCartas;


//Metodos.
public:
	//Constructor por defecto.
	Mazo();
	//Destructor de la clase.
	~Mazo();
	//Metodo que no recibe nada de parametro ni devuelve nada. Crea la lista de 52 cartas, asignandolas al atributo misCartas.
	void setBaraja();
	//Retorna la lista de cartas o el mazo (el atributo misCartas). No recibe parametros.
	list<Carta> getBaraja();
	//Metodo que revuelve las cartas del mazo, no recibe ni devuelve nada.
	void revolverCartas();
	//Retorna la primer carta del mazo y la borra del mismo.
	Carta devolverPrimeraCarta();

};
