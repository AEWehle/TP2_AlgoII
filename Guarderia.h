#ifndef _GUARDERIA_H
#define _GUARDERIA_H
#include <string>
#include "Animal.h"
using namespace std; 

struct Guarderia{
    Animal ** lista_de_animales;
    int cantidad_de_animales;
    bool hubo_cambios = false;
};

#endif