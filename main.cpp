#include "Hora.hpp"

int main()
{
	Hora* h = Hora::getHora();
	std::cout<<h->printFechaHora()<<std::endl;
	return 0;
}