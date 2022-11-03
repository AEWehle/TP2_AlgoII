#ifndef LISTA_TEMPLATE
#define LISTA_TEMPLATE

#include "nodo.h"

//  EL ORDEN DE LOS ELEMENTOS SE EMPIEZA A CONTAR DESDE 1, NO DESDE 0


template <typename Dato>
class Lista {
//atributos
    private:
        
        Nodo<Dato>* primero;
        
        int cantidad;
        
        Nodo<Dato>* actual;

//metodos
    public:
        // Constructor
        // pre: -
        // pos: construye una Lista vacia
        Lista();

        // pre: 0 < pos <= cantidad + 1
        // pos: Agrega d en la posicion pos (la primera es la 1)
        void alta(Dato* dato, int pos);

        // pre: 0 < pos <= cantidad
        // pos: devuelve el dato que esta en la posicion pos (empieza en 1)
        Dato* consulta(int pos);

        // pre: 0 < pos <= cantidad
        // pos: da de baja el dato que esta en la posicion pos (empieza en 1)
        void baja(int pos);

        // pre: -
        // pos: True si la Lista esta vacia, False si no
        bool vacia();

        // Devuelve la cantidad elementos
        int obtener_cantidad();

        // Destructor
        ~Lista();

        // Agregado Lista con cursores
        // pos: True si hay algún dato más en la lista, False si
        //      la lista es vacía o si llegué al final de la lista
        bool hay_siguiente();

        // pre: hay_siguiente() es True
        // pos: devuelve el dato y mueve el cursor al siguiente
        Dato* siguiente();

        // pos: pone el cursor al principio
        void iniciar();

    private:
        // pre: 0 < pos <= cantidad
        // pos: devuelve un ptr al nodo que esta en pos
        Nodo<Dato>* obtener_nodo(int pos);
};

template <typename Dato>
Lista<Dato>::Lista() {
    this -> primero = nullptr;
    this -> cantidad = 0;
    this -> actual = primero;
}

template <typename Dato>
void Lista<Dato>::alta(Dato* dato, int pos) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(dato);
    Nodo<Dato>* siguiente = primero;
    if (pos == 1) {
        this -> primero = nuevo;
    }
    else {
        Nodo<Dato>* anterior = obtener_nodo(pos - 1);
        siguiente = anterior -> obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    this -> cantidad++;
}

template <typename Dato>
Dato* Lista<Dato>::consulta(int pos) {
    Nodo<Dato>* nodo = obtener_nodo(pos);
    return (nodo->obtener_dato());
}

template <typename Dato>
void Lista<Dato>::baja(int pos) {
    Nodo<Dato>* a_borrar = this -> primero;
    cout << "CANTIDAD ACAAAAA " << cantidad << endl;
    cout << "POSICION " << pos << endl;
    if (pos == 1) {
        this -> primero = a_borrar->obtener_siguiente();
    }
    else {
        Nodo<Dato>* anterior = obtener_nodo(pos - 1);
        a_borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(a_borrar->obtener_siguiente());
        
    }
    delete a_borrar->obtener_dato();
    delete a_borrar; // Ojo si dentro de los nodos pedimos memoria
    this -> cantidad--;
}

template <typename Dato>
bool Lista<Dato>::vacia() {
    return (this -> cantidad == 0);
}

template <typename Dato>
Lista<Dato>::~Lista() {
    while (! vacia()){
        baja(1);
    }
}

template <typename Dato>
int Lista<Dato>::obtener_cantidad() {
    return this -> cantidad;
}

template <typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_nodo(int pos) {
    Nodo<Dato>* auxiliar = this -> primero;
    for(int i = 1; i < pos; i++)
        auxiliar = auxiliar->obtener_siguiente();
    return auxiliar;
}

template <typename Dato>
bool Lista<Dato>::hay_siguiente() {
    return (this -> actual != nullptr);
}

template <typename Dato>
Dato* Lista<Dato>::siguiente() {
    Dato* dato = this -> actual->obtener_dato();
    this -> actual = this -> actual->obtener_siguiente();
    return dato;
}

template <typename Dato>
void Lista<Dato>::iniciar() {
    this -> actual = this -> primero;
}


#endif // LISTA_TEMPLATE
