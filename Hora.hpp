#include <time.h>
#include <iostream>
#include <string>
#include <stdio.h>

class Hora
{

private: 
	time_t tiempo;
	static Hora* instancia;
	Hora();

public: 
	static Hora* getHora();
	const std::string printFechaHora(); 
};