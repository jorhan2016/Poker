#ifndef MESA_H
#define	MESA_H
#include <sstream>
using namespace std;

class Mesa {

public:

	int CANTIDAD_CARTAS_COMUNITARIAS_VISIBLES_INICIAL = 3;
	Mesa();
	void setComunitarias(int CANTIDAD_CARTAS_COMUNITARIAS_VISIBLES_INICIAL);
	Carta[] getComunitarias();
	void setApuesta();
	int getApuesta();
	void añadirApuesta(int cantidad);
	void setAcumulado(int cantidadAcumulada);
	int getAcumulado();

	virtual ~Mesa();

private:

	int CANTIDAD_CARTAS_COMUNITARIAS_TOTAL = 5;
	Carta[] cartasComunitarias;
	int cantidadCartasVisibles;
	int apuesta;
	int cantidadDineroAcumulado;
	Mazo elMazo;

}