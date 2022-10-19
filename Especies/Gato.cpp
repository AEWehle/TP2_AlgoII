#include <string>
#include "../Animal.h"
#include "Gato.h"
using namespace std; 

Gato::Gato(){
    comida = "atún";
    es_domestico = true;
}

void Gato::mostrar(){
    mostrar_animal("GATO");
}