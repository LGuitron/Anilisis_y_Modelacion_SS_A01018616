#include "Hora.hpp"

Hora* Hora::instancia = 0;

Hora::Hora()
{
	instancia = this;
}

const std::string  Hora::printFechaHora()
{
	time_t tiempo = time(0);
	struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&tiempo);
    strftime(buf, sizeof(buf), "%r", &tstruct);
    return buf;
}

Hora* Hora::getHora()
{
	static Hora instancia;
	return &instancia;
}