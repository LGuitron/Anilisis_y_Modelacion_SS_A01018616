#include "ManejadorAsignaciones.h"
std::vector<void*> ManejadorAsignaciones::direccionesAsignadas = {nullptr};
unsigned ManejadorAsignaciones::indiceAliberar = 0;

//Funcion para verificar si un apuntador fue liberado o no//
bool ManejadorAsignaciones::apuntadorLiberado(void* ptr)
{
    for (std::vector<void*>::iterator it = direccionesAsignadas.begin() ; it != direccionesAsignadas.end(); ++it)
    {
      //El apuntador no ha sido liberado//
      if(*it==ptr)
      {
        indiceAliberar = it-direccionesAsignadas.begin();
        return false;
      }
    }
    return true;
}

void ManejadorAsignaciones::liberarMemoria()
{
    direccionesAsignadas.erase(direccionesAsignadas.begin()+indiceAliberar);
}

//Operadores new//
void * ManejadorAsignaciones::operator new(size_t tamanio)throw (std::bad_alloc)
{
   void *p = malloc(tamanio);
   if(p)
   {
     direccionesAsignadas.push_back(p);
     return p;
   }
   else
      throw std::bad_alloc();

}

void* ManejadorAsignaciones::operator new[]( std::size_t tamanio)throw (std::bad_alloc)
{
  void *a = malloc(tamanio);
  if(a)
  {
    direccionesAsignadas.push_back(a);
    return a;
  }
  else
    throw std::bad_alloc();
}

//Operadores delete//
void ManejadorAsignaciones::operator delete(void* ptr) throw()
{
    if(!apuntadorLiberado(ptr))
    {
      std::free(ptr);
      liberarMemoria();
    }
}

void ManejadorAsignaciones::operator delete[](void* ptr) throw()
{
    if(!apuntadorLiberado(ptr))
    {
      std::free(ptr);
      liberarMemoria();
    }
}

void ManejadorAsignaciones::liberarTodo()
{
  while (direccionesAsignadas.size()>0)
  {
      void* ptr = direccionesAsignadas.back();
      direccionesAsignadas.pop_back();
      std::free(ptr);
  }
}
