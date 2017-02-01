#include <iostream>
#include <cmath>

class EnteroPerfecto
{
	public:
		int valor;
		bool isPerfect;

	bool verificarNaturalPerfecto(int n)
	{
		int suma = 1;
		for(unsigned i = 2; i <=sqrt(n) ;i++)
		{
			if(n%i==0)      	//Suma factor
			{
				suma+=i;
				if(i!=n/i)  	//Suma reciproco si es diferente//
					suma+=n/i;
			}
		}
		if(suma==n)
			return true;
		else
			return false;
	}

	public: 
	EnteroPerfecto(int _valor)
	{
		valor = _valor;
		isPerfect = verificarNaturalPerfecto(valor);
	}
	EnteroPerfecto()
	{
		valor = 0;
		isPerfect = false;
	}

	void operator = (int numero)
	{
		if(verificarNaturalPerfecto(numero))
			return;
		
		//de lo contrario lanzar una exepcion//
		//else

	}
};	

class ArregloNNP
{
	private:
		int tamanio;
		EnteroPerfecto* arreglo;

	 public:
	 	ArregloNNP(unsigned _tamanio)
	 	{
	 		tamanio=_tamanio;
	 		arreglo = new EnteroPerfecto[tamanio];
	 		for(unsigned i=0;i<tamanio;i++)
	 		{
	 			arreglo[i]=0;
	 		}
	 	}

	 	bool verificarNaturalPerfecto(int n)
	 	{
	 		int suma = 1;
	 		for(unsigned i = 2; i <=sqrt(n) ;i++)
	 		{
	 			if(n%i==0)      	//Suma factor
	 			{
	 				suma+=i;
	 				if(i!=n/i)  	//Suma reciproco si es diferente//
	 					suma+=n/i;
	 			}
	 		}
	 		if(suma==n)
	 			return true;
	 		else
	 			return false;
	 	}
		
		EnteroPerfecto& operator [] (int indice)
		{
			if(indice>0 && indice<tamanio)
				return arreglo[indice];
			//de lo contrario lanzar una excepcion
			//else
		}
};

int main()
{
	ArregloNNP a(6);
	//a[3] = 6;
	//a[4] = 7;


return 0;
}

