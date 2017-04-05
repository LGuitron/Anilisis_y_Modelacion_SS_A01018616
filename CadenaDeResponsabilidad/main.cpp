#include "Servidor.h"
#include <iostream>

int main()
{

	//Dominios//
	Dominio google("google.com","8.8.8.8");
	Dominio wikipedia("wikipedia.com","208.80.153.224");
	Dominio facebook("facebook.com","31.13.66.36");
	Dominio youtube("youtube.com","201.151.207.29");
	Dominio twitter("twitter.com","104.244.42.193");
	Dominio blackboard("miscursos.itesm.mx","10.2.5.4");
	Dominio NFL("nfl.com","104.95.88.219");
	Dominio slack("slack.com","54.192.4.118");
	Dominio steam("steamcommunity.com","104.85.6.86");
	Dominio stackoverflow("stackoverflow.com","151.101.65.69");

	//Servidores//
	//A//
	Servidor A("A");
	A.agregarDominio(google);
	A.agregarDominio(wikipedia);

	//B//
	Servidor B("B");
	B.agregarDominio(facebook);
	B.agregarDominio(youtube);

	//C//
	Servidor C("C");
	C.agregarDominio(twitter);
	C.agregarDominio(blackboard);

	//D//
	Servidor D("D");
	D.agregarDominio(NFL);
	D.agregarDominio(slack);

	//E//
	Servidor E("E");
	E.agregarDominio(steam);
	E.agregarDominio(stackoverflow);

	//Sucesores//
	A.agregarSucesor(&B);
	B.agregarSucesor(&C);
	C.agregarSucesor(&D);
	D.agregarSucesor(&E);

	//Peticion al tercer DNS//
	std::string resultado0 = A.manejarPeticion("twitter.com");
	std::cout<<resultado0<<std::endl;

	//Peticion al ultimo DNS//
	std::string resultado = A.manejarPeticion("stackoverflow.com");
	std::cout<<resultado<<std::endl;

	//Peticion fallida//
	std::string resultado2 = A.manejarPeticion("noExiste.com");
	std::cout<<resultado2<<std::endl;

	return 1;
}