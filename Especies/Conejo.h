#ifndef _CONEJO_H_
#define _CONEJO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Conejo: public Animal{
public:
    Conejo();
    Conejo( string nombre, int edad, int tamano, string personalidad );
    void mostrar() override;
    ~Conejo();
};


#endif