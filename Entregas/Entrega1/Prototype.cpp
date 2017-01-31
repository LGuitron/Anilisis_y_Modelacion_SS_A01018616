#include <iostream>
using namespace std;

class Personaje
{
	public:
		virtual void correr() = 0;
		virtual Personaje* clonar() = 0;

		template <class SubClase>
		static Personaje* factoryMethod()
		{
			return SubClase::getInstance();
		}
};

template <class SubClase>
class ClonPersonaje : public Personaje
{

	public:
		virtual Personaje* clonar()
		{
			return new SubClase(dynamic_cast<SubClase&>(*this));
		}
};

class Principe : public ClonPersonaje<Principe>
{
	private:
		Principe(){}
		static Principe* instance;

	public:
		void seleccionarArma();
		void atacar();
		void correr()
		{
			cout << "El principe corre r?ido" << endl;
		}
		static Principe* getInstance()
		{
			if(instance==NULL)
				instance = new Principe;
			return instance;
		}
};
Principe* Principe::instance = NULL;


class Princesa : public ClonPersonaje<Princesa>
{
	private:
		Princesa(){}
		static Princesa* instance;

	public:
		void gritar();
		void correr()
		{
			cout << "La princesa corre medio lento" << endl;
		}

		static Princesa* getInstance()
		{
			if(instance==NULL)
				instance = new Princesa;
			return instance;
		}
};
Princesa* Princesa::instance = NULL;

class Villano : public ClonPersonaje<Villano>
{
	private:
		Villano(){}
		static Villano* instance;

	public:
		void atacar();
		void atraparPricnesa();
		void correr()
		{
			cout << "El villano no necesita correr" << endl;
		}
		static Villano* getInstance()
		{
			if(instance==NULL)
				instance = new Villano;
			return instance;
		}
};
Villano* Villano::instance = NULL; 

class VillanoVolador : public ClonPersonaje<VillanoVolador>
{
	private:
		VillanoVolador(){}
		static VillanoVolador* instance;

	public:
		void correr()
		{
			cout << "Tambien puede volar" << endl;
		}
		static VillanoVolador* getInstance()
		{
			if(instance==NULL)
				instance = new VillanoVolador;
			return instance;
		}
};
VillanoVolador* VillanoVolador::instance = NULL; 


int main()
{
	////////////////////PRUEBAS SINGLETON Y FACTORY METHOD/////////////////////

	//Principe y princesa declarados con getInstance//
	Principe* pri = Principe::getInstance();
	Princesa* p = Princesa::getInstance();
	//Principe y princesa declarados con factory method//
	Personaje* pri2  = Personaje::factoryMethod<Principe>();
	Personaje* p2 = Personaje::factoryMethod<Princesa>();


	//Villano y villano volador declarados con factory method//
	Personaje* v = Personaje::factoryMethod<Villano>();
	Personaje* vv = Personaje::factoryMethod<VillanoVolador>();
	//Villano y villano volador declarados con getIntance//
	Villano* v2 = Villano::getInstance();
	VillanoVolador* vv2 = VillanoVolador::getInstance();


	cout<<"Funciones correr"<<endl<<endl;
	pri->correr();
	pri2->correr();
	p->correr();
	p2->correr();
	v->correr();
	v2->correr();
	vv->correr();
	vv2->correr();


	cout<<endl<<"Direcciones de memoria SINGLETON y FACTORY METHOD"<<endl<<endl;
	cout<<"Direccion principe1: "<<pri<<" Direccion principe2: "<<pri2<<endl;
	cout<<"Direccion princesa1: "<<p<<" Direccion princesa2: "<<p2<<endl;
	cout<<"Direccion villano1: "<<v<<" Direccion villano2: "<<v2<<endl;
	cout<<"Direccion VillanoVolador1: "<<vv<<" Direccion VillanoVolador2: "<<vv2<<endl;


	////////////////////////////////PRUEBAS PROTOTYPE///////////////////////////////
	cout<<endl<<"Prototype"<<endl<<endl;
	Personaje* personaje = pri->clonar();
	Personaje* personaje2 = p ->clonar();
	Personaje* personaje3 = v->clonar();
	Personaje* personaje4 = vv->clonar();

	personaje->correr();
	personaje2->correr();
	personaje3->correr();
	personaje4->correr();
	cout<<endl;

	delete personaje;
	delete personaje2;
	delete personaje3;
	delete personaje4;
	delete pri;
	delete p;
	delete v;
	delete vv;

	return 1;
}