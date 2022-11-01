#ifndef _ROEDOR_H_
#define _ROEDOR_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Roedor: public Animal{
public:
    Roedor();
    Roedor( string nombre, int edad, string tamano, string personalidad );
    void mostrar() override;
    void duchar() override;
    void ensuciar() override;
    Especie resolver_especie() override;
    ~Roedor();
};


#endif