#include "stdafx.h"
#include "Combinaciones.h"

void testObtenerCartaAlta()
{
	Carta carta1(1, 14);
	Carta carta2(1, 8);
	Carta carta3(2, 4);
	Carta carta4(3, 10);
	Carta carta5(2, 3);
	Carta carta6(4, 1);
	Carta carta7(3, 5);
	
	Combinaciones combinaciones1;
	list<Carta> jugador1 = {carta7, carta2};
	list<Carta> comunitarias1 = {carta6, carta5, carta3};
	combinaciones1.setCartas(jugador1, comunitarias1);
	combinaciones1.ordenarCartas();
	int resultado1 = 8;
	if (combinaciones1.obtenerCartaAlta() != resultado1)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testObtenerCartaAlta (CombinacionesPruebas) message=Fallo el metodo obtener carta alta al pasarle 5 cartas ordenadas" << std::endl;
	}

	Combinaciones combinaciones2;
	list<Carta> jugador2 = {carta7};
	list<Carta> comunitarias2 = {carta6};
	combinaciones2.setCartas(jugador2, comunitarias2);
	combinaciones2.ordenarCartas();
	int resultado2 = 5;
	if (combinaciones1.obtenerCartaAlta() != resultado2)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testObtenerCartaAlta (CombinacionesPruebas) message=Fallo el metodo obtener carta alta al pasarle 2 cartas ordenadas" << std::endl;
	}

	Combinaciones combinaciones3;
	list<Carta> jugador3 = {carta1, carta2};
	list<Carta> comunitarias3 = {carta3};
	combinaciones3.setCartas(jugador3, comunitarias3);
	combinaciones3.ordenarCartas();
	int resultado3 = 14;
	if (combinaciones3.obtenerCartaAlta() != resultado3)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testObtenerCartaAlta (CombinacionesPruebas) message=Fallo el metodo obtener carta alta al pasarle 3 cartas desordenadas" << std::endl;
	}

	Combinaciones combinaciones4;
	list<Carta> jugador4 = {carta1, carta2};
	list<Carta> comunitarias4 = {carta3, carta4, carta5, carta6, carta7};
	combinaciones4.setCartas(jugador4, comunitarias4);
	combinaciones4.ordenarCartas();
	int resultado4 = 14;
	if (combinaciones4.obtenerCartaAlta() != resultado4)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testObtenerCartaAlta (CombinacionesPruebas) message=Fallo el metodo obtener carta alta al pasarle 7 cartas desordenadas" << std::endl;
	}
}

void testOrdenarCartas()
{
	Carta carta1(1, 14);
	Carta carta2(1, 8);
	Carta carta3(2, 4);
	Carta carta4(3, 10);
	Carta carta5(2, 3);
	Carta carta6(4, 1);
	Carta carta7(3, 5);
	
	Combinaciones combinaciones1;
	list<Carta> jugador1 = {carta7, carta2};
	list<Carta> comunitarias1 = {carta6, carta5, carta3};
	combinaciones1.setCartas(jugador1, comunitarias1);
	combinaciones1.ordenarCartas();
	list<Carta> resultado1 = {carta6, carta5, carta3, carta7, carta2};
	if (combinaciones1.getCartas() != resultado1)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testOrdenarCartas (CombinacionesPruebas) message=Fallo el metodo ordenar cartas al pasarle 5 cartas ordenadas" << std::endl;
	}

	Combinaciones combinaciones2;
	list<Carta> jugador2 = {carta7};
	list<Carta> comunitarias2 = {carta6};
	combinaciones2.setCartas(jugador2, comunitarias2);
	combinaciones2.ordenarCartas();
	list<Carta> resultado2 = {carta6, carta7};
	if (combinaciones1.getCartas() != resultado2)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testOrdenarCartas (CombinacionesPruebas) message=Fallo el metodo ordenar cartas al pasarle 2 cartas ordenadas" << std::endl;
	}

	Combinaciones combinaciones3;
	list<Carta> jugador3 = {carta1, carta2};
	list<Carta> comunitarias3 = {carta3};
	combinaciones3.setCartas(jugador3, comunitarias3);
	combinaciones3.ordenarCartas();
	list<Carta> resultado3 = {carta3, carta2, carta1};
	if (combinaciones3.getCartas() != resultado3)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testOrdenarCartas (CombinacionesPruebas) message=Fallo el metodo ordenar cartas al pasarle 3 cartas desordenadas" << std::endl;
	}

	Combinaciones combinaciones4;
	list<Carta> jugador4 = {carta1, carta2};
	list<Carta> comunitarias4 = {carta3, carta4, carta5, carta6, carta7};
	combinaciones4.setCartas(jugador4, comunitarias4);
	combinaciones4.ordenarCartas();
	list<Carta> resultado4 = {carta6, carta5, carta3, carta7, carta2, carta4, carta1};
	if (combinaciones4.getCartas() != resultado4)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testOrdenarCartas (CombinacionesPruebas) message=Fallo el metodo ordenar cartas al pasarle 7 cartas desordenadas" << std::endl;
	}
}

void testSetGetCartas()
{
	Carta cartaJugador1(1,2);
	Carta cartaJugador2(2, 3);
	Carta cartaComunitaria1(1, 8);
	Carta cartaComunitaria2(2, 14);
	Carta cartaComunitaria3(3, 5);
	list<Carta> jugador = {cartaJugador1, cartaJugador2};
	list<Carta> comunitarias = {cartaComunitaria1, cartaComunitaria2, cartaComunitaria3};
	Combinaciones combinaciones;
	combinaciones.setCartas(jugador, comunitarias);
	list<Carta> resultado1 = {cartaComunitaria1, cartaComunitaria2, cartaComunitaria3, cartaJugador1, cartaJugador2};
	if (combinaciones.getCartas() != resultado1)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testSetCartas (CombinacionesPruebas) message=Fallaron los metodos set/get Cartas" << std::endl;
	}
}

void testSetGetMatrizRepeticiones()
{
	Combinaciones combinaciones;
	combinaciones.setMatrizRepeticiones();
	if (true /*check result*/)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testSetMatrizRepeticiones (CombinacionesPruebas) message=error message sample" << std::endl;
	}
}

void testSetGetNumeroMano()
{
	Combinaciones combinaciones;
	combinaciones.setNumeroMano();
	if (true /*check result*/)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testSetNumeroMano (CombinacionesPruebas) message=error message sample" << std::endl;
	}
}

void testSetGetNumeroTurno()
{
	int turno = 4;
	Combinaciones combinaciones;
	combinaciones.setNumeroTurno(turno);
	if (combinaciones.getNumeroTurno() != 4)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testSetNumeroTurno (CombinacionesPruebas) message=Fallaron los metodos set/get NumeroTurno" << std::endl;
	}
}

void testVerificarColor()
{
	Combinaciones combinaciones;
	bool result = combinaciones.verificarColor();
	if (true /*check result*/)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testVerificarColor (CombinacionesPruebas) message=error message sample" << std::endl;
	}
}

void testVerificarEscalera()
{
	Combinaciones combinaciones;
	bool result = combinaciones.verificarEscalera();
	if (true /*check result*/)
	{
		std::cout << "%TEST_FAILED% time=0 testname=testVerificarEscalera (CombinacionesPruebas) message=error message sample" << std::endl;
	}
}

int main(int argc, char** argv)
{
	std::cout << "%SUITE_STARTING% CombinacionesPruebas" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	std::cout << "%TEST_STARTED% testObtenerCartaAlta (CombinacionesPruebas)" << std::endl;
	testObtenerCartaAlta();
	std::cout << "%TEST_FINISHED% time=0 testObtenerCartaAlta (CombinacionesPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testOrdenarCartas (CombinacionesPruebas)" << std::endl;
	testOrdenarCartas();
	std::cout << "%TEST_FINISHED% time=0 testOrdenarCartas (CombinacionesPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testSetGetCartas (CombinacionesPruebas)" << std::endl;
	testSetGetCartas();
	std::cout << "%TEST_FINISHED% time=0 testSetGetCartas (CombinacionesPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testSetGetMatrizRepeticiones (CombinacionesPruebas)" << std::endl;
	testSetGetMatrizRepeticiones();
	std::cout << "%TEST_FINISHED% time=0 testSetGetMatrizRepeticiones (CombinacionesPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testSetGetNumeroMano (CombinacionesPruebas)" << std::endl;
	testSetGetNumeroMano();
	std::cout << "%TEST_FINISHED% time=0 testSetGetNumeroMano (CombinacionesPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testSetGetNumeroTurno (CombinacionesPruebas)" << std::endl;
	testSetGetNumeroTurno();
	std::cout << "%TEST_FINISHED% time=0 testSetGetNumeroTurno (CombinacionesPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testVerificarColor (CombinacionesPruebas)" << std::endl;
	testVerificarColor();
	std::cout << "%TEST_FINISHED% time=0 testVerificarColor (CombinacionesPruebas)" << std::endl;

	std::cout << "%TEST_STARTED% testVerificarEscalera (CombinacionesPruebas)" << std::endl;
	testVerificarEscalera();
	std::cout << "%TEST_FINISHED% time=0 testVerificarEscalera (CombinacionesPruebas)" << std::endl;

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	return (EXIT_SUCCESS);
}

