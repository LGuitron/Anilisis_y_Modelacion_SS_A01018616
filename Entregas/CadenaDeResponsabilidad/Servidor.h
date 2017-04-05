#include <string>
#include <vector>
#include <iostream>
#include "Dominio.h"

class Servidor
{
private:
	std::string nombre;
	std::vector<Dominio> dominios;
	std::string pasarPeticion(std::string peticion);
	Servidor* sucesor;

public:
	Servidor(std::string nombre);
	std::string manejarPeticion(std::string peticion);
	void agregarDominio(Dominio nuevoDominio);
	void agregarSucesor(Servidor* sucesor);
};