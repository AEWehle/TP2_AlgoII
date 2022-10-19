#include <string>
#include "../Animal.h"
#include "Gato.h"
using namespace std; 

Gato::Gato(){
    comida = "atún";
    es_domestico = true;
}
Gato::Gato( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    especie = 'G';
    comida = "atún";
    es_domestico = true;
}
