#ifndef _GUARDERIA_H
#define _GUARDERIA_H
#include <string>
#include "Animal.h"
#include "Especies/Perro.h"
#include "Especies/Gato.h"
#include "Especies/Caballo.h"
#include "Especies/Roedor.h"
#include "Especies/Conejo.h"
#include "Especies/Erizo.h"
#include "Especies/Lagartija.h"
#include "Archivos_auxiliares/lista.h"
using namespace std; 

const int NO_SE_ENCUENTRA = -1;

//typedef Animal Dato; //-> Iba a ser para reutilizar la lista pero por ahora queda asi

class Guarderia{
    //Atributos
    private:
        Lista<Animal> lista_de_animales;

    //Metodos
    public:
        //Constructores
            //Sin Parametros
            //PRE: -
            //POS: Crea guarderia vacia (cantidad_de_animales = 0)
            Guarderia();

        //Destructor
            ~Guarderia();

        //Constructor de copia
            Guarderia(const Guarderia &guarderia_aux);

        //Copiar
            void copiar(Animal** &lista_animales_aux);

        //Ver lista de animales en la guarderia
            void ver_lista_de_animales();

        //Agregar
            void agregar_animal(Animal* nuevo_animal);

        //Obtener Posicion
            int obtener_posicion(string nombre);

        //Obtener cantidad
            int obtener_cantidad();

        //Eliminar Elemento
            void eliminar_elemento(int posicion);

        //Mostrar Elemento
            void mostrar(int posicion);
        
        //Mostrar
        //PRE: Guardería cargada con animales
            void mostrar();
        
    
    private:
        //SWAP
            void swap(int posicion_1, int posicion_2);


};

#endif