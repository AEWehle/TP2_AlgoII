#ifndef LISTA_TEMPLATE
#define LISTA_TEMPLATE

#include "nodo.h"

template <typename Dato>
class Lista {
        //atributos
    private:
        // Puntero al primer Nodo
        Nodo<Dato>* primero;
        // Cantidad de Nodos
        int cantidad;
        // Puntero al Nodo actual
        Nodo<Dato>* actual;

        //metodos
    public:
        // Constructor
        // pre: -
        // pos: construye una Lista vacia
        Lista();

        // pre: 0 < pos <= cantidad + 1
        // pos: Agrega d en la posicion pos (la primera es la 1)
        void alta(Dato d, int pos);

        // pre: 0 < pos <= cantidad
        // pos: devuelve el dato que esta en la posicion pos (empieza en 1)
        Dato consulta(int pos);

        // pre: 0 < pos <= cantidad
        // pos: da de baja el dato que esta en la posicion pos (empieza en 1)
        void baja(int pos);

        // pre: -
        // pos: verdadero si la Lista esta vacia, F si no
        bool vacia();

        // Devuelve la cantidad elementos
        int obtener_cantidad();

        // Destructor
        ~Lista();

        // Agregado Lista con cursores
        // pos: True si hay alg�n dato m�s en la lista, False si
        //      la lista es vac�a o si llegu� al final de la lista
        bool hay_siguiente();

        // pre: hay_siguiente() es True
        // pos: devuelve el dato y mueve el cursor al siguiente
        Dato siguiente();

        // pos: pone el cursor al principio
        void iniciar();

    private:
        // pre: 0 < pos <= cantidad
        // pos: devuelve un ptr al nodo que esta en pos
        Nodo<Dato>* obtener_nodo(int pos);
};

template <typename Dato>
Lista<Dato>::Lista() {
    primero = nullptr;
    cantidad = 0;
    actual = primero;
}

template <typename Dato>
void Lista<Dato>::alta(Dato dato, int pos) {
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

template <typename Dato>
Dato Lista<Dato>::consulta(int pos) {
    Nodo* nodo = obtener_nodo(pos);
    return (nodo->obtener_dato());
}

template <typename Dato>
void Lista<Dato>::baja(int pos) {
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

template <typename Dato>
bool Lista<Dato>::vacia() {
    return (cantidad == 0);
}

template <typename Dato>
Lista<Dato>::~Lista() {
    while (! vacia()){
        baja(1);
    }
}

template <typename Dato>
int Lista<Dato>::obtener_cantidad() {
    return cantidad;
}

template <typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_nodo(int pos) {
    Nodo* auxiliar = primero;
    for(int i = 1; i < pos; i++)
        auxiliar = auxiliar->obtener_siguiente();
    return auxiliar;
}

template <typename Dato>
bool Lista<Dato>::hay_siguiente() {
    return (actual != nullptr);
}

template <typename Dato>
Dato Lista<Dato>::siguiente() {
    Dato dato = actual->obtener_dato();
    actual = actual->obtener_siguiente();
    return dato;
}

template <typename Dato>
void Lista<Dato>::iniciar() {
    actual = primero;
}


#endif // LISTA_TEMPLATE