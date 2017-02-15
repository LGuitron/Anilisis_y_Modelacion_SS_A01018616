#include "Menu.h"

Almacen* Menu::almacen = nullptr;

Menu::Menu()
{
	almacen = Almacen::crearInventario();
	continuar = true;
	cout<<endl<<"Almacen de videojuegos"<<endl;
	cout<<"______________________"<<endl<<endl;
	desplegarOpciones();
}

void Menu::desplegarOpciones()
{
	while(continuar)
	{
		cout<<"Selecciona una opcion:"<<endl;
		cout<<"a. Agregar Videojuego"<<endl;
		cout<<"b. Buscar videojuego"<<endl;
		cout<<"c. Eliminar videojuego"<<endl;
		cout<<"d. Imprimir almacen"<<endl;
		cout<<"e. Rehacer"<<endl;
		cout<<"f. Ordenar Almacen"<<endl;
		cout<<"g. Ver tamanio actual de almacen"<<endl;
		cout<<"h. Salir"<<endl;
		cout<<"Tu seleccion: ";
		string opcion;
		cin>>opcion;
		cout<<endl;
		opcionSeleccionada(opcion);
	}
}

void Menu::opcionSeleccionada(string opcion)
{
	if(opcion == "a")
		agregarVideojuego();

	else if(opcion == "b")
		buscarVideojuego();

	else if(opcion == "c")
		eliminarVideojuego();

	else if(opcion == "d")
		almacen->imprimirElementos();

	else if(opcion == "e")
		almacen->rehacer();

	else if(opcion == "f")
		ordenarAlmacen();

	else if(opcion == "g")
		imprimirTamanio();

	else if(opcion == "h")
		continuar = false;

	else
		cout<<"La opcion escogida no existe"<<endl;
}

void Menu::agregarVideojuego()
{
	string nombre;
	string estudio;
	string precio;
	string estrellas;

	cout<<endl<<"Introduce el nombre del juego: ";
	cin>>nombre;
	cout<<endl<<"Introduce el nombre del estudio desarrollador:  ";
	cin>>estudio;
	cout<<endl<<"Introduce el precio: ";
	cin>>precio;
	cout<<endl<<"Introduce el numero de estrellas del juego: ";
	cin>>estrellas;
	almacen->agregarVideojuego(nombre,estudio,stof(precio),stof(estrellas));
	cout<<endl;
}

void Menu::eliminarVideojuego()
{
	string opcion;
	string opcion2;
	cout<<"Selecciona una opcion:"<<endl;
	cout<<"Eliminar juego por:"<<endl;
	cout<<"a. id"<<endl;
	cout<<"b. Nombre"<<endl;
	cout<<"Tu seleccion: ";
	cin>>opcion;
	cout<<endl;

	//Buscar videojuego por numero de serie//
	if(opcion == "a")
	{
		cout<<"Introduce el numero de serie del juego que quieres eliminar"<<endl;
		cin>>opcion2;
		almacen->eliminarVideojuego(stoul(opcion2));
	}

	//Buscar videojuego por nombre//
	else if(opcion == "b")														
	{
		cout<<"Introduce el nombre del juego que quieres eliminar"<<endl;
		cin>>opcion2;
		almacen->eliminarVideojuego(opcion2);
	}
	else
		cout<<"Opcion invalida"<<endl;
}

void Menu::buscarVideojuego()
{
	string opcion;
	string opcion2;
	cout<<"Selecciona una opcion:"<<endl;
	cout<<"Buscar juego por:"<<endl;
	cout<<"a. id"<<endl;
	cout<<"b. Nombre"<<endl;
	cout<<"Tu seleccion: ";
	cin>>opcion;
	cout<<endl;

	//Buscar videojuego por numero de serie//
	if(opcion == "a")
	{
		cout<<"Introduce el numero de serie del juego que buscas"<<endl;
		cin>>opcion2;
		Videojuego resBusqueda = almacen->buscarVideojuego(stoul(opcion2));
		desplegarResultadoBusqueda(resBusqueda);
	}

	//Buscar videojuego por nombre//
	else if(opcion == "b")														
	{
		cout<<"Introduce el nombre del juego que buscas"<<endl;
		cin>>opcion2;
		Videojuego resBusqueda = almacen->buscarVideojuego(opcion2);
		desplegarResultadoBusqueda(resBusqueda);
	}
	else
		cout<<"Opcion invalida"<<endl;
}

void Menu::desplegarResultadoBusqueda(Videojuego vj)
{
		if(vj.getNombre()==" ")
			cout<<"Videojuego no encontrado"<<endl;
		else
		{
			cout<<"Resultado de la busqueda: "<<endl;
			cout<<"Numero de Serie: "<<vj.getNumSerie()<<endl;
			cout<<"Nombre: "<<vj.getNombre()<<endl;
			cout<<"Estudio: "<<vj.getEstudio()<<endl;
			cout<<"Precio: "<<vj.getNumSerie()<<endl;
			cout<<"Estrellas: "<<vj.getNumSerie()<<endl;
			cout<<endl;
		}
}

void Menu::imprimirTamanio()
{
	cout<<endl<<"El tamanio actual del almacen es de "<<almacen->getNumElementos()<<endl<<endl;
}

void Menu::ordenarAlmacen()
{
	string opcion;
	cout<<"Selecciona una opcion: "<<endl;
	cout<<"a. Ordenar elementos por costo de mayor a menor"<<endl;
	cout<<"b. Ordenar elementos por costo de menor a mayor"<<endl;
	cin>>opcion;
	if(opcion=="a")
		almacen->ordenar(0);
	else if(opcion=="b")
		almacen->ordenar(1);
	else
		cout<<"Opcion invalida"<<endl;
}