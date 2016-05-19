#pragma once
#include <list>

using namespace std;

Class Mazo {

private:
	list<Carta*> misCartas();
	
public:

	Mazo();
	~Mazo();
	void setBaraja();
	list<Carta> getBaraja();
	void revolverCartas();
	
}
