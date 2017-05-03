#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ObjetoColision
{
	protected:
		ObjetoColision(){}

	private:
		string nombre;

	public:
		void notificarColision(ObjetoColision* otro)
		{
				if(this!=otro)		//Evita que exista una colision de un objeto con el mismo//
				{
					cout<<"______________"<<endl;
					cout<<"Nueva Colision"<<endl;
					cout<<"______________"<<endl;
					cout<<this->getNombre()<< " esta chocando con "<<otro->getNombre()<<endl;
					cout<<"Notificando colision a "<<otro->getNombre()<<endl;
					otro->recibirColision(this);
				}
		}

		void recibirColision(ObjetoColision* otro)
		{
			cout<< this->getNombre()<<" recibe informacion de colision con "<<otro->getNombre()<<endl;
		}
		void setNombre(string _nombre)
		{
			nombre = _nombre;
		}
		string getNombre()
		{
			return nombre;
		}
};


/////////////////////////////////////Naves espaciales//////////////////////////////////////////////

class Spacecraft : public ObjetoColision
{
	protected:
		Spacecraft(){}
	public:
		template <class SubClase>
		static Spacecraft* factoryMethod()
		{
			return SubClase::getInstance();
		}
};

class ExplorationShip : public Spacecraft
{
	private:
		ExplorationShip(){}
		static ExplorationShip* instance;

	public:
		static ExplorationShip* getInstance()
		{
			if(instance==NULL)
			{
				instance = new ExplorationShip;
				instance->setNombre("Nave de exploracion");
			}
			return instance;
		}
};
ExplorationShip* ExplorationShip::instance = NULL;


class ColonizationShip : public Spacecraft
{
	private:
		ColonizationShip(){}
		static ColonizationShip* instance;

	public:
		static ColonizationShip* getInstance()
		{
			if(instance==NULL)
			{
				instance = new ColonizationShip;
				instance->setNombre("Nave de colonizacion");
			}
			return instance;
		}
};

ColonizationShip* ColonizationShip::instance = NULL;

class ObservationShip : public Spacecraft
{
	private:
		ObservationShip(){}
		static ObservationShip* instance;

	public:
		static ObservationShip* getInstance()
		{
			if(instance==NULL)
			{
				instance = new ObservationShip;
				instance->setNombre("Nave de observacion");
			}
			return instance;
		}
};
ObservationShip* ObservationShip::instance = NULL;

//////////////////////////////////////Asteroides////////////////////////////////////////


class Asteroide : public ObjetoColision
{
	protected:
		Asteroide(){}
	public:
		template <class SubClase>
		static Asteroide* factoryMethod()
		{
			return SubClase::getInstance();
		}
};

class Stony : public Asteroide
{
	private:
		Stony(){}
		static Stony* instance;

	public:
		static Stony* getInstance()
		{
			if(instance==NULL)
			{
				instance = new Stony;
				instance->setNombre("Stony meteorite");
			}
			return instance;
		}
};
Stony* Stony::instance = NULL;


class Iron : public Asteroide
{
	private:
		Iron(){}
		static Iron* instance;

	public:
		static Iron* getInstance()
		{
			if(instance==NULL)
			{
				instance = new Iron;
				instance->setNombre("Iron meteorite");
			}
			return instance;
		}
};
Iron* Iron::instance = NULL;

//////////////////////////////////////Planetas////////////////////////////////////////


class Planeta : public ObjetoColision
{
	protected:
		Planeta(){}
	public:
		template <class SubClase>
		static Planeta* factoryMethod()
		{
			return SubClase::getInstance();
		}
};

class Desert : public Planeta
{
	private:
		Desert(){}
		static Desert* instance;

	public:
		static Desert* getInstance()
		{
			if(instance==NULL)
			{
				instance = new Desert;
				instance->setNombre("Desert planet");
			}
			return instance;
		}
};
Desert* Desert::instance = NULL;


class Earth : public Planeta
{
	private:
		Earth(){}
		static Earth* instance;

	public:
		static Earth* getInstance()
		{
			if(instance==NULL)
			{
				instance = new Earth;
				instance->setNombre("Earth planet");
			}
			return instance;
		}
};
Earth* Earth::instance = NULL;

int main()
{
	Spacecraft* obs = Spacecraft::factoryMethod<ObservationShip>();
	Spacecraft* exp = Spacecraft::factoryMethod<ExplorationShip>();
	Spacecraft* col = Spacecraft::factoryMethod<ColonizationShip>();

  Asteroide* sto = Asteroide::factoryMethod<Stony>();
	Asteroide* iro = Asteroide::factoryMethod<Iron>();

	Planeta* des = Planeta::factoryMethod<Desert>();
	Planeta* ear = Planeta::factoryMethod<Earth>();

	vector<ObjetoColision*> objetos;
	objetos.push_back(obs);
	objetos.push_back(exp);
	objetos.push_back(col);
	objetos.push_back(sto);
	objetos.push_back(iro);
	objetos.push_back(des);
	objetos.push_back(ear);


	//Colision todos contra todos//
	for(int i=0;i<objetos.size();i++)
	{
			for(int j=0;j<objetos.size();j++)
			{
					objetos[i]->notificarColision(objetos[j]);
			}
	}

	cout<<endl;

	delete obs;
	delete exp;
	delete col;
	delete sto;
	delete iro;
	delete des;
	delete ear;

	return 1;
}
