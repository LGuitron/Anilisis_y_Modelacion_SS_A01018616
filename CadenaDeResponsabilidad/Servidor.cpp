#include "Servidor.h"

Servidor::Servidor(std::string nombre)
{
	this->nombre = nombre;
	sucesor = nullptr;
}

std::string Servidor::manejarPeticion(std::string peticion)
{
	for(unsigned i=0;i<dominios.size();i++)
	{
		if(dominios[i].getNombre()==peticion)
		{
			std::cout<<"Servidor "<<nombre<<" tiene el dominio de "<<peticion<<": ";
			return dominios[i].getDireccion();
		}
	}
	return pasarPeticion(peticion);
}

void Servidor::agregarDominio(Dominio nuevoDominio)
{
	dominios.push_back(nuevoDominio);
}

void Servidor::agregarSucesor(Servidor* sucesor)
{
	this->sucesor = sucesor;
}

std::string Servidor::pasarPeticion(std::string peticion)
{
	if(sucesor!=nullptr)
	{
		return sucesor->manejarPeticion(peticion);
	}
	else
	{
		return "No se encontro la pagina solicitada";
	}
}