#include "Impresoras.h"

Laser::Laser()
{
}

Inyeccion::Inyeccion()
{
}

PDF::PDF()
{
}

Postscript::Postscript()
{
}

Portatil::Portatil()
{
}


void Printers::imprimirCon(Printers* p)
{
	p->imprimirNombre();
}

void Laser::imprimirNombre()
{
	std::cout<<" en impresora laser "<<std::endl;
}

void Inyeccion::imprimirNombre()
{
	std::cout<<" en impresora de inyeccion "<<std::endl;
}

void PDF::imprimirNombre()
{
	std::cout<<" en PDF "<<std::endl;
}

void Postscript::imprimirNombre()
{
	std::cout<<" en Postscript "<<std::endl;
}

void Portatil::imprimirNombre()
{
	std::cout<<" en impresora portatil "<<std::endl;
}