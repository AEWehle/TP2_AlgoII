#ifndef FUNCIONES_MAIN_H_ 
#define FUNCIONES_MAIN_H_ 
#include <string> 
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
 
/* ________________________funciones_main.h_____________________________________ 
_______________________________________________________________________________*/ 
 
 
 
const string RUTA_ARCHIVO = "animales.csv"; 
const string COMA_ESPACIO = ", "; 
const int BLOQUE_ANIMALES = 5; // Cantidad de memoria a pedir. 
const char DELIMITADOR_ARCHIVO_CSV = '\n'; 
const int CANTIDAD_OPCIONES = 6; 
const int ESTADO_ABIERTA = 1;
const int ESTADO_CERRADA = 0;
 
 
/*________leer_archivo()_______________________________________________________ 
 PRE:  Necesita el archivo llamado RUTA_ARCHIVO con la informacion de los anim- 
 ales en formato csv:  
             
 POST: Devuelve .... 
_______________________________________________________________________________*/ 
Guarderia* leer_archivo(); 

 
 
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
 
 
/*________verificar_eleccion()_________________________________________________ 
 PRE:  Recibe la eleccion del ususario recibida como int 
 POST: Devuelve true si es valida y false si no. 
_______________________________________________________________________________*/ 
bool verificar_eleccion( int eleccion ); 
 
 
/*________ejecutar_eleccion()__________________________________________________ 
 PRE:  Recibe un puntero mi_Guarderia (Una Guarderia con la 
  lista de Animales y la cantidad). 
       Recibe la eleccion del usuario verificada (int) entre 1 y CANTIDAD_OPCIONES 
 POST: Ejecuta la funcion correpondiente a la eleccion del usuario. 
_______________________________________________________________________________*/ 
void ejecutar_eleccion( Guarderia* mi_Guarderia, int eleccion, int* estado_guarderia ); 
 
 
/*________buscar_nombre()______________________________________________________ 

PRE:  Recibe la base de datos (puntero a clase Guarderia) y el nombre
    del animal buscado (string) 
POST: Devuelve el numero de animal correspondiente en la lista de Animales de la  
 Base de Datos, si no lo encuentra devuelve -1. 
_______________________________________________________________________________*/ 
int buscar_nombre (Guarderia* mi_Guarderia, string animal_buscado); 
 
 
/*________mostrar_un_animal()___________________________________________________ 
PRE:  Recibe la base de datos (puntero a Guarderia) y el nume- 
ro_de_animal en la lista (int) 
POST: Imprime en terminal una linea con los datos de animal de forma completa 
_______________________________________________________________________________*/ 
void mostrar_un_animal( Guarderia* mi_Guarderia, int numero_de_animal ); 
 
 
/*________pedir_eleccion()_____________________________________________________ 
 PRE: 
 POST: Le pide al usuario que ingrese una opcion de la lista hasta que sea una  
 opcion valida, y la devuelve. 
_______________________________________________________________________________*/ 
int  pedir_eleccion(); 
 
 
 
/*________preguntar_agregar_animal()____________________________________________ 
PRE:  Le pregunta al usuario si desea agregar un animal tras haber ingresado un  
titulo no existente para editarlle el puntaje 
POST: Si repsonde Si llama a agregar_animal 
      Si responde cualuqier otra cosa no agrega nada y termina 
_______________________________________________________________________________*/ 
void preguntar_agregar_animal( Guarderia* mi_Guarderia ); 

#endif
