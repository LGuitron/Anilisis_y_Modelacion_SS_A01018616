#include "Menu.h"

int main()
{

	//Menu para funciones del almacen//
	Menu menu;

	//PROTOTYPE videojuegos//
	Videojuego* v = new Videojuego(12345,"Skyrim", "Bethesda", 999.0f , 5.0f);
	Videojuego* vv = v->clonar();

	//FACTORY METHOD videojuegos//
	Videojuego* vEst = Videojuego::factoryMethod<VidEstrategia>();

	//SINGLETON almacen//	
	Almacen* almacen = Almacen::crearInventario();

	return 0;
}