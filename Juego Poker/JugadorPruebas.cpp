#include "stdafx.h"
#include "JugadorPruebas.h"
#include "stdafx.h"
#include <list>
#include "Carta.h"
#include "Jugador.h"
using namespace std;


JugadorPruebas::JugadorPruebas(){
}

JugadorPruebas::~JugadorPruebas(){
}

int main() {

	int palo = 1;
	int num = 3;
	int palo2 = 5;
	int num2 = 6;


	Carta miCarta(palo, num);
	Carta miCarta2(palo2, num2);

	list <Carta> miLista;
	miLista.push_back(miCarta);
	miLista.push_back(miCarta2);

	Jugador j1;
	j1.setCartasJugador(miLista);

	list <Carta> par = j1.getCartasJugador();

	j1.imprimirLista(par);			//ESTO FUE PARA PROBAR EL SET Y EL GET DE JUGADOR- TODO FUNCIONA ¡QUÉ DICHA!



									//INICIA PRUEBA DE OTROS METODOS
	int ciega = 175;


	j1.setDinero();
	cout << "Dinero del jugador: " << j1.getDinero() << endl;

	cout << "La ciega es de: " << ciega << endl;

	j1.reducirDinero(ciega);
	cout << "Dinero del jugador despues de reducir la ciega: " << j1.getDinero() << endl;

	//INICIA PRUEBA DE OTROS METODOS

	int numTurno = 2;
	int numMano = 6;
	cout << "El numero del turno y mano son " << numTurno << numMano << endl;

	bool apuesto = j1.decidirApuesta(ciega, numMano, numTurno);



	if (apuesto == true) {
		cout << "SI apuesto" << endl;
	}
	else {
		cout << "NO apuesto" << endl;
	}


	int dineroParaSalir = 50;   //esto pes para probar el metodo salir del juego
	bool salgo = j1.salirJuego(ciega);

	cout << "sale del juego?" << endl;

	if (salgo == true) {
		cout << "NO SALGO" << endl;
	}
	else {
		cout << "SI salgo" << endl;
	}

	system("pause");
	return 0;
};
