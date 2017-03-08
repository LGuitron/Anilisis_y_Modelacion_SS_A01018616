#include "PenaNieto.h"

PenaNieto::PenaNieto(std::string _nombre)
{
	nombre = _nombre;
}

void PenaNieto::setEstado(std::string _estado)
{
	estado=_estado;
	notificar();
}

std::string PenaNieto::getEstado()
{
	return estado;
}