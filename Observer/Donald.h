#ifndef DONALD_H
#define DONALD_H

#include "Sujeto.h"
class Donald: public Sujeto
{
private:
	std::string estado;
public:
	Donald(std::string _nombre);
	void setEstado(std::string _estado);
	std::string getEstado();
};

#endif