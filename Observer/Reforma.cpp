#include "Reforma.h"

Reforma::Reforma(std::string _nombre)
{
	nombre=_nombre;
}

void Reforma::actualizar(Sujeto& sujeto)
{
	std::cout<<nombre <<" publica el ultimo estado de "<<sujeto.getNombre()<<" que es "<<sujeto.getEstado()<<std::endl;
}