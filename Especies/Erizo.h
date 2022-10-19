#ifndef _ERIZO_H_
#define _ERIZO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Erizo: public Animal{
public:
    Erizo();
    ~Erizo();
    void mostrar();
};


#endif