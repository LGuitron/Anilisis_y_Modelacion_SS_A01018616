#include "Almacen.h"

class Menu
{
	private:
		bool continuar;
		static Almacen* almacen;
		void desplegarResultadoBusqueda(Videojuego vj);

	public:
		Menu();
		void desplegarOpciones();
		void opcionSeleccionada(string opcion);
		void agregarVideojuego();
		void eliminarVideojuego();
		void buscarVideojuego();
		void ordenarAlmacen();
		void imprimirTamanio();

};