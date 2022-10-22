#ifndef _ROEDOR_H_
#define _ROEDOR_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Roedor: public Animal{
public:
    Roedor();
    Roedor( string nombre, int edad, int tamano, string personalidad );
    void mostrar() override;
    ~Roedor();
};


#endif