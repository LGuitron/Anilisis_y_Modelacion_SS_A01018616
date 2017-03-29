#include "TextoSimple.h"
#include "TextoFormato.h"
#include "Impresoras.h"
#include "Imagenes.h"
#include "TarjetasPresentacion.h"

void printAllDocuments(Documents**d,int countDocs,Printers**p,int countPrinters)
{
	for(int i=0;i<countDocs;i++)
	{
		for(int j=0;j<countPrinters;j++)
		{
			d[i]->printOn(p[j]);
		}
	}
}


int main()
{

	int numDocumentos = 4;
	int numPrinters = 5;

	Documents** d = new Documents* [numDocumentos];
	Printers** p = new Printers* [numPrinters];

	d[0] = Documents::getInstance<TextoSimple>();
	d[1] = Documents::getInstance<TextoFormato>();
	d[2] = Documents::getInstance<Imagenes>();
	d[3] = Documents::getInstance<TarjetasPresentacion>();

	p[0] = new Laser();
	p[1]= new Inyeccion();
	p[2] = new PDF();
	p[3] = new Postscript();
	p[4] = new Portatil();

	printAllDocuments(d,numDocumentos,p,numPrinters);
	return 1;
}