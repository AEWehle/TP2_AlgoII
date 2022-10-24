#include <string>
#include <iostream> 
#include "Animal.h"
#include "Especies/Perro.h"
#include "Especies/Gato.h"
#include "Especies/Caballo.h"
#include "Especies/Roedor.h"
#include "Especies/Conejo.h"
#include "Especies/Erizo.h"
#include "Especies/Lagartija.h"
using namespace std; 


Animal::Animal(){
    higiene = 100;
    hambre = 0;
}

Animal::Animal( string nombre, int edad, int tamano, string personalidad ){
    this -> nombre = nombre;
    this -> edad =  edad;
    this -> tamano = tamano;
    this -> personalidad = personalidad;
    higiene = 100;
    hambre = 0;
}

Animal::~Animal(){
    
}


void Animal::alimentar(){  
    hambre = 0;
    cout << "Soy " << nombre << ", como " << comida << "." << endl;
}


void Animal::mostrar(){
    // especie, nombre, edad, tamano, personalidad, hambre e higiene.
    // cout << "____________________"<< nombre << "______________________________" << endl;
    cout << "       - " << "Nombre: " << nombre << "." << endl;
    cout << "       - " << edad << " años." << endl;
    cout << "       - " << "Es " << TAMANOS_STRING[ tamano ] << " m2." << endl;
    cout << "       - " << "Es " << personalidad << "." << endl;
    cout << "       - " << "Tiene " << hambre << "\% de hambre y está " << higiene << "\% limpio." << endl << endl;
}


string Animal::obtener_nombre(){
    return nombre;
}

