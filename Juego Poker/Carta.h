#pragma once
#include <iostream>

using namespace std;

class Carta{

private:

	int palo;
	int numero;

public:

	Carta(int, int);
	Carta();
	~Carta();
	void setPalo(int);
	int getPalo();
	void setNumero(int);
	int getNumero();

	


};