
#define	CARTA_H
#include <sstream>
using namespace std;
#pragma once

class Carta {

public:

	carta();
	void setNumeroCarta();
	int getNumeroCarta();
	void setPaloCarta();
	int getPaloCarta();

	virtual ~Carta();


private:

	int numeroCarta;
	int paloCarta;
};

