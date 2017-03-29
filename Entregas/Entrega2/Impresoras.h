#ifndef PRINTERS_H
#define PRINTERS_H

#include <iostream>
#include <string>

class Laser;

//Clase visitor para metodos de impresion (tiene implementacion debido a que solo se necesita una operacion)//
class Printers
{
	public:
		virtual void imprimirCon(Printers* p);
		virtual void imprimirNombre()=0;
};


class Laser : public Printers
{
	public:
		Laser();
		void imprimirNombre();
};

class Inyeccion : public Printers
{
	public:
		Inyeccion();
		void imprimirNombre();
};


class PDF:public Printers
{
	public:
		PDF();
		void imprimirNombre();
};

class Postscript:public Printers
{
	public:
		Postscript();
		void imprimirNombre();
};

class Portatil : public Printers
{
	public:
		Portatil();
		void imprimirNombre();
};

#endif