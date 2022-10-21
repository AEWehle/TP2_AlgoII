#ifndef _GATO_H_
#define _GATO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Gato: public Animal{
public:
    Gato();
    Gato( string nombre, int edad, int tamano, string personalidad );
    void mostrar() override;
    ~Gato();
};


#endif