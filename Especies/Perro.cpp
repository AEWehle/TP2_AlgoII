#include <string>
#include "../Animal.h"
#include "Perro.h"
using namespace std; 

Perro::Perro(){
    comida = "huesos";
    es_domestico = true;
}

void Perro::mostrar(){
    mostrar_animal("PERRO");
}