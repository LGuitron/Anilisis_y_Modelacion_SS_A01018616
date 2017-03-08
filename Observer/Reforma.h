#ifndef REFORMA_H
#define REFORMA_H

#include "Observador.h"


class Sujeto;

class Reforma:public Observador
{
public:
	Reforma(std::string _nombre);
	void actualizar(Sujeto& sujeto);
};
#endif
