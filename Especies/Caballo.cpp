#include <string>
#include "../Animal.h"
#include "Caballo.h"
using namespace std; 

Caballo::Caballo(){
    comida = "manzanas";
    es_domestico = true;
}

void Caballo::mostrar(){
    mostrar_animal("CABALLO");
}