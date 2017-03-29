#include "TarjetasPresentacion.h"

TarjetasPresentacion::TarjetasPresentacion()
{
	tipoDocumento = "tarjeta de presentacion";
}

void TarjetasPresentacion::printOn(Printers* p)
{
	std::cout<<"Se imprimio un documento de tipo "<<tipoDocumento;
	p->imprimirCon(p);
}