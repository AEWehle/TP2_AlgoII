#include <string>
#include <iostream>
#include "../Animal.h"
#include "Perro.h"
using namespace std; 

Perro::Perro(){
    comida = "huesos";
    es_domestico = true;
}
Perro::Perro( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    // especie = 'P';
    comida = "huesos";
    es_domestico = true;
}

void Perro::mostrar(){
    // especie, nombre, edad, tamano, personalidad, hambre e higiene.
    cout << "____________________PERRO________________________________" << endl;
    Animal::mostrar();
    }