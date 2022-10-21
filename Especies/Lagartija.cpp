#include <string>
#include <iostream>
#include "../Animal.h"
#include "Lagartija.h"
using namespace std; 

Lagartija::Lagartija(){
    comida = "insectos";
    es_domestico = false;
}
Lagartija::Lagartija( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    // especie = 'L';
    comida = "insectos";
    es_domestico = false;
}

void Lagartija::mostrar(){
    // especie, nombre, edad, tamano, personalidad, hambre e higiene.
    cout << "____________________LAGARTIJA____________________________" << endl;
    Animal::mostrar();
}