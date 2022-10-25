#include <iostream>  
#include <string> 
#include <fstream> 
#include "Animal.h"
#include "funciones_main.h" 
#include "funciones_auxiliares.h" 
#include "opciones.h" 
#include "Guarderia.h"
#include "Especies/Perro.h"
#include "Especies/Gato.h"
#include "Especies/Caballo.h"
#include "Especies/Roedor.h"
#include "Especies/Conejo.h"
#include "Especies/Erizo.h"
#include "Especies/Lagartija.h"
#include "nodo.h" 
using namespace std;  
 
 
/*________crear_archivo_lectura()______________________________________________ 
 PRE: No existe un archivo con esa ruta 
 POST: Lo crea y lo pasa como lectura 
_______________________________________________________________________________*/ 
void crear_archivo( ifstream &archivo_animales ){ 
    cout << "\n     Hubo un problema, no hay un archivo con tus animales que se llame " << RUTA_ARCHIVO << endl; 
    cout << "       Creo un archivo nuevo."; 
    archivo_animales.open( RUTA_ARCHIVO, ios::out ); 
    archivo_animales.close(); 
} 
 
 
 
/*________guardar_lineas()_____________________________________________________ 
 PRE: Recibe la Guarderia y el archivo ya existenete 
 POST: Lee del archivo las lineas y las guarda en la Guarderia 
_______________________________________________________________________________*/ 
void guardar_lineas( Guarderia* mi_guarderia, ifstream &archivo_animales ){ 
    //nombre,edad,tamano,especie,personalidad 
    //mi_guarderia -> lista_de_animales = new Animal*[ BLOQUE_ANIMALES ]; 
    //mi_guarderia -> cantidad_de_animales = 0; 
     
    string linea_aux; 
 
    while( getline(archivo_animales, linea_aux, DELIMITADOR_ARCHIVO_CSV) && ( linea_aux != "") ){ 
        guardar_un_animal( mi_guarderia, linea_aux ); 
    } 
} 
 
 
 
Guarderia* leer_archivo(){  
    Guarderia* mi_guarderia = new Guarderia; 
    ifstream archivo_animales(RUTA_ARCHIVO); 
 
    if ( !archivo_animales.is_open() ) { 
        crear_archivo( archivo_animales ); 
        archivo_animales.open( RUTA_ARCHIVO, ios::in); 
    } 
    else{  cout << "Se encontró la lista de animales correctamente."; } 
 
    guardar_lineas( mi_guarderia, archivo_animales ); 
 
    cout << " Se mantienen " << mi_guarderia->obtener_cantidad() << " animales en la reserva.\n\n"; 
    cout << "Qué te gustaría hacer? " << endl; 
     
    archivo_animales.close(); 
    return mi_guarderia; 
} 
 
 
 
/*________imprimir_menu()______________________________________________________ 
 PRE: 
 POST: Imprime en temrinal todas las opciones que pude elegir el usuario. 
_______________________________________________________________________________*/ 
void imprimir_menu(){ 
    cout << "   1. Listar animales.\n"; 
    cout << "   2. Rescatar un animal\n"; 
    cout << "   3. Buscar un animal.\n"; 
    cout << "   4. Cuidar animales.\n"; 
    cout << "   5. Adoptar un animal.\n"; 
    cout << "   6. Guardar y salir.\n"; 
} 
 

 
 
int pedir_eleccion(){ 
    string entrada; 
    bool todo_bien = false; 
    int eleccion = 0; 
    while ( !todo_bien ){ 
        cout << "Elegí un numero de la lista:" << endl; 
        imprimir_menu(); 
        cout << " >> "; 
        //cin.ignore(); 
        cin >> entrada; 
 
        eleccion = string_a_entero(entrada); 
        todo_bien = verificar_eleccion( eleccion ); 
        if( !todo_bien ){ 
            cout << "Debe ser una opcion de la lista, podes elegir del 1 al " << CANTIDAD_OPCIONES << endl; 
        } 
    } 
    return eleccion; 
} 
 
 
 
 
bool verificar_eleccion( int eleccion ){ 
    return ( (1 <= eleccion) && (eleccion <= CANTIDAD_OPCIONES) ); 
} 
 
 
 
void preguntar_agregar_animal( Guarderia* mi_guarderia ){ 
    cout << "Querés agregar un animal nuevo?\n [SI, NO]\n >> "; 
    string linea_aux; 
    while ( linea_aux.length() == 0 ){ 
        cout << " >> "; 
        getline( cin, linea_aux, '\n' ); 
    } 
 
    if (string_a_mayuscula(linea_aux) == "SI"){ 
        rescatar_animal( mi_guarderia ); 
    } 
    else { 
        cout << "Ok, no agregamos nada." << endl;  
        cout << endl << "Qué mas te gustaría hacer?\n"; 
    } 
} 
 
 
 
