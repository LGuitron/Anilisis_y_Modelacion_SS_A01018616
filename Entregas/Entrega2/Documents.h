#ifndef DOCUMENTS_H
#define DOCUMENTS_H

#include "Impresoras.h"
#include <iostream>
#include <string>

class Documents
{	
	public:
		std::string tipoDocumento;

	template<class T>
    static T* getInstance()
    {
        static T instance;
        return &instance;
    }

	public:
		virtual void printOn(Printers* p)=0;
};

#endif