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
    
    // cout << "____________________"<< especie << "______________________________" << endl;
    cout << "       - " << "Nombre: " << nombre << "." << endl;
    cout << "       - " << edad << " años." << endl;
    cout << "       - " << "Es " << tamano << endl;
    cout << "       - " << "Es muy " << personalidad << "." << endl;
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


int Animal::obtener_hambre(){

    return hambre;

}


int Animal::obtener_higiene(){

    return higiene;

}


void Animal::setear_hambre(int hambre_int){

    hambre = hambre_int;

}


void Animal::setear_higiene(int higiene_int){

    higiene = higiene_int;

}


void Animal::dar_hambre(){

    if(hambre!=100){
        if (personalidad == PERSONALIDADES[0]) {
            //Caso mitad del hambre
            hambre = hambre + PUNTOS_HAMBRE/2;
        }
        else if (personalidad == PERSONALIDADES[1]) {
            //Caso doble del hambre
            hambre = hambre + 2*PUNTOS_HAMBRE;
        }
        else
            hambre = hambre + PUNTOS_HAMBRE;

    }
    
    else
        cout << "Parece que " << nombre << " tiene mucha hambre. Quizás es hora de alimentarl@." << endl;

}

void Animal::ensuciar(){

    if(higiene!=0){
        if (personalidad == PERSONALIDADES[2]) {
            //Caso se ensucia la mitad
            higiene = higiene - PUNTOS_HIGIENTE/2;
        }
        else if (personalidad == PERSONALIDADES[3]) {
            //Caso se ensucia el doble
            higiene = higiene - 2*PUNTOS_HIGIENTE;
        }
        else
            higiene = higiene - PUNTOS_HIGIENTE;

    }

    else
        cout << "Parece que " << nombre << " está muy sucio. Quizás es hora de ducharl@." << endl;

}


void Animal::duchar(){

    higiene = 100;
    
}