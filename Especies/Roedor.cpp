#include <string>
#include <iostream>
#include "../Animal.h"
#include "Roedor.h"
using namespace std; 

Roedor::Roedor(){
    comida = "queso";
    es_domestico = true;
}
Roedor::Roedor( string nombre, int edad, int tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    // especie = 'R';
    comida = "queso";
    es_domestico = false;
}

void Roedor::mostrar(){
    // especie, nombre, edad, tamano, personalidad, hambre e higiene.
    cout << "____________________ROEDOR_______________________________" << endl;
    Animal::mostrar();
    }