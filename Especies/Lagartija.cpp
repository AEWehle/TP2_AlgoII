#include <string>
#include "../Animal.h"
#include "Lagartija.h"
using namespace std; 

Lagartija::Lagartija(){
    comida = "insectos";
    es_domestico = true;
}

void Lagartija::mostrar(){
    mostrar_animal("LAGARTIJA");
}