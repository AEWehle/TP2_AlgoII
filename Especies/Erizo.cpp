#include <string>
#include <iostream>
#include "../Animal.h"
#include "Erizo.h"
using namespace std; 

Erizo::Erizo(){
    comida = "insectos";
    es_domestico = false;
}

Erizo::Erizo( string nombre, int edad, int tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){
    // especie ='E';
    comida = "insectos";
    es_domestico = false;
}

Erizo::~Erizo(){
    
}

void Erizo::mostrar(){
    // especie, nombre, edad, tamano, personalidad, hambre e higiene.
    cout << "____________________ERIZO________________________________" << endl;
    Animal::mostrar();
    }

Especie Erizo::resolver_especie(){
    return E;
}