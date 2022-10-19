#include <string>
#include "../Animal.h"
#include "Roedor.h"
using namespace std; 

Roedor::Roedor(){
    comida = "queso";
    es_domestico = true;
}

void Roedor::mostrar(){
    mostrar_animal("ROEDOR");
}