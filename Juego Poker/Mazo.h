#pragma once

#include <vector>

using namespace std;

class Mazo {

private:
	vector<Carta> misCartas();
	
public:

	Mazo();
	~Mazo();
	void setBaraja();
	vector<Carta> getBaraja();
	void revolverCartas();

};
