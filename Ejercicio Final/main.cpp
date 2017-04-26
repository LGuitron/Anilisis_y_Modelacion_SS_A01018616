#include "ClaseA.h"
#include <iostream>

int main()
{
  //Ejemplo 1//
  ClaseA a;
  ClaseA b;
  b = a;
  *(a.entero) = 5;
  std::cout<<*(b.entero)<<std::endl;

  //Ejemplo 2//
  ClaseA* c = new ClaseA;
  ClaseA* d = c;
  delete c;
  delete d;

  //Ejemplo 3//
  ClaseA* e = new ClaseA;
  ClaseA* f = new ClaseA;
  e = f;
  delete e;
  delete f;

  //Ejemplo 4//
  ClaseA* g = new ClaseA[2];
  ClaseA* h = g;
  delete g;
  delete h;

  //Ejemplo 5//
  ClaseA* i = new ClaseA[2];
  ClaseA* j = new ClaseA[2];
  i=j;
  delete i;
  delete j;

  ManejadorAsignaciones::liberarTodo();
  return 1;
}
