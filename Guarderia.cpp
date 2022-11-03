#include <string>
#include <iostream> 
#include "Guarderia.h"
#include "Archivos_auxiliares/funciones_auxiliares.h" 
// #include "Animal.h" // se inluye a traves de guarderia
using namespace std; 


//Constructor sin parámetros
Guarderia::Guarderia(){
    //se crea una lista vacía
}

// Destrcutor
Guarderia::~Guarderia(){

}



//Agrega un animal al final de la lista
void Guarderia::agregar_animal( Animal* nuevo_animal ){
    
    lista_de_animales.alta( nuevo_animal, lista_de_animales.obtener_cantidad() + 1 );

}


//Obtener Posicion
// Si no lo encuentra dvuelve la cantidad +1 
int Guarderia::obtener_posicion( string nombre ){
    int cantidad_de_animales = lista_de_animales.obtener_cantidad();
    int posicion = 1;

    while( (posicion <= cantidad_de_animales) &&  ( string_a_mayuscula( lista_de_animales.consulta( posicion  )->obtener_nombre() ) != string_a_mayuscula( nombre ) )){
        posicion++;
    }
   
    return posicion;
}


//Cantidad de Animales
int Guarderia::obtener_cantidad(){
    return lista_de_animales.obtener_cantidad();
}


//Eliminar Elemento
void Guarderia::eliminar_animal(int posicion){
    lista_de_animales.baja(posicion);
}



//Obtener animal
Animal* Guarderia::obtener_animal(int posicion){
    return lista_de_animales.consulta(posicion);
}


//Ver lista
void Guarderia::ver_lista_de_animales(){
    cout << "Hay " << lista_de_animales.obtener_cantidad() << " animales en la reserva." << endl;
    if(lista_de_animales.obtener_cantidad()){
        for( int i = 1 ; i < (lista_de_animales.obtener_cantidad()+1) ; i++){
            lista_de_animales.consulta(i)->mostrar();
        }
    }else{
        cout << "No hay animales en la lista" << endl;
    }
}

