#ifndef TELEVISA_H
#define TELEVISA_H

#include "Observador.h"


class Sujeto;

class Televisa:public Observador
{
public:
	Televisa(std::string _nombre);
	void actualizar(Sujeto& sujeto);
};
#endif