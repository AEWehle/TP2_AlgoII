#include <string>
#include <iostream>
#include "../Animal.h"
#include "Gato.h"
using namespace std; 

Gato::Gato(){
    comida = "atún";
    es_domestico = true;
}
Gato::Gato( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    // especie = 'G';
    comida = "atún";
    es_domestico = true;
}

Gato::~Gato(){
    
}

void Gato::mostrar(){
    // especie, nombre, edad, tamano, personalidad, hambre e higiene.
    cout << "____________________GATO_________________________________" << endl;
    Animal::mostrar();
    }

Especie Gato::resolver_especie(){
    return G;
}
