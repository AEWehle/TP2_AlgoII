#include <string>
#include "../Animal.h"
#include "Caballo.h"
using namespace std; 

Caballo::Caballo(  ): Animal(  ){
    comida = "manzanas";
    es_domestico = true;
}

Caballo::Caballo( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    especie = 'C';
    comida = "manzanas";
    es_domestico = true;
}
