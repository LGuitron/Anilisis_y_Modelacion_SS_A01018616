#include "PenaNieto.h"
#include "Donald.h"
#include "Reforma.h"
#include "Televisa.h"

int main()
{
	PenaNieto pena("EPN");
	Donald don("Donald Trump");

	Reforma reforma("Reforma");
	Televisa tel("Televisa");
	
	pena.agregarObservador(&reforma);
	pena.agregarObservador(&tel);
	don.agregarObservador(&reforma);

	pena.setEstado("copete");
	don.setEstado("muro");
	return 1;
}
