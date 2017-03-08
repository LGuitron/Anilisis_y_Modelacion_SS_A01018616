#include "Sujeto.h"

void Sujeto::notificar()
{
	for(int i=0;i<observadores.size();i++)
	{
		observadores[i]->actualizar(*this);
	}
}

void Sujeto::setNombre(std::string _nombre)
{
	nombre = _nombre;
}

std::string Sujeto::getNombre()
{
	return nombre;
}

void Sujeto::agregarObservador(Observador* observador)
{
	observadores.push_back(observador);
}