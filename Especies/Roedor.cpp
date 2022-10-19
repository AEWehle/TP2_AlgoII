#include <string>
#include "../Animal.h"
#include "Roedor.h"
using namespace std; 

Roedor::Roedor(){
    comida = "queso";
    es_domestico = true;
}
Roedor::Roedor( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    especie = 'R';
    comida = "queso";
    es_domestico = false;
}
