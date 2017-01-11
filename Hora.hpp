#include <time.h>
#include <iostream>
#include <string>
#include <stdio.h>

class Hora
{

private: 
	time_t tiempo;

public: 
	Hora();
	const std::string currentDateTime(); 
};

extern Hora h;