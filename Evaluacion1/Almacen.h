#include <vector>
#include "Videojuego.h"

class Almacen
{
	private:
		Almacen();
		static Almacen* instancia;
		vector<Videojuego> lista;
		unsigned numeroElementos;

		//Variable estatica para asignar numero de serie a videojuegos
		static unsigned nuevoIDvideoJuego;

	public: 
		//Almacen se crea con singleton//
		static Almacen* crearInventario(unsigned _tamanio);
		void agregarVideojuego(string _nombre, string _estudioCreador,float _precio, float _estrellas);
		void eliminarVideojuego(unsigned numSerie);
		void eliminarVideojuego(string nombre);
		Videojuego buscarVideojuego(unsigned numSerie);
		Videojuego buscarVideojuego(string nombre);
		void rehacer();
		unsigned getNumElementos();
		void imprimirElementos();
};
