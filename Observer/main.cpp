#include "PenaNieto.h"
#include "Donald.h"
#include "Reforma.h"

int main()
{
	PenaNieto pena("EPN");
	Donald don("Donald Trump");

	Reforma reforma("Reforma");

	pena.agregarObservador(&reforma);
	don.agregarObservador(&reforma);

	pena.setEstado("copete");
	don.setEstado("muro");
	return 1;
}