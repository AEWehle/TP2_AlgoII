#ifndef NODO_H
#define NODO_H

typedef char Dato; //Cambiar por el tipo de dato que vayamos a usar

class Nodo {
    // Atributos
private:
    Dato dato;
    Nodo* siguiente;

public:
    // Constructor
    // crea un nodo con dato = d y siguiente = 0
    Nodo(Dato dato);

    void cambiar_siguiente(Nodo* nuevo_siguiente);

    Dato obtener_dato();

    Nodo* obtener_siguiente();
};

#endif // NODO_H
