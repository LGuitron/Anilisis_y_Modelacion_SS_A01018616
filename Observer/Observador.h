#ifndef OBSERVADOR_H
#define OBSERVADOR_H


#include <string>
#include <iostream>

class Sujeto;

class Observador
{
	protected:
		std::string nombre;
	public:
		virtual void actualizar(Sujeto& sujeto) = 0;
};

#endif
#include "Sujeto.h"