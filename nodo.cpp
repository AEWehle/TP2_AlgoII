#include "nodo.h"

// Constructor
Nodo::Nodo(Dato dato) {
    dato = dato;
    siguiente = nullptr;
}

// cambiar siguiente
void Nodo::cambiar_siguiente(Nodo* nuevo_siguiente) {
    siguiente = nuevo_siguiente;
}

// obtener siguiente
Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

// obtener dato
Dato Nodo::obtener_dato() {
    return dato;
}
