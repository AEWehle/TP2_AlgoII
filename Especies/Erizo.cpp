#include <string>
#include "../Animal.h"
#include "Erizo.h"
using namespace std; 

Erizo::Erizo(){
    comida = "insectos";
    es_domestico = true;
}

void Erizo::mostrar(){
    mostrar_animal("ERIZO");
}