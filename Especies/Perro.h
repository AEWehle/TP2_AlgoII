#ifndef _PERRO_H_
#define _PERRO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Perro: public Animal{
public:
    Perro();
    ~Perro();
    void mostrar();
};


#endif