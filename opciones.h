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
 POST: Imprime en temrinal los titulos de los lbros en la base de datos actual.
_______________________________________________________________________________*/
void listar_animales      ( Guarderia* mi_guarderia );


/*________agregar_animal()______________________________________________________
 PRE:  Recibe la base de datos actual, estructura tipo Guarderia.
 POST: Segun lo ingresado por el usuario lo guarda en la base de datos.
_______________________________________________________________________________*/
void agregar_animal      ( Guarderia* mi_guarderia );


/*________editar_puntaje()______________________________________________________
 PRE:  Recibe la base de datos actual, estructura tipo Guarderia.
       Le pregunta al usuario a qué titulo quiere editar su puntaje.
 POST: Enuentra la primera aparicion del titulo y luego de preguntarle el punta-
 je nuevo lo modifica en la base de datos.
_______________________________________________________________________________*/
void editar_puntaje     ( Guarderia* mi_guarderia );


/*________animal_favorito()_____________________________________________________
 PRE:  Recibe la base de datos actual, estructura tipo Guarderia.
 POST: Enuentra el animal con mayor puntaje en la base de datos y se la muestra 
 al usuario.
_______________________________________________________________________________*/
void animal_favorito     ( Guarderia* mi_guarderia );


/*________tres_menor_puntaje()_________________________________________________
 PRE:  Recibe la base de datos actual, estructura tipo Guarderia.
 POST: Encuentra los 3 animales con menor puntaje y los muestra.
_______________________________________________________________________________*/
void tres_menor_puntaje ( Guarderia* mi_guarderia );


/*________genero_mas_leido()___________________________________________________
 PRE:  Recibe la base de datos actual, estructura tipo Guarderia.
 POST: Encuentra el o los (empate) generos que tiene mas animales y los muestra 
 en terminal junto con la cantidad de animal con esos géneros.
_______________________________________________________________________________*/
void genero_mas_leido   ( Guarderia* mi_guarderia );


/*________genero_favorito()____________________________________________________
 PRE:  Recibe la base de datos actual, estructura tipo Guarderia.
 POST: Encuentra el o los (empate) generos que tienen el puntaje promedio mas 
 alto y los muestra junto con el promedio.
_______________________________________________________________________________*/
void genero_favorito    ( Guarderia* mi_guarderia );


/*________guardar_salir()______________________________________________________
 PRE:  Recibe la base de datos actual, estructura tipo Guarderia.
 POST: Guarda en el archivo llamado RUTA_ARCHIVO la infromacion en la base de
  datos y libera la memoria.
_______________________________________________________________________________*/
void guardar_salir      ( Guarderia* mi_guarderia );


typedef void (*Manejo_Guarderia) (Guarderia* mi_guarderia );
const Manejo_Guarderia funcion_elegida[ CANTIDAD_OPCIONES ] = {
    listar_animales, 
    agregar_animal,
    editar_puntaje,
    animal_favorito,
    tres_menor_puntaje,
    genero_mas_leido,
};

#endif