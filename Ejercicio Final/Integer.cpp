#include "Integer.h"

Integer::Integer(int _valor)
{
    this->valor = valor;
}

Integer& Integer::operator = (int nuevoValor)
{
    valor = nuevoValor;
}
std::ostream& operator<< (std::ostream& stream, const Integer& entero)
{
    stream<<entero.valor;
}
