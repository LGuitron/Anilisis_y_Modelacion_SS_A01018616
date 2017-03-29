#include "TextoSimple.h"

TextoSimple::TextoSimple()
{
	tipoDocumento = "texto simple";
}

void TextoSimple::printOn(Printers* p)
{
	std::cout<<"Se imprimio un documento de tipo "<<tipoDocumento;
	p->imprimirCon(p);
}