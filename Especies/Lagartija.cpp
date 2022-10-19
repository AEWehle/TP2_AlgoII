#include <string>
#include "../Animal.h"
#include "Lagartija.h"
using namespace std; 

Lagartija::Lagartija(){
    comida = "insectos";
    es_domestico = true;
}
Lagartija::Lagartija( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    especie = 'L';
    comida = "insectos";
    es_domestico = true;
}