#ifndef _LAGARTIJA_H_
#define _LAGARTIJA_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Lagartija: public Animal{
public:
    Lagartija();
    Lagartija( string nombre, int edad, string tamano, string personalidad );
    ~Lagartija();
};


#endif