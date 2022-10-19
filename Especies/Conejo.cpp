#include <string>
#include "../Animal.h"
#include "Conejo.h"
using namespace std; 

Conejo::Conejo(){
    comida = "lechuga";
    es_domestico = true;
}

void Conejo::mostrar(){
    mostrar_animal("CONEJO");
}