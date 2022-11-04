#include <string>
#include <iostream>
#include "../Animal.h"
#include "Gato.h"
using namespace std; 

Gato::Gato(){
    comida = "atun";
    es_domestico = true;
}
Gato::Gato( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    // especie = 'G';
    comida = "atun";
    es_domestico = true;
}

Gato::~Gato(){
    
}

void Gato::mostrar(){
    // especie, nombre, edad, tamano, personalidad, hambre e higiene.
    cout << "____________________GATO_________________________________" << endl;
    Animal::mostrar();
}

void Gato::ensuciar(){
    higiene = 100;
}

void Gato::duchar(){
    cout << nombre << ": - Soy un gato, no necesito ducharme." << endl;
}

Especie Gato::resolver_especie(){
    return G;
}
