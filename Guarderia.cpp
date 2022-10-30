#include <string>
#include <iostream> 
#include "Guarderia.h"
// #include "Animal.h" // se inluye a traves de guarderia
using namespace std; 


//Constructor sin parámetros
Guarderia::Guarderia(){
    //se crea una lista vacía
}


Guarderia::~Guarderia(){
    // if(cantidad_de_animales > 0){
    //     delete[] lista_de_animales;
    // }
}


//Constructor de copia
// Guarderia::Guarderia(const Guarderia& guarderia_aux){
//     cantidad_de_animales = guarderia_aux.cantidad_de_animales;

//     if (cantidad_de_animales > 0) {
//         lista_de_animales = new Animal*;
//         for (int i = 0; i < cantidad_de_animales; i++)
//             lista_de_animales[i] = guarderia_aux.lista_de_animales[i];
//     }

// }


//Copiar
// void Guarderia::copiar(Animal** &lista_animales_aux){
//     for( int i = 0; i < cantidad_de_animales ; i++){ 
//         lista_animales_aux[i] = lista_de_animales[i]; 
//     } 
// }

//Agrega un animal al final de la lista
void Guarderia::agregar_animal(Animal* nuevo_animal){
    
    lista_de_animales.alta(nuevo_animal,lista_de_animales.obtener_cantidad()+1);

}


//Obtener Posicion
int Guarderia::obtener_posicion(string nombre){
    int cantidad_de_animales = lista_de_animales.obtener_cantidad();
    int posicion = 1;
    int i = 0;

    while(i < cantidad_de_animales &&  lista_de_animales.consulta(posicion)->obtener_nombre() != nombre){
        posicion = ++i;
    }
    
    if (posicion == cantidad_de_animales) {
        cout << "El animal " << nombre << " no se encuentra en la lista" << endl ;
        //posicion = NO_SE_ENCUENTRA;
    }
    return posicion;
}


//Cantidad de Animales
int Guarderia::obtener_cantidad(){
    return lista_de_animales.obtener_cantidad();
}


//Eliminar Elemento
void Guarderia::eliminar_elemento(int posicion){
    lista_de_animales.baja(posicion);
}



// void Guarderia::swap(int posicion_1, int posicion_2){
//     Animal* aux = Guarderia::lista_de_animales[posicion_1];
//     Guarderia::lista_de_animales[posicion_1] = Guarderia::lista_de_animales[posicion_2];
//     Guarderia::lista_de_animales[posicion_2] = aux;
// }



//Mostrar Elemento
Animal* Guarderia::mostrar(int posicion){
    return lista_de_animales.consulta(posicion);
}


//Ver lista
void Guarderia::ver_lista_de_animales(){
    if(lista_de_animales.obtener_cantidad()){
        for(int i=1; i<lista_de_animales.obtener_cantidad()+1; i++){
            lista_de_animales.consulta(i)->mostrar();
        }
    }else{
        cout << "No hay animales en la lista" << endl;
    }
}


void Guarderia::copiar(Animal** &lista_animales_aux){}