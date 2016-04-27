#pragma once
#include <vector>

using namespace std;

Class Mesa {

private:

	Carta[5] cartasComunitarias;
	int apuesta;
	int dineroMesa;

public:

	Mesa();
	~Mesa();
	void setCartasComunitarias(Carta[]);
	void setApuesta(int, int);
	void setDineroMesa(int);
	Carta[] getCartasComunitarias();
	int getApuesta();
	int getDineroMesa();
	void limpiarDineroMesa();

}
