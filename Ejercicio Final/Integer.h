#include "ManejadorAsignaciones.h"
#include <ostream>

class Integer : public ManejadorAsignaciones
{
    public:
      int valor;
      Integer(int valor);
      Integer& operator = (int nuevoValor);
      friend std::ostream& operator<< (std::ostream& stream, const Integer& entero);
};
