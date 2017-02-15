#include "Almacen.h"



Almacen* Almacen::instancia = nullptr;
unsigned Almacen::nuevoIDvideoJuego = 1;


	Almacen::Almacen(){}

	//Almacen se crea con singleton//
	Almacen* Almacen::crearInventario()
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
			{
				operacionesEliminar.push(lista[i]);		//Agrega videojuego eliminado al stack//
				lista.erase(lista.begin() + i);
			}
		}
	}
	void Almacen::eliminarVideojuego(string nombre)
	{
		for(unsigned i=0; i<lista.size(); i++)
		{
			if(nombre==lista[i].getNombre())
			{
				operacionesEliminar.push(lista[i]);		//Agrega videojuego eliminado al stack//
				lista.erase(lista.begin() + i);
			}
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

	void Almacen::ordenar(bool menorAmayor)
	{
		sort(lista.begin(),lista.end());  //Ordena de menor a mayor
		if(!menorAmayor)				  //Cambia el orden de mayor a menor
			reverse(lista.begin(),lista.end()); 

	}

	void Almacen::rehacer()
	{
		for(int i = 0; i<3; i++)
		{
			if(operacionesEliminar.size()>0)
			{
				lista.push_back(operacionesEliminar.top());
				operacionesEliminar.pop();
			}
			else
				break;
		}
	}
	unsigned Almacen::getNumElementos()
	{
		return lista.size();
	}
	void Almacen::imprimirElementos()
	{
		for(unsigned i=0; i<lista.size(); i++)
		{
			cout<<lista[i].getNombre()<<" "<<lista[i].getEstudio()<<" "<<lista[i].getNumSerie()<<" "<<lista[i].getEstrellas()<<" "<<lista[i].getPrecio()<<endl;
		}
		cout<<endl;
	}
