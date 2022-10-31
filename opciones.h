#ifndef OPCIONES_H
#define OPCIONES_H
#include <string>
#include "funciones_main.h"
using namespace std; 



/* ________________________opciones.h_____________________________________
  En este .h se encuentran declaradas las funciones que se ejecutan según la 
elección del usuario.
_______________________________________________________________________________*/

/*________listar_animales()______________________________________________________
 PRE:  El usuario pidio listar los animales, recibe una structura tipo Guarderia
 con la informacion actual.
 POST: Imprime en terminal los datos de los animales guardados.
_______________________________________________________________________________*/
void listar_animales( Guarderia* mi_guarderia );


/*________rescatar_animal()______________________________________________________
 PRE:  Serescató un animal y hay que agregarlo a la lista de animales en la rese-
 rva recibe una structura tipo Guarderia con la informacion actual.
 POST: Guarda el animal.
_______________________________________________________________________________*/
void rescatar_animal      ( Guarderia* mi_guarderia );


/*________buscar_animal()______________________________________________________
 PRE:  
 POST: 
_______________________________________________________________________________*/
void buscar_animal        ( Guarderia* mi_guarderia );
 

 /*________cuidar_animal()______________________________________________________
 PRE:  
 POST: 
_______________________________________________________________________________*/
void cuidar_animales      ( Guarderia* mi_guarderia );
 

 /*________adoptar_animal()______________________________________________________
 PRE:  
 POST: 
_______________________________________________________________________________*/
void adoptar_animal       ( Guarderia* mi_guarderia );


/*________guardar_salir()______________________________________________________
 PRE:  Recibe la base de datos actual.
 POST: Guarda en el archivo llamado RUTA_ARCHIVO la informacion en la base de
  datos y libera la memoria.
_______________________________________________________________________________*/
void guardar_salir( Guarderia* mi_guarderia );


typedef void (*Manejo_Guarderia) (Guarderia* mi_guarderia );
const Manejo_Guarderia funcion_elegida[ CANTIDAD_OPCIONES ] = {
    listar_animales, 
    rescatar_animal,
    buscar_animal,
    cuidar_animales,
    adoptar_animal,
    guardar_salir,
};

#endif
