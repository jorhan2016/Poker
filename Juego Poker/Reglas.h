#ifndef REGLAS_H
#define	REGLAS_H
#include <sstream>
using namespace std;

class Reglas {


public:

	Carta[] ordenarCartas();
	Carta[] determinarMismoPalo();
	int determinarExistenciaCartasRepetidas(Carta[]);
	int obtenerManoNumero();
	int determinarFormacionEscalera(Carta[]);


}