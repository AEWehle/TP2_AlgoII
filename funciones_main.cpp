#include <iostream>  
#include <string> 
#include <fstream> 
#include "Archivos_auxiliares/funciones_auxiliares.h" 
#include "Archivos_auxiliares/nodo.h" 
#include "funciones_main.h" 
#include "opciones.h" 
#include "Guarderia.h"
// #include "Animal.h"
// #include "Especies/Perro.h" // estos ya se incluyen a traves de guarderia
// #include "Especies/Gato.h"
// #include "Especies/Caballo.h"
// #include "Especies/Roedor.h"
// #include "Especies/Conejo.h"
// #include "Especies/Erizo.h"
// #include "Especies/Lagartija.h"
using namespace std;  
 



Animal* crear_nuevo_animal( char especie, string nombre, int edad, string tamano, string personalidad ){ 
    Animal* nuevo_animal; 
    if(especie == 'P')
        nuevo_animal = new Perro( nombre, edad, tamano, personalidad );
    else if(especie == 'G')
        nuevo_animal = new Gato( nombre, edad, tamano, personalidad );
    else if(especie == 'C')
        nuevo_animal = new Caballo( nombre, edad, tamano, personalidad );
    else if(especie == 'R')
        nuevo_animal = new Roedor( nombre, edad, tamano, personalidad );
    else if(especie == 'O')
        nuevo_animal = new Conejo( nombre, edad, tamano, personalidad );
    else if(especie == 'E')
        nuevo_animal = new Erizo( nombre, edad, tamano, personalidad );
    else//(especie == 'L')
        nuevo_animal = new Lagartija( nombre, edad, tamano, personalidad );

    return nuevo_animal; 
} 
 

void cargar_guarderia(Guarderia* mi_guarderia){

    fstream archivo_guarderia(RUTA_ARCHIVO, ios::in);

    if(!archivo_guarderia.is_open()){
        cout << "No se encontro un archivo con nombre \"" << RUTA_ARCHIVO << "\", se va a crear el archivo" << endl << endl;
        archivo_guarderia.open(RUTA_ARCHIVO, ios::out);     //Si no existe el archivo lo creo
        archivo_guarderia.close();
        archivo_guarderia.open(RUTA_ARCHIVO, ios::in);
    }

    string nombre, edad, tamano, especie, personalidad;

    while(getline(archivo_guarderia, nombre, ',')){    //Cuando ya no encuentra un nombre se terminó el archivo

        getline(archivo_guarderia, edad, ',');
        getline(archivo_guarderia, tamano, ',');
        getline(archivo_guarderia, especie, ',');
        getline(archivo_guarderia, personalidad);    //El último lo leo hasta encontrar un \n, no una coma.

        Animal* nuevo_animal = crear_nuevo_animal(especie[0], nombre, stoi(edad), tamano, personalidad);

        mi_guarderia -> agregar_animal(nuevo_animal);
    }

    archivo_guarderia.close();
}


/*________imprimir_menu()______________________________________________________ 
 PRE: 
 POST: Imprime en temrinal todas las opciones que pude elegir el usuario. 
_______________________________________________________________________________*/ 
void imprimir_menu(){ 
    cout << "*****   MENU   *****" << endl << endl;
    cout << "   1. Listar animales." << endl; 
    cout << "   2. Rescatar un animal." << endl; 
    cout << "   3. Buscar un animal." << endl;
    cout << "   4. Cuidar animales." << endl;
    cout << "   5. Adoptar un animal." << endl;
    cout << "   6. Guardar y salir." << endl << endl;
}


bool eleccion_valida(int eleccion){ 
    return ( (1 <= eleccion) && (eleccion <= CANTIDAD_OPCIONES) ); 
}


int pedir_eleccion(){ 

    string eleccion;
    imprimir_menu();
    cout << "Ingrese el número de la opción elegida: " << endl << " >> ";
    cin >> eleccion;

    int eleccion_int = stoi(eleccion);

    while(!eleccion_valida(eleccion_int)){

        //cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');    //Por si el usuario ingresa caracteres que no sean números, sean la cantidad que sean
        cout << "La opcion ingresada es invalida, por favor ingrese una opcion valida: ";
        cin >> eleccion;
        eleccion_int = stoi(eleccion);

    }

    return eleccion_int;

}


void ejecutar_eleccion(Guarderia* mi_guarderia, int eleccion){ 

    //if( (3 <= eleccion && eleccion <= 7)  &&  ( es_lista_vacia( mi_guarderia ) )  ); 
    funcion_elegida[ eleccion - 1 ]( mi_guarderia );

}
