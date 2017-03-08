#ifndef SUJETO_H
#define SUJETO_H


#include <string>
#include <iostream>
#include <vector>
#include "Observador.h"

class Sujeto
{
protected:
	std::string nombre;
	std::vector <Observador*> observadores;
public:
	void notificar();
	void setNombre(std::string _nombre);
	std::string getNombre();
	virtual void setEstado(std::string _estado)=0;
	virtual std::string getEstado()=0;
	void agregarObservador(Observador* observador);
};
#endif