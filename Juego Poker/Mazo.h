#ifndef MAZO_H
#define	MAZO_H
#include <sstream>
using namespace std;

class Mazo {


public:

	Mazo();
	void setCartas();
	Carta carta getCarta(int indice);

	virtual ~Mazo();


private:

	int CANTIDAD_CARTAS = 52;
	Carta[] cartas;
	int posicionSuperior;
	void revolverMazo();

}