#ifndef PENANIETO_H
#define PENANIETO_H

#include "Sujeto.h"
class PenaNieto: public Sujeto
{
private:
	std::string estado;
public:
	PenaNieto(std::string _nombre);
	void setEstado(std::string _estado);
	std::string getEstado();
};

#endif