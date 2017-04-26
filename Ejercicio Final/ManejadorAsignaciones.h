#include <vector>
#include <cstddef>
#include <cstdlib>

#ifndef MANEJADORASIGNACIONES_H
#define MANEJADORASIGNACIONES_H

class ManejadorAsignaciones
{
  private:
       static std::vector<void*> direccionesAsignadas;
       static unsigned indiceAliberar;
       static void liberarMemoria();
       static bool apuntadorLiberado(void* ptr);

  public:

       //Operadores new y delete//
       void* operator new(std::size_t tamanio) throw (std::bad_alloc);
       void* operator new[]( std::size_t tamanio)  throw (std::bad_alloc);
       void operator delete(void* ptr) throw();
       void operator delete[](void* ptr) throw();

       //Funcion para liberar todos los apuntadores//
       static void liberarTodo();
};

#endif
