#ifndef _CABALLO_H_
#define _CABALLO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Caballo: public Animal{
public:
    Caballo();
    Caballo( string nombre, int edad, int tamano, string personalidad );
    void mostrar() override ;
    ~Caballo();

};


#endif