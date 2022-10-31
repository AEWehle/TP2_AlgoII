#ifndef _CABALLO_H_
#define _CABALLO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Caballo: public Animal{
public:
    Caballo();
    Caballo( string nombre, int edad, string tamano, string personalidad );
    void mostrar() override ;
    Especie resolver_especie() override;
    ~Caballo();

};


#endif