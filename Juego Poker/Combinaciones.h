#pragma once
#include "stdafx.h"
#include "Carta.h"

using namespace std;


/*Esta  clase controla las posibles combinaciones que se dan en el juego Poker. Esta clase se encargara de clasificar una lista
de cartas, formado con las cartas comunitarias y las cartas de algun jugador, segun exista o no: Escalera Real, Escalera de Color,
Poker, Full, Color, Escalera, Trio, Doble Par, Par o Carta Alta.*/
class Combinaciones{

	//Los siguientes son los atributos de la clase.
private:

	//Almacenara las cartas del jugador y las cartas comunitarias en una sola lista.
	list<Carta> cartas;
	//Almacena las cartas que estan en escalera que tiene el jugador.
	list<Carta> escalera; 
	//Almacena las cartas que estan repetidas y cuantas veces se repite cada una.
	list<list<int>> matrizRepeticiones;
	/*Almacenara un numero del 1 al 10 según la mano que posea el jugador de la siguiente manera : 
	Carta Alta->1, Par->2, Doble Par->3, Trío->4, Escalera->5, Color->6, Full->7, Poker->8, Escalera de Color->9 y Escalera Real->10.*/
	int numeroMano;
	//Contendra el numero del turno que se encuentra en curso.
	int numeroTurno;
	//booleano que guardara si hay escalera o no en la mano del jugador.
	bool hayEscalera;

//Metodos privados:
	//Verifica si hay escalera, el cual sera llamado por el metodo publico de igual nombre. No recibe ni devuelve nada.
	void verificarEscalera();
	//Determna las cartas que estan repetidas y cuantas veces se repite. El cual sera llamado por el metodo publico con igual nombre.
	void setMatrizRepeticiones();


//Metodos publicos:
public:
	//Constructor por defecto.
	Combinaciones();
	//Destructor por defecto.
	~Combinaciones();
	//Este es el constructor por parametros de la Combinaciones, recibe como parametro un ojeto del mismo tipo Combinaciones.
	Combinaciones(Combinaciones& );
	//Le asignara al atributo numeroTurno el entero que se reciba por parametro. No devuelve nada.
	void setNumeroTurno(int);
	//Retornara el valor del atributo numeroTurno. No recibe nada.
	int getNumeroTurno();
	//Retornara las cartas contenidas en el atributo escalera. No recibe nada.
	list<Carta> getEscalera();
	/*Metodo que unira las cartas del jugador y las cartas comunitarias (que entran por parametro) en una sola lista y 
	le asignara dicha lista al atributo Cartas. No devuelve nada.*/
	void setCartas(list<Carta> , list<Carta> );
	//Retorna la lista de Cartas guardada en el atributo cartas. No recibe nada.
	list<Carta> getCartas();
	//Ordena la lista de cartas de menor a mayor segun su numero (principalmente para cuando se desee verificar si hay o no escalera)
	void ordenarCartas();
	/*Comparara las cartas previamente ordenadas contenidas en la lista de cartas para ver si al menos hay numeroTurno + 1 cartas del
	mismo palo, retornara	true si dicha condición se cumple y false si no. No recibe nada.*/
	bool verificarColor();
	//Retorna (un boolenao) el atributo hayEscalera.
	bool getHayEscalera();
	//Retorna (un booleano) el valor de la ultima carta de la lista, previamente ordenada, la cual es la mas alta. No recibe nada.
	int obtenerCartaAlta();
	//Retorna (una lista de listas de enteros) el atributo matrizRepeticiones. No recibe nada.
	list<list<int>> getMatrizRepeticiones();
	//Asigna el numero de la mano, al atributo numeroMano. No recibe nada.
	void setNumeroMano();
	//Retorna (un entero) el atributo numeroMano. No recibe nada.
	int getNumeroMano();
	/*Asigna las cartas que estan repetidas y cuantas veces se repite cada una al aributo matrizRepeticiones. Para esto llama al 
	metodo prvado con igual nombre.*/
	void setMatrizRepeticiones(list<Carta>::iterator inicio, list<list<int>> matriz);
	/*Comparara las cartas previamente ordenadas contenidas en la lista de cartas para ver si al menos hay numeroTurno + 1 cartas en escalera,
	y le asigna al atributo hayEscalera true si dicha condicion se cumple y false si no. Para esto llama el metodo privado de igual
	nombre. No devuelve nada.*/
	void verificarEscalera(list<Carta>::iterator inicio);
};
