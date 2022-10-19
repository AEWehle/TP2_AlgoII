#include <string>
#include "../Animal.h"
#include "Perro.h"
using namespace std; 

Perro::Perro(){
    comida = "huesos";
    es_domestico = true;
}
Perro::Perro( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    especie = 'P';
    comida = "huesos";
    es_domestico = true;
}
