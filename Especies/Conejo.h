#ifndef _CONEJO_H_
#define _CONEJO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Conejo: public Animal{
public:
    Conejo();
    ~Conejo();
    void mostrar();
};


#endif