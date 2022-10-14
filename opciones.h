#ifndef _OPCIONES_EDL_H_
#define _OPCIONES_EDL_H_
#include <string>
#include "funciones_main.h"
using namespace std; 


/* ________________________Opciones_EDL.h_____________________________________
  En este .h se encuentran declaradas las funciones que se ejecutan según la 
elección del usuario.
_______________________________________________________________________________*/

/*________listar_animales()______________________________________________________
 PRE:  El usuario pidio listar los animales, recibe una structura tipo Guarderia
 con la informacion actual.
 POST: Imprime en terminal los datos de los animales guardados.
_______________________________________________________________________________*/
void listar_animales      ( Guarderia* mi_guarderia );


/*________rescatar_animal()______________________________________________________
 PRE:  
 POST: 
_______________________________________________________________________________*/
void rescatar_animal      ( Guarderia* mi_guarderia );


/*________editar_puntaje()______________________________________________________
 PRE:  
 POST:
_______________________________________________________________________________*/
void editar_puntaje     ( Guarderia* mi_guarderia );


/*________animal_favorito()_____________________________________________________
 PRE:  
 POST: 
_______________________________________________________________________________*/
void animal_favorito     ( Guarderia* mi_guarderia );


/*________tres_menor_puntaje()_________________________________________________
 PRE:  
 POST: 
_______________________________________________________________________________*/
void tres_menor_puntaje ( Guarderia* mi_guarderia );


/*________genero_mas_leido()___________________________________________________
 PRE:  
 POST: 
_______________________________________________________________________________*/
void genero_mas_leido   ( Guarderia* mi_guarderia );


/*________genero_favorito()____________________________________________________
 PRE:  
 POST: 
_______________________________________________________________________________*/
void genero_favorito    ( Guarderia* mi_guarderia );


/*________guardar_salir()______________________________________________________
 PRE:  Recibe la base de datos actual.
 POST: Guarda en el archivo llamado RUTA_ARCHIVO la informacion en la base de
  datos y libera la memoria.
_______________________________________________________________________________*/
void guardar_salir      ( Guarderia* mi_guarderia );


typedef void (*Manejo_Guarderia) (Guarderia* mi_guarderia );
const Manejo_Guarderia funcion_elegida[ CANTIDAD_OPCIONES ] = {
    listar_animales, 
    rescatar_animal,
    editar_puntaje,
    animal_favorito,
    tres_menor_puntaje,
    genero_mas_leido,
};

#endif