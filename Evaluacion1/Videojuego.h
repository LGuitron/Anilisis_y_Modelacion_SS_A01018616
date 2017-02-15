#include <string>
#include <iostream>
using namespace std;

class Videojuego
{
protected:
	string nombre;
	string estudioCreador;
	unsigned numSerie;
	float precio;
	float estrellas;

public:

	Videojuego();
	Videojuego(unsigned _numSerie,string _nombre, string _estudioCreador,float _precio, float _estrellas);
	string getNombre();
	string getEstudio();
	int getNumSerie();
	float getPrecio();
	float getEstrellas();

	virtual Videojuego* clonar();
	virtual void Concepcion();
	virtual void Disenio();
	virtual void Planificacion();
	virtual void Produccion();
	virtual void Pruebas();
	bool operator < (const Videojuego &otro) const;


	template<class Genero>
    static Videojuego* factoryMethod()
    {
        return new Genero;
    }
};

template <class Genero>
class ClonVideojuego:public Videojuego
{
	public:
		virtual Videojuego* clonar()
		{
			return new Genero(dynamic_cast<Genero&>(*this));
		}
};


class VidEstrategia:public ClonVideojuego<VidEstrategia>
{
public:
	void Concepcion();
	void Disenio();
	void Planificacion();
	void Produccion();
	void Pruebas();
};

class VidAventura:public ClonVideojuego<VidAventura>
{
public:
	void Concepcion();
	void Disenio();
	void Planificacion();
	void Produccion();
	void Pruebas();
};

class VidAprendizaje:public ClonVideojuego<VidAprendizaje>
{
public:
	void Concepcion();
	void Disenio();
	void Planificacion();
	void Produccion();
	void Pruebas();
};