#include <string>
#include <iostream>
#include "../Animal.h"
#include "Conejo.h"
using namespace std; 

Conejo::Conejo(){
    comida = "lechuga";
    es_domestico = true;
}

Conejo::Conejo( string nombre, int edad, int tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    // especie = 'O';
    comida = "lechuga";
    es_domestico = true;
}

void Conejo::mostrar(){
    // especie, nombre, edad, tamano, personalidad, hambre e higiene.
    cout << "____________________CONEJO_______________________________" << endl;
    Animal::mostrar();
}