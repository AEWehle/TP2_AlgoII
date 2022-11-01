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
void imprimir_menu(int cantidad_elecciones){ 
    if(cantidad_elecciones == 6){
        cout << "*****   MENU   *****" << endl << endl;
        cout << "   1. Listar animales." << endl; 
        cout << "   2. Rescatar un animal." << endl; 
        cout << "   3. Buscar un animal." << endl;
        cout << "   4. Cuidar animales." << endl;
        cout << "   5. Adoptar un animal." << endl;
        cout << "   6. Guardar y salir." << endl << endl;
    }else if (cantidad_elecciones == 4) {
        cout << "*****   CUIDAR ANIMALES: MENU   *****" << endl << endl;
        cout << "   1. Elegir Individualmente." << endl; 
        cout << "   2. Alimentar a todos." << endl; 
        cout << "   3. Bañar a todos." << endl;
        cout << "   4. Regresar al Menu Principal." << endl << endl;
    }
}


bool eleccion_valida(int eleccion, int cantidad_opciones){ 
    return ( (1 <= eleccion) && (eleccion <= cantidad_opciones) ); 
}


int pedir_eleccion(int cantidad_opciones){ 

    string eleccion;
    //imprimir_menu(cantidad_opciones); -> Comentada, se imprime menu desde afuera para poder reutilizar verificación
    cout << "Ingrese el numero de la opcion elegida: ";
    cin >> eleccion;

    int eleccion_int = stoi(eleccion);

    while(!eleccion_valida(eleccion_int, cantidad_opciones)){

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


//////////////////////////////////////////////////////////////////////////////////
 



 
/*________es_lista_vacia()_____________________________________________________ 
PRE:   
POST: Si la cantidad de animales guardados es 0 devuelve false y pregunta al usu- 
    ario si quiere agregar un animal. 
    De lo contrario devuelve true 
_______________________________________________________________________________*/ 
/*bool es_lista_vacia( Guarderia* mi_guarderia ){ 
    int cantidad_animales = mi_guarderia->obtener_cantidad();
    if ( cantidad_animales == 0 ){ 
        cout << "Por ahora no tenes animales en la reserva, podés agregar ya mismo.\n" << endl; 
        preguntar_agregar_animal( mi_guarderia ); 
    } 
    return ( cantidad_animales == 0 ); 
}*/

/*
void guardar_un_animal( Guarderia* mi_guarderia,  string animales_csv){ //nombre,edad,tamano,especie,personalidad ---> Loni,2,mediano,P,sociable 
    unsigned long primer_coma     = (unsigned long)  animales_csv.find(','); 
    unsigned long segunda_coma    = (unsigned long)  animales_csv.find(',', (primer_coma + 1)); 
    unsigned long tercera_coma    = (unsigned long)  animales_csv.find(',', (segunda_coma + primer_coma + 1)); 
    unsigned long cuarta_coma     = (unsigned long)  animales_csv.find(',', (tercera_coma + segunda_coma + primer_coma + 1)); 
    unsigned long fin_linea       = (unsigned long)  animales_csv.length(); 
 
    char especie_char =  char_a_mayuscula( animales_csv.substr( tercera_coma + segunda_coma + primer_coma, cuarta_coma - (tercera_coma + segunda_coma + primer_coma + 1) )[0] ); 
 
    // Guardo el nombre en mayusculas, evita problema en comparaciones futuras 
    string nombre = string_a_mayuscula( animales_csv.substr( 0, primer_coma ) ); 
     
    int edad = string_a_entero( animales_csv.substr( primer_coma + 1, segunda_coma - ( primer_coma + 1) ) );   
     
    // int tamano = buscar_en_array_de_string( TAMANOS_STRING , animales_csv.substr( segunda_coma + primer_coma, tercera_coma - (segunda_coma + primer_coma + 1) ) , CANTIDAD_TAMANOS ); 
    string tamano = animales_csv.substr( segunda_coma + primer_coma, tercera_coma - (segunda_coma + primer_coma + 1) );
     
    string personalidad = string_a_mayuscula( animales_csv.substr( cuarta_coma + tercera_coma + segunda_coma + primer_coma + 1, fin_linea ) ); 
 
    Animal* animal_dela_linea = crear_nuevo_animal( especie_char, nombre, edad, tamano, personalidad ); 
 
    mi_guarderia->agregar_animal(animal_dela_linea); 
    

    // verificar_almacenamiento( mi_guarderia ); // ya no es necesario 
*/

/*  Devuelve un string formato csv del animal correspondiente al numero_de_animal 
    (int), lo devuelve listo parasubirlo al archivo o para imprimirlo (bool) 
    si se desea con la palabra de la especie de forma completa se indica con 
    true en genero_completo (bool) */ 
string armar_linea_animal( Guarderia* mi_guarderia, int numero_de_animal, bool especie_completo ){ 
    string separador = COMA_ESPACIO; 
    if ( especie_completo ){ 
        // string especie_string = ESPECIE_STRING [ mi_guarderia -> lista_de_animales.consulta( numero_de_animal ) -> resolver_especie ]; 
    } 
    else {  
        // genero_string =  mi_guarderia -> lista_de_animales[numero_de_animal] -> genero ;  
       separador = ","; 
    } 
     
    // string linea_animal = mi_guarderia -> lista_de_animales[numero_de_animal] -> obtener_nombre() + separador + genero_string; 
    // linea_animal = (linea_animal + separador) + to_string( mi_guarderia -> lista_de_animales[numero_de_animal] -> puntaje ); 
    string linea_animal = "nada"; 
    return linea_animal; 
} 