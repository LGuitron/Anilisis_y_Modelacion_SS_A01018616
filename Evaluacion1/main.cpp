#include "Almacen.h"

int main()
{

	Videojuego* v = new Videojuego(12345,"Skyrim", "Bethesda", 999.0f , 5.0f);
	Videojuego* vv = v->clonar();

	Videojuego* vEst = Videojuego::factoryMethod<VidEstrategia>();

	Almacen* almacen = Almacen::crearInventario(10);
	almacen->agregarVideojuego("Skyrim", "Bethesda", 999.0f , 5.0f);
	almacen->imprimirElementos();

	cout<<"Cantidad de juegos: "<<almacen->getNumElementos()<<endl;



	Videojuego v1 = almacen->buscarVideojuego("Skyrim");
	cout<<"Resultado busqueda: "<<v1.getNombre()<<endl;

	Videojuego v2 = almacen->buscarVideojuego("a");
	cout<<"Resultado busqueda: "<<v2.getNombre()<<endl;

	almacen->eliminarVideojuego("Skyrim");





	return 0;
}