#ifndef FUNCIONES_MAIN_H_ 
#define FUNCIONES_MAIN_H_ 
#include <string> 
#include "Archivos_auxiliares/nodo.h" 
#include "Guarderia.h"
// #include "Especies/Perro.h" // estos ya se incluyen a traves de guarderia
// #include "Especies/Gato.h"
// #include "Especies/Caballo.h"
// #include "Especies/Roedor.h"
// #include "Especies/Conejo.h"
// #include "Especies/Erizo.h"
// #include "Especies/Lagartija.h"
using namespace std;  
 
/* ________________________funciones_main.h_____________________________________ 
_______________________________________________________________________________*/ 
 
 
 
const string RUTA_ARCHIVO = "animales.csv"; 
const string COMA_ESPACIO = ", "; 
const int BLOQUE_ANIMALES = 5; // Cantidad de memoria a pedir. 
const char DELIMITADOR_ARCHIVO_CSV = '\n'; 
const string CANCELAR = "CANCELAR";


enum OpcionMenu {
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMALES,
    ADOPTAR_ANIMAL,
    GUARDAR_Y_SALIR,
    CANTIDAD_OPCIONES = 6
};

enum OpcionMenuOpcion4 {
    ELEGIR_ANIMAL = 1,
    ALIMENTAR_TODOS,
    DUCHAR_TODOS,
    VOLVER_MENU_PPAL,
    CANTIDAD_OPCIONES_OP4 = 4
};

enum OpcionElegirAnimal {
    ALIMENTAR = 1,
    DUCHAR,
    SIGUIENTE,
    VOLVER_MENU_OP4,
    CANTIDAD_OPCIONES_EA = 4
};

/*________cargar_guarderia()_______________________________________________________ 
 PRE:  
             
 POST: 
_______________________________________________________________________________*/ 
void cargar_guarderia(Guarderia* mi_guarderia); 

void imprimir_menu(int cantidad_elecciones);


/*________pedir_eleccion()_____________________________________________________ 
 PRE: 
 POST: Le pide al usuario que ingrese una opcion de la lista hasta que sea una  
 opcion valida, y la devuelve. 
_______________________________________________________________________________*/ 
int  pedir_eleccion(int cantidad_opciones); 


/*________ejecutar_eleccion()__________________________________________________ 
 PRE:  Recibe un puntero mi_Guarderia (Una Guarderia con la 
  lista de Animales y la cantidad). 
       Recibe la eleccion del usuario verificada (int) entre 1 y CANTIDAD_OPCIONES 
 POST: Ejecuta la funcion correpondiente a la eleccion del usuario. 
_______________________________________________________________________________*/ 
void ejecutar_eleccion( Guarderia* mi_Guarderia, int eleccion); 

Animal* crear_nuevo_animal( char especie, string nombre, int edad, string tamano, string personalidad );


////////////////////////////////////////////////////////////////////////////////////
 
 
/*________verificar_almacenamiento()___________________________________________ 
 PRE: Recibe puntero a la Guarderia actual. 
 Controlo si se lleno lo que reserve, si es asi reservo mas 
 POST: Si tiene la cantidad de memoria dinamica reservada llena, pide mas. 
_______________________________________________________________________________*/ 
void verificar_almacenamiento( Guarderia* mi_Guarderia ); 
 
 
/*________escribir_archivo()___________________________________________________ 
 PRE:   Necesita el archivo llamado RUTA_ARCHIVO para guaradr la información  
    de los Animales en formato csv:  
            titulo, genero, puntaje \n 
        Recibe un puntero a la Guarderia con la informacion ac- 
    tual de los Animales 
 POST:  
_______________________________________________________________________________*/ 
void escribir_archivo( Guarderia* mi_Guarderia ); 
 
 
/*________guardar_un_animal()___________________________________________________ 
 PRES:  - A partir de la linea csv guarda el animal con esos datos 
        - Necesita la Guarderia actual. 
        - String con los datos del animal a agregar en formato csv: 
            titulo, genero, puntaje 
 POST: Guarda en la base de datos actual el animal (en el arreglo de Animales) con 
sus datos (titulo, genero, puntaje y posicion), y la cantidad de Animales actual. 
_______________________________________________________________________________*/ 
void guardar_un_animal( Guarderia* mi_Guarderia,  string animal_csv); 

 

 
/*________mostrar_un_animal()___________________________________________________ 
PRE:  Recibe la base de datos (puntero a Guarderia) y el nume- 
ro_de_animal en la lista (int) 
POST: Imprime en terminal una linea con los datos de animal de forma completa 
_______________________________________________________________________________*/ 
void mostrar_un_animal( Guarderia* mi_Guarderia, int numero_de_animal ); 


#endif
