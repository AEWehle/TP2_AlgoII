#include "lista.h"
// Comentario
Lista::Lista() {
    primero = nullptr;
    cantidad = 0;
    actual = primero;
}

void Lista::alta(Dato dato, int pos) {
    Nodo* nuevo = new Nodo(dato);
    Nodo* siguiente = primero;
    if (pos == 1) {
        primero = nuevo;
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    cantidad++;
}

Dato Lista::consulta(int pos) {
    Nodo* nodo = obtener_nodo(pos);
    return (nodo->obtener_dato());
}

void Lista::baja(int pos) {
    Nodo* a_borrar = primero;
    if (pos == 1) {
        primero = a_borrar->obtener_siguiente();
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        a_borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(a_borrar->obtener_siguiente());
    }
    delete a_borrar; // Ojo si dentro de los nodos pedimos memoria
    cantidad--;
}

bool Lista::vacia() {
    return (cantidad == 0);
}

Lista::~Lista() {
    while (! vacia()){
        baja(1);
    }
}

int Lista::obtener_cantidad() {
    return cantidad;
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* auxiliar = primero;
    for(int i = 1; i < pos; i++)
        auxiliar = auxiliar->obtener_siguiente();
    return auxiliar;
}

bool Lista::hay_siguiente() {
    return (actual != nullptr);
}

Dato Lista::siguiente() {
    Dato dato = actual->obtener_dato();
    actual = actual->obtener_siguiente();
    return dato;
}

void Lista::iniciar() {
    actual = primero;
}
