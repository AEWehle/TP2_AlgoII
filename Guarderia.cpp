#include <string>
#include <iostream> 
#include "Animal.h"
#include "Guarderia.h"
using namespace std; 


Guarderia::Guarderia(){
    lista_de_animales = new Animal*;
    cantidad_de_animales = 0;
}


Guarderia::~Guarderia(){
    if(cantidad_de_animales > 0){
        delete[] lista_de_animales;
    }
}


//Constructor de copia
Guarderia::Guarderia(const Guarderia& guarderia_aux){
    cantidad_de_animales = guarderia_aux.cantidad_de_animales;

    if (cantidad_de_animales > 0) {
        lista_de_animales = new Animal*;
        for (int i = 0; i < cantidad_de_animales; i++)
            lista_de_animales[i] = guarderia_aux.lista_de_animales[i];
    }

}


//Copiar
    void Guarderia::copiar(Animal** &lista_animales_aux){
        for( int i = 0; i < cantidad_de_animales ; i++){ 
            lista_animales_aux[i] = lista_de_animales[i]; 
        } 
    }

//Cargar
    void Guarderia::agregar(Animal* nuevo_animal){
        lista_de_animales[ (cantidad_de_animales)++] = nuevo_animal; 
    }


//Obtener Posicion
    int Guarderia::obtener_posicion(string nombre){
        int posicion = cantidad_de_animales; 
        int i = 0;

        while(i < cantidad_de_animales &&  lista_de_animales[i]->obtener_nombre() != nombre){
            posicion = ++i;
        }
        
        if (posicion == cantidad_de_animales) {
            cout << "El animal " << nombre << " no se encuentra en la lista" << endl ;
            posicion = -1;
        }
        return posicion;
    }


//Cantidad de Animales
    int Guarderia::obtener_cantidad(){
        return Guarderia::cantidad_de_animales;
    }


//Eliminar Elemento
    void Guarderia::eliminar_elemento(int posicion){
        if(Guarderia::cantidad_de_animales > 1){
            swap(Guarderia::cantidad_de_animales - 1, posicion);

            Animal** nueva_lista_animales = new Animal*[Guarderia::cantidad_de_animales];

            for(int i = 0; i < Guarderia::cantidad_de_animales - 1; i++){
                nueva_lista_animales[i] = Guarderia::lista_de_animales[i];
            }

            delete Guarderia::lista_de_animales[Guarderia::cantidad_de_animales - 1];
            delete[] Guarderia::lista_de_animales;

            Guarderia::lista_de_animales = nueva_lista_animales;
        }else{
            delete Guarderia::lista_de_animales[Guarderia::cantidad_de_animales - 1];
            delete[] Guarderia::lista_de_animales;
        }

        Guarderia::cantidad_de_animales--;
    }



void Guarderia::swap(int posicion_1, int posicion_2){
    Animal* aux = Guarderia::lista_de_animales[posicion_1];
    Guarderia::lista_de_animales[posicion_1] = Guarderia::lista_de_animales[posicion_2];
    Guarderia::lista_de_animales[posicion_2] = aux;
}



//Mostrar Elemento
    void Guarderia::mostrar(int posicion){
        if(posicion > cantidad_de_animales){
            cout << "La guardería tiene solo "<< cantidad_de_animales <<" animales. No existe nungun animal en la posicion "<< posicion << "." << endl ;
        }else{
            Guarderia::lista_de_animales[posicion]->mostrar();
        }
    }


//Mostrar
    void Guarderia::mostrar(){
        if (Guarderia::cantidad_de_animales == 0) {
            cout << "La guardería está vacia. No hay animales para mostrar." << endl ;
        }
        else{
            cout << "Salvaste los siguientes animales:\n";
            for(int i=0; i<Guarderia::cantidad_de_animales; i++){
            Guarderia::lista_de_animales[i]->mostrar();
        }
        }
    }

//Ver lista
    Animal** Guarderia::ver_lista(){
        return lista_de_animales;
    }


