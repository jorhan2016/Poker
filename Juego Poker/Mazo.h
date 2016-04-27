#pragma once
#include <vector>

using namespace std;

Class Mazo {

private:
	vector<Carta> misCartas();
	
public:

	Mazo();
	~Mazo();
	void setBaraja();
	vector<Carta> getBaraja();
	void revolverCartas();

}