/*________es_lista_vacia()_____________________________________________________ 
PRE:   
POST: Si la cantidad de animales guardados es 0 devuelve false y pregunta al usu- 
    ario si quiere agregar un animal. 
    De lo contrario devuelve true 
_______________________________________________________________________________*/ 
bool es_lista_vacia( Guarderia* mi_guarderia ){ 
    int cantidad_animales = mi_guarderia->obtener_cantidad();
    if ( cantidad_animales == 0 ){ 
        cout << "Por ahora no tenes animales en la reserva, podés agregar ya mismo.\n" << endl; 
        preguntar_agregar_animal( mi_guarderia ); 
    } 
    return ( cantidad_animales == 0 ); 
} 
 
 
 
void ejecutar_eleccion( Guarderia* mi_guarderia, int eleccion ){ 
    if( (3 <= eleccion && eleccion <= 7)  &&  ( es_lista_vacia( mi_guarderia ) )  ); 
    else{  funcion_elegida[ eleccion - 1 ]( mi_guarderia ); } 
} 
 
 
Animal* crear_nuevo_animal( char especie_char, string nombre, int edad, int tamano, string personalidad ){ 
    Animal* nuevo_animal = nullptr; 
    switch (especie_char){ 
        case P: 
            nuevo_animal = new Perro( nombre, edad, tamano, personalidad ); 
            break; 
        case G: 
            nuevo_animal = new Gato( nombre, edad, tamano, personalidad ); 
            break; 
        case C: 
            nuevo_animal = new Caballo( nombre, edad, tamano, personalidad ); 
            break; 
        case R: 
            nuevo_animal = new Roedor( nombre, edad, tamano, personalidad ); 
            break; 
        case O: 
            nuevo_animal = new Conejo( nombre, edad, tamano, personalidad ); 
            break; 
        case E: 
            nuevo_animal = new Erizo( nombre, edad, tamano, personalidad ); 
            break; 
        case L: 
            nuevo_animal = new Lagartija( nombre, edad, tamano, personalidad ); 
            break; 
    } 
    return nuevo_animal; 
} 
 
 
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
     
    int tamano = buscar_en_array_de_string( TAMANOS_STRING , animales_csv.substr( segunda_coma + primer_coma, tercera_coma - (segunda_coma + primer_coma + 1) ) , CANTIDAD_TAMANOS ); 
     
    string personalidad = string_a_mayuscula( animales_csv.substr( cuarta_coma + tercera_coma + segunda_coma + primer_coma + 1, fin_linea ) ); 
 
    Animal* animal_dela_linea = crear_nuevo_animal( especie_char, nombre, edad, tamano, personalidad ); 
 
    mi_guarderia->agregar(animal_dela_linea); 
    
    verificar_almacenamiento( mi_guarderia ); 
} 
 
 
 
void verificar_almacenamiento( Guarderia* mi_guarderia ){ 
    int cant_animales = mi_guarderia->obtener_cantidad();
    if ( (cant_animales  % (BLOQUE_ANIMALES)) == 0 ){  
          
        int cantidad_bloques = cant_animales / (BLOQUE_ANIMALES) + 1; 
        Animal** ptr_ptr_aux = new Animal*[ cantidad_bloques* BLOQUE_ANIMALES ]; 
 
        /*for( int i = 0; i < cant_animales ; i++){ 
            ptr_ptr_aux[i] = mi_guarderia -> lista_de_animales[i];
        } */

        mi_guarderia->copiar(ptr_ptr_aux); 
 
        delete [] mi_guarderia; 
        //mi_guarderia. = ptr_ptr_aux; 
        ptr_ptr_aux = nullptr;  
    } 
} 
 

 
/*  Devuelve un string formato csv del animal correspondiente al numero_de_animal 
    (int), lo devuelve listo parasubirlo al archivo o para imprimirlo (bool) 
    si se desea con la palabra de la especie de forma completa se indica con 
    true en genero_completo (bool) */ 
string armar_linea_animal( Guarderia* mi_guarderia, int numero_de_animal, bool especie_completo ){ 
    string separador = COMA_ESPACIO; 
    if ( especie_completo ){ 
    //     genero_string = GENEROS_STRING [ GENEROS_CHAR.find( mi_guarderia -> lista_de_animales[numero_de_animal] -> genero ) ]; 
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
 
 
void escribir_archivo( Guarderia* mi_guarderia ){ 
    ifstream is_archivo_animales(RUTA_ARCHIVO); 
 
    if ( !is_archivo_animales.is_open() ) { 
        crear_archivo( is_archivo_animales ); 
    } 
 
    ofstream archivo_animales( RUTA_ARCHIVO ); 
 
    for ( int numero_de_animal = 0; numero_de_animal < (mi_guarderia->obtener_cantidad()) ; numero_de_animal++ ){ 
        archivo_animales << armar_linea_animal( mi_guarderia, numero_de_animal, false ) << endl;  
        // Va a quedar con una linea vacia al final del archivo, el programa enteinde que es el final
    } 
 
    archivo_animales.close(); 
} 
 
 int buscar_nombre (Guarderia* mi_Guarderia, string titulo_buscado){
    return mi_Guarderia->obtener_posicion(titulo_buscado);
 }