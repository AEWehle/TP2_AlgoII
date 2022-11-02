#ifndef FUNCIONES_MAIN_H_ 
#define FUNCIONES_MAIN_H_ 
#include <string> 
#include "Archivos_auxiliares/nodo.h" 
#include "Guarderia.h"
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
 PRE:  Recibe puntero a mi_guarderia (Guarderia con lista de animales)
             
 POST: La guarderia queda cargada con los animales leídos de un archivo
      predeterminado.
_______________________________________________________________________________*/ 
void cargar_guarderia(Guarderia* mi_guarderia); 


/*________imprimir_menu()_______________________________________________________ 
 PRE:  Recibe la cantidad de opciones que tiene el menu (el programa tiene
      dos menúes: uno con 4 opciones y otro con 6)
             
 POST: Imprime un menú u otro.
_______________________________________________________________________________*/ 
void imprimir_menu(int cantidad_elecciones);


/*________pedir_eleccion()_____________________________________________________ 
 PRE:  Recibe cantidad_opciones que es 4 o 6 según el menú que se esté
      ejecutando.
 POST: Le pide al usuario que ingrese una opcion de la lista hasta que sea una  
 opcion valida, y la devuelve. 
_______________________________________________________________________________*/ 
int  pedir_eleccion(int cantidad_opciones); 


/*________ejecutar_eleccion()__________________________________________________ 
 PRE:  Recibe un puntero mi_Guarderia (Guarderia con lista de animales). 
       Recibe la eleccion del usuario verificada (int) entre 1 y CANTIDAD_OPCIONES 
 POST: Ejecuta la funcion correpondiente a la eleccion del usuario. 
_______________________________________________________________________________*/ 
void ejecutar_eleccion( Guarderia* mi_Guarderia, int eleccion); 


/*________crear_nuevo_animal()__________________________________________________ 
 PRE:  Recibe datos para crear un animal. En base a la especie recibida crea
      un animal de la clase correspondiente (hija de Animal).
 POST: Devuelve un puntero al animal creado. 
_______________________________________________________________________________*/ 
Animal* crear_nuevo_animal( char especie, string nombre, int edad, string tamano, string personalidad );


////////////////////////////////////////////////////////////////////////////////////
 
 
/*________escribir_archivo()___________________________________________________ 
 PRE:   Necesita el archivo llamado RUTA_ARCHIVO para guaradr la información  
    de los Animales en formato csv:  
            titulo, genero, puntaje \n 
        Recibe un puntero a la Guarderia con la informacion ac- 
    tual de los Animales 
 POST:  
_______________________________________________________________________________*/ 
void escribir_archivo( Guarderia* mi_Guarderia ); 


#endif
