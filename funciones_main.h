#ifndef FUNCIONES_MAIN_H_ 
#define FUNCIONES_MAIN_H_ 
#include <string> 
#include "Archivos_auxiliares/nodo.h" 
#include "Guarderia.h"
using namespace std;  
 
/* ________________________funciones_main.h_____________________________________ 
_______________________________________________________________________________*/ 


const string RUTA_ARCHIVO = "animales.csv"; 
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


/*________crear_nuevo_animal()__________________________________________________ 
 PRE:  Datos para crear el animal son correctos
 POST: Crea un animal y devuelve un puntero al animal creado. 
_______________________________________________________________________________*/ 
Animal* crear_nuevo_animal( char especie, string nombre, int edad, string tamano, string personalidad );


/*________cargar_guarderia()_______________________________________________________ 
 PRE: Guarderia fue creada correctamente
 POST: Carga la guardería con los animales leídos de un archivo
      predeterminado. Si el archivo no existe, lo crea y deja la guardería vacía.
_______________________________________________________________________________*/ 
void cargar_guarderia(Guarderia* mi_guarderia); 


/*________imprimir_menu()_______________________________________________________ 
 PRE:  La cantidad de elecciones es un entero 4 o 6 
 POST: Imprime en pantalla el menú de acuerdo con el valor de cantidad_elecciones
_______________________________________________________________________________*/ 
void imprimir_menu(int cantidad_elecciones);


/*________pedir_eleccion()_____________________________________________________ 
 PRE:  Recibe cantidad_opciones que es 4 o 6 según el menú que se esté
      ejecutando.
 POST: Pide al usuario opcion a ejecutar y devuelve la elección. Si no se ingresó
       una opcion correcta, la pide nuevamente.
_______________________________________________________________________________*/ 
int  pedir_eleccion(int cantidad_opciones); 


/*________ejecutar_eleccion()__________________________________________________ 
 PRE:  Guarderia fue creada correctamente, la elección es entero entre 1 y 
       CANTIDAD_OPCIONES 
 POST: Ejecuta la funcion correpondiente a la eleccion del usuario. 
_______________________________________________________________________________*/ 
void ejecutar_eleccion( Guarderia* mi_Guarderia, int eleccion); 


#endif
