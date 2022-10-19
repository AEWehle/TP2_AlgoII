#include <string>
#include "../Animal.h"
#include "Erizo.h"
using namespace std; 

Erizo::Erizo(){
    comida = "insectos";
    es_domestico = true;
}

Erizo::Erizo( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    especie ='E';
    comida = "insectos";
    es_domestico = true;
}