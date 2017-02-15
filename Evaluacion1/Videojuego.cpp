#include "Videojuego.h"

	Videojuego::Videojuego(){}
	Videojuego::Videojuego(unsigned _numSerie,string _nombre, string _estudioCreador,float _precio, float _estrellas)
	{
		numSerie = _numSerie;
		nombre = _nombre;
		estudioCreador = _estudioCreador;
		precio = _precio;
		estrellas = _estrellas;
	}
	string Videojuego::getNombre(){return nombre;}
	string Videojuego::getEstudio(){return estudioCreador;}
	int Videojuego::getNumSerie(){return numSerie;}
	float Videojuego::getPrecio(){return precio;}
	float Videojuego::getEstrellas(){return estrellas;}


	Videojuego* Videojuego::clonar(){}
	void Videojuego::Concepcion(){}
	void Videojuego::Disenio(){}
	void Videojuego::Planificacion(){}
	void Videojuego::Produccion(){}
	void Videojuego::Pruebas(){}

	bool Videojuego::operator < (const Videojuego &otro) const
	{
		if (precio < otro.precio)
		    return true;
		return false;
	}

	void VidEstrategia::Concepcion()
	{
		cout<<"Concepcion Videojuego de Estrategia"<<endl;
	}
	void VidEstrategia::Disenio()
	{
		cout<<"Disenio Videojuego de Estrategia"<<endl;
	}
	void VidEstrategia::Planificacion()
	{
		cout<<"Planificacion Videojuego de Estrategia"<<endl;
	}
	void VidEstrategia::Produccion()
	{
		cout<<"Produccion Videojuego de Estrategia"<<endl;
	}
	void VidEstrategia::Pruebas()
	{
		cout<<"Pruebas Videojuego de Estrategia"<<endl;
	}



	void VidAventura::Concepcion()
	{
		cout<<"Concepcion Videojuego de Aventura"<<endl;
	}
	void VidAventura::Disenio()
	{
		cout<<"Disenio Videojuego de Aventura"<<endl;
	}
	void VidAventura::Planificacion()
	{
		cout<<"Planificacion Videojuego de Aventura"<<endl;
	}
	void VidAventura::Produccion()
	{
		cout<<"Produccion Videojuego de Aventura"<<endl;
	}
	void VidAventura::Pruebas()
	{
		cout<<"Pruebas Videojuego de Aventura"<<endl;
	}


	void VidAprendizaje::Concepcion()
	{
		cout<<"Concepcion Videojuego de Aprendizaje"<<endl;
	}
	void VidAprendizaje::Disenio()
	{
		cout<<"Disenio Videojuego de Aprendizaje"<<endl;
	}
	void VidAprendizaje::Planificacion()
	{
		cout<<"Planificacion Videojuego de Aprendizaje"<<endl;
	}
	void VidAprendizaje::Produccion()
	{
		cout<<"Produccion Videojuego de Aprendizaje"<<endl;
	}
	void VidAprendizaje::Pruebas()
	{
		cout<<"Pruebas Videojuego de Aprendizaje"<<endl;
	}