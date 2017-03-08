#include "Donald.h"

Donald::Donald(std::string _nombre)
{
	nombre = _nombre;
}

void Donald::setEstado(std::string _estado)
{
	estado=_estado;
	notificar();
}

std::string Donald::getEstado()
{
	return estado;
}