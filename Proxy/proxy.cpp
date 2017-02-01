#include<iostream>
#include <cmath>

using namespace std;

class ArrayNatPerfect;

class Proxy
{
    ArrayNatPerfect& arr;
    int idx;
public:
    Proxy(ArrayNatPerfect& arr, int idx) : arr(arr), idx(idx){}
    Proxy& operator = (int value);
    friend ostream& operator<<(ostream&, Proxy&&); 
};

class ArrayNatPerfect
{
private:
    int * arr;
    int size;
    
public:
    friend class Proxy;
    ArrayNatPerfect(int size) : size(size)
    {
        arr = new int[size+1]; //EL MAS 1 ES PARA REDIRIGIR ERRORES
    }
    Proxy operator[](int index)
    {
        if(index < 0 || index >= size)
        {
            cout << "Error: No hay índices negativos" << endl;
            return Proxy(*this, size);
        }
        return Proxy(*this, index);
    }
    friend ostream& operator<<(ostream& os, Proxy&& p);
};


bool verificarNaturalPerfecto(int n)
{
	int suma = 1;			//Se suma el 1 automaticamente	
	for(unsigned i = 2; i <=sqrt(n) ;i++)
	{
		if(n%i==0)      	//Suma factor
		{
			suma+=i;
			if(i!=n/i)  	//Suma reciproco si es diferente//
				suma+=n/i;
		}
	}
	if(suma==n && n!= 1) 	//Se excluye al 1 porque no es natural perfecto//	
		return true;
	else
		return false;
}


Proxy& Proxy::operator = (int value)
{
		if(verificarNaturalPerfecto(value))
        {
            arr.arr[idx] = value;
        }
        else
        {
            cout << "Eror no es natural perfecto" << endl;
        }
        return *this;
}

ostream& operator<<(ostream& os, Proxy&& p)
{
    os << p.arr.arr[p.idx];
    return os;
}



int main()
{
    ArrayNatPerfect a(5);
    a[0]=1;
    a[5]= 2;
    a[-1] = -1;
    a[4] = 6;
    a[3] = 28;
    cout << a[3]<<endl;
    
}