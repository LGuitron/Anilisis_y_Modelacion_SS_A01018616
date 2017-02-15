#include <vector>
#include <algorithm>
#include <stack>
#include "Videojuego.h"

class Almacen
{
	private:
		Almacen();
		static Almacen* instancia;
		vector<Videojuego> lista;
		stack<Videojuego> operacionesEliminar;
		unsigned numeroElementos;

		//Variable estatica para asignar numero de serie a videojuegos
		static unsigned nuevoIDvideoJuego;

	public: 
		//Almacen se crea con singleton//
		static Almacen* crearInventario();
		void agregarVideojuego(string _nombre, string _estudioCreador,float _precio, float _estrellas);
		void eliminarVideojuego(unsigned numSerie);
		void eliminarVideojuego(string nombre);
		Videojuego buscarVideojuego(unsigned numSerie);
		Videojuego buscarVideojuego(string nombre);
		void rehacer();
		void ordenar(bool menorAmayor);		//Con true se ordena de menor a mayor, con false se ordena de mayor a menor//
		unsigned getNumElementos();
		void imprimirElementos();
};
