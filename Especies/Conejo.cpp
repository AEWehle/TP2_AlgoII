#include <string>
#include "../Animal.h"
#include "Conejo.h"
using namespace std; 

Conejo::Conejo(){
    comida = "lechuga";
    es_domestico = true;
}

Conejo::Conejo( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    especie = 'O';
    comida = "lechuga";
    es_domestico = true;
}
