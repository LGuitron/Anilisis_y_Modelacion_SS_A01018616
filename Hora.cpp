#include "Hora.hpp"


Hora h;

Hora::Hora()
{
}

const std::string Hora::currentDateTime()
{
	time_t     tiempo = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&tiempo);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}