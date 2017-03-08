#include "Televisa.h"

Televisa::Televisa(std::string _nombre)
{
	nombre=_nombre;
}


void Televisa::actualizar(Sujeto& sujeto)
{
	std::cout<<nombre <<" publica el ultimo estado de "<<sujeto.getNombre()<<" que es "<<sujeto.getEstado()<<std::endl;
}