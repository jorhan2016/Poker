<<<<<<< HEAD

<<<<<<< HEAD
#include <iostream>
=======
#define	CARTA_H
#include <sstream>
>>>>>>> denis
using namespace std;
=======
>>>>>>> denis
#pragma once
#include <iostream>

using namespace std;

class Carta{

private:

	int palo;
	int numero;

public:

	Carta(int, int);
	~Carta();
	void setPalo(int);
	int getPalo();
	void setNumero(int);
	int getNumero();




};