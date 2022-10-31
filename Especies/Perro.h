#ifndef _PERRO_H_
#define _PERRO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Perro: public Animal{
public:
    Perro();
    Perro( string nombre, int edad, string tamano, string personalidad );
    void mostrar() override;
    Especie resolver_especie() override;
    ~Perro();
};


#endif