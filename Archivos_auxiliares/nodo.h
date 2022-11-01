#ifndef NODO_TEMPLATE
#define NODO_TEMPLATE

//Dato será el ANIMAL que se introduzca en la lista
template <typename Dato>
class Nodo{
        // Atributos
    private:
        Dato* dato;
        Nodo* siguiente;

    public:
        // Constructor
        // crea un nodo con dato = d y siguiente = 0
        Nodo(Dato* dato);

        /* Recibe el nodo que se quiere aputar con Siguiente, 
        hace que el atrivuto Siguinete apunte a este */
        void cambiar_siguiente(Nodo* nuevo_siguiente);

        /* Devuelve un puntero que apunta a lo mismo que el atributo Dato*/
        Dato* obtener_dato();

        /* Devuelve un puntero que apunta a lo mismo que el atributo Siguiente*/
        Nodo* obtener_siguiente();
};


// Constructor
template <typename Dato>
Nodo<Dato>::Nodo(Dato* dato){
    this->dato = dato;
    siguiente = nullptr;
}

// cambiar siguiente
template <typename Dato>
void Nodo<Dato>::cambiar_siguiente(Nodo<Dato>* nuevo_siguiente){
    siguiente = nuevo_siguiente;
}

// obtener siguiente
template <typename Dato>
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
    return siguiente;
}

// obtener dato
template <typename Dato>
Dato* Nodo<Dato>::obtener_dato() {
    return dato;
}

#endif // NODO_TEMPLATE
