#include "Dominio.h"

Dominio::Dominio(std::string nombre, std::string direccionIP)
{
	this->nombre = nombre;
	this->direccionIP = direccionIP;
}
std::string Dominio::getNombre()
{
	return nombre;
}
std::string Dominio::getDireccion()
{
	return direccionIP;
}