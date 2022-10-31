#include <string>
#include <iostream> 
#include "Animal.h"
using namespace std; 


Animal::Animal(){
    higiene = 100;
    hambre = 0;
}

Animal::Animal( string nombre, int edad, string tamano, string personalidad ){
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
    // cout << "____________________"<< especie << "______________________________" << endl;
    cout << "       - " << "Nombre: " << nombre << "." << endl;
    cout << "       - " << edad << " años." << endl;
    cout << "       - " << "Es " << tamano << " m2." << endl;
    cout << "       - " << "Es " << personalidad << "." << endl;
    cout << "       - " << "Tiene " << hambre << "\% de hambre y está " << higiene << "\% limpio." << endl << endl;
}


string Animal::obtener_nombre(){
    return nombre;
}

int Animal::obtener_edad(){
    return edad;
}

string Animal::obtener_tamano(){
    return tamano;
}

string Animal::obtener_personalidad(){
    return personalidad;
}

bool Animal::es_adoptable(){
    return es_domestico;
}