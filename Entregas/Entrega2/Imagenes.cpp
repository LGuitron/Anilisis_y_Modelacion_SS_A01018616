#include "Imagenes.h"

Imagenes::Imagenes()
{
	tipoDocumento = "imagen";
}

void Imagenes::printOn(Printers* p)
{
	std::cout<<"Se imprimio un documento de tipo "<<tipoDocumento;
	p->imprimirCon(p);
}