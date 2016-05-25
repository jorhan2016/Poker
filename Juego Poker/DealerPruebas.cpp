#include "stdafx.h"
#include "Dealer.h"

void testColocarCartaComunitaria() {
	Dealer dealer;
	Carta result = dealer.colocarCartaComunitaria();
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testColocarCartaComunitaria (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testDeterminarGanador() {
	list<Jugador> jugadores;
	list<Carta> cartasComunitarias;
	Dealer dealer;
	list<Jugador> result = dealer.determinarGanador(jugadores, cartasComunitarias);
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testDeterminarGanador (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testGetCiega() {
	Dealer dealer;
	int result = dealer.getCiega();
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testGetCiega (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testGetContadorMazo() {
	Dealer dealer;
	int result = dealer.getContadorMazo();
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testGetContadorMazo (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testGetDineroTurno() {
	Dealer dealer;
	int result = dealer.getDineroTurno();
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testGetDineroTurno (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testGetMazo() {
	Dealer dealer;
	Mazo result = dealer.getMazo();
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testGetMazo (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testLimpiarDineroTurno() {
	Dealer dealer;
	dealer.limpiarDineroTurno();
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testLimpiarDineroTurno (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testRepartirCartasJugador() {
	Dealer dealer;
	list<Carta> result = dealer.repartirCartasJugador();
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testRepartirCartasJugador (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testSetCiega() {
	Dealer dealer;
	dealer.setCiega();
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testSetCiega (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testSetContadorMazo() {
	Dealer dealer;
	dealer.setContadorMazo();
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testSetContadorMazo (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testSetDineroTurno() {
	int dinero;
	Dealer dealer;
	dealer.setDineroTurno(dinero);
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testSetDineroTurno (DealerPruebas) message=error message sample" << std::endl;
	}
}

void testSetMazo() {
	Dealer dealer;
	dealer.setMazo();
	if (true /*check result*/) {
		std::cout << "%TEST_FAILED% time=0 testname=testSetMazo (DealerPruebas) message=error message sample" << std::endl;
	}
}

int main(int argc, char** argv) {
	std::cout << "%SUITE_STARTING% DealerPruebas" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	std::cout << "%TEST_STARTED% testColocarCartaComunitaria (DealerPruebas)" << std::endl;
	testColocarCartaComunitaria();
	std::cout << "%TEST_FINISHED% time=0 testColocarCartaComunitaria (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testDeterminarGanador (DealerPruebas)" << std::endl;
	testDeterminarGanador();
	std::cout << "%TEST_FINISHED% time=0 testDeterminarGanador (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testGetCiega (DealerPruebas)" << std::endl;
	testGetCiega();
	std::cout << "%TEST_FINISHED% time=0 testGetCiega (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testGetContadorMazo (DealerPruebas)" << std::endl;
	testGetContadorMazo();
	std::cout << "%TEST_FINISHED% time=0 testGetContadorMazo (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testGetDineroTurno (DealerPruebas)" << std::endl;
	testGetDineroTurno();
	std::cout << "%TEST_FINISHED% time=0 testGetDineroTurno (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testGetMazo (DealerPruebas)" << std::endl;
	testGetMazo();
	std::cout << "%TEST_FINISHED% time=0 testGetMazo (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testLimpiarDineroTurno (DealerPruebas)" << std::endl;
	testLimpiarDineroTurno();
	std::cout << "%TEST_FINISHED% time=0 testLimpiarDineroTurno (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testRepartirCartasJugador (DealerPruebas)" << std::endl;
	testRepartirCartasJugador();
	std::cout << "%TEST_FINISHED% time=0 testRepartirCartasJugador (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testSetCiega (DealerPruebas)" << std::endl;
	testSetCiega();
	std::cout << "%TEST_FINISHED% time=0 testSetCiega (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testSetContadorMazo (DealerPruebas)" << std::endl;
	testSetContadorMazo();
	std::cout << "%TEST_FINISHED% time=0 testSetContadorMazo (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testSetDineroTurno (DealerPruebas)" << std::endl;
	testSetDineroTurno();
	std::cout << "%TEST_FINISHED% time=0 testSetDineroTurno (DealerPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testSetMazo (DealerPruebas)" << std::endl;
	testSetMazo();
	std::cout << "%TEST_FINISHED% time=0 testSetMazo (DealerPruebas)" << std::endl;

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	return (EXIT_SUCCESS);
}

