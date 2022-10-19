#ifndef _LAGARTIJA_H_
#define _LAGARTIJA_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Lagartija: public Animal{
public:
    Lagartija();
    ~Lagartija();
    void mostrar();
};


#endif