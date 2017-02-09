#include "Almacen.h"


Almacen* Almacen::instancia = nullptr;
unsigned Almacen::nuevoIDvideoJuego = 1;

	Almacen::Almacen(){}

	//Almacen se crea con singleton//
	Almacen* Almacen::crearInventario(unsigned _tamanio)
	{
		if(instancia==nullptr)
		{
			instancia = new Almacen;
		}
		return instancia;
	}

	void Almacen::agregarVideojuego(string _nombre, string _estudioCreador,float _precio, float _estrellas)
	{
		Videojuego nuevoJuego(nuevoIDvideoJuego, _nombre, _estudioCreador, _precio,_estrellas);
		nuevoIDvideoJuego++;
		lista.push_back(nuevoJuego);
	}

	void Almacen::eliminarVideojuego(unsigned numSerie)
	{
		for(unsigned i=0; i<lista.size(); i++)
		{
			if(numSerie==lista[i].getNumSerie())
				lista.erase(lista.begin() + i);
		}
	}
	void Almacen::eliminarVideojuego(string nombre)
	{
		for(unsigned i=0; i<lista.size(); i++)
		{
			if(nombre==lista[i].getNombre())
				lista.erase(lista.begin() + i);
		}
	}

	Videojuego Almacen::buscarVideojuego(unsigned numSerie)
	{
		for(unsigned i=0; i<lista.size(); i++)
		{
			if(numSerie==lista[i].getNumSerie())
				return lista[i];
		}
		//Regresa un videojuego default si no lo encontro
		Videojuego v(999999," "," ",0.0f,0.0f);
		return v;
	}

	Videojuego Almacen::buscarVideojuego(string nombre)
	{
		for(unsigned i=0; i<lista.size(); i++)
		{
			if(nombre==lista[i].getNombre())
				return lista[i];
		}
		//Regresa un videojuego default si no lo encontro
		Videojuego v(999999," "," ",0.0f,0.0f);
		return v;
	}

	void Almacen::rehacer()
	{
		cout<<"Rehacer"<<endl;
	}
	unsigned Almacen::getNumElementos()
	{
		return lista.size();
	}
	void Almacen::imprimirElementos()
	{
		for(unsigned i=0; i<lista.size(); i++)
		{
			cout<<lista[i].getNombre()<<" "<<lista[i].getEstudio()<<" "<<lista[i].getNumSerie()<<" "<<lista[i].getEstrellas()<<" "<<lista[i].getPrecio();
		}
		cout<<endl;
	}
