#include "TextoFormato.h"

TextoFormato::TextoFormato()
{
	tipoDocumento = "texto formato";
}

void TextoFormato::printOn(Printers* p)
{
	std::cout<<"Se imprimio un documento de tipo "<<tipoDocumento;
	p->imprimirCon(p);
}