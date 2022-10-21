#ifndef _ERIZO_H_
#define _ERIZO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Erizo: public Animal{
public:
    Erizo();
    Erizo( string nombre, int edad, string tamano, string personalidad );
    void mostrar() override;
    ~Erizo();
};


#endif