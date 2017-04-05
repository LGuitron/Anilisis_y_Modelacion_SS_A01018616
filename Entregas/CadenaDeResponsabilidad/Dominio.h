#include <string>

class Dominio
{
private:
	std::string nombre;
	std::string direccionIP;

public:
	Dominio(std::string nombre, std::string direccionIP);
	std::string getNombre();
	std::string getDireccion();
};