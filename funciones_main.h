#ifndef _FUNCIONES_MAIN_H_
#define _FUNCIONES_MAIN_H_
#include <string>
using namespace std; 

// Podemos cambiarle el nombre a este archivo#ifndef _FUNCIONES_EDL_H_

/* ________________________Funciones_EDL.h_____________________________________
_______________________________________________________________________________*/



const string RUTA_ARCHIVO = "Animales.csv";
const string COMA_ESPACIO = ", ";
const int BLOQUE_ANIMALES = 5; // Cantidad de memoria a pedir.
const char DELIMITADOR_ARCHIVO_CSV = '\n';
const string RUTA_ARCHIVO = "animales.csv";
const int CANTIDAD_OPCIONES = 6;
// const int CANTIDAD_GENEROS = 6;
// const int EDAD_MAX = 100;


/*________Animal________________________________________________________________
 La estructura guarda la informacion de un animal
 El titulo, todo en mayusculas
 El genero, char mayuscula respetando relacion GENEROS_CHAR <-> GENEROS_STRING
 El puntaje, valor de 0 a PUNTAJE_MAX
_______________________________________________________________________________*/
struct Animal{ //nombre,edad,tamaño,especie,personalidad 
// TIENE ESTA FORA PPOR AHORA, ES SOLO PARA QUE NO ME APAREZCAN ERRORES
    string nombre;
    int edad;   
    string tamaño;
    char especie;
    string personalidad;
};


/*________Guarderia___________________________________________________________
 Esta estructura va a guarda toda la informacion extraida del archivo en una 
 lista de Animales.
 Tiene la cantidad de Animales guardados y por 'ultimo una bool que indica si se 
 realizaron cambios en los datos, justificando reescribir el archivo original
 al cerrar el programa.
_______________________________________________________________________________*/
struct Guarderia{
    Animal ** lista_de_animales;
    int cantidad_de_animales;
    bool hubo_cambios = false;
};



/*________leer_archivo()_______________________________________________________
 PRE:  Necesita el archivo llamado RUTA_ARCHIVO con la informacion de los anim-
 ales en formato csv: 
            
 POST: Devuelve ....
_______________________________________________________________________________*/
Guarderia* leer_archivo();


/*________verificar_almacenamiento()___________________________________________
 PRE: Recibe puntero a la estructura tipo Guarderia actual.
 Controlo si se lleno lo que reserve, si es asi reservo mas
 POST: Si tiene la cantidad de memoria dinamica reservada llena, pide mas.
_______________________________________________________________________________*/
void verificar_almacenamiento( Guarderia* mi_Guarderia );


/*________escribir_archivo()___________________________________________________
 PRE:   Necesita el archivo llamado RUTA_ARCHIVO para guaradr la información 
    de los Animales en formato csv: 
            titulo, genero, puntaje \n
        Recibe un puntero a la strudtura tipo Guarderia con la informacion ac-
    tual de los Animales
 POST: 
_______________________________________________________________________________*/
void escribir_archivo( Guarderia* mi_Guarderia );


/*________guardar_un_animal()___________________________________________________
 PRES: Recibe:
        - Puntero a la estructura tipo Guarderia actual.
        - String con los datos del animal a agregar en formato csv:
            titulo, genero, puntaje
 POST: Guarda en la base de datos actual el animal (en el arreglo de Animales) con
sus datos (titulo, genero, puntaje y posicion), y la cantidad de Animales actual.
_______________________________________________________________________________*/
void guardar_un_animal( Guarderia* mi_Guarderia,  string animal_csv);


/*________buscar_titulo()______________________________________________________
PRE:  Recibe la base de datos (puntero a estructura tipo Guarderia) y el titu-
 lo de animal buscado (string)
POST: Devuelve el numero de animal correspondiente en la lista de Animales de la 
 Base de Datos, si el animal no lo encuentra devuelve la Cantidad de Animales en 
 la base de datos.
_______________________________________________________________________________*/
int buscar_titulo (Guarderia* mi_Guarderia, string titulo_buscado);


/*________verificar_eleccion()_________________________________________________
 PRE:  Recibe la eleccion del ususario recibida como int
 POST: Devuelve true si es valida y false si no.
_______________________________________________________________________________*/
bool verificar_eleccion( int eleccion );


/*________ejecutar_eleccion()__________________________________________________
 PRE:  Recibe un puntero a la mi_Guarderia (Una estructura tipo Guarderia con la
  lista de Animales y la cantidad).
       Recibe la eleccion del usuario verificada (int) entre 1 y CANTIDAD_OPCIONES
 POST: Ejecuta la funcion correpondiente a la eleccion del usuario.
_______________________________________________________________________________*/
void ejecutar_eleccion( Guarderia* mi_Guarderia, int eleccion );


/*________buscar_titulo()______________________________________________________
PRE:  Recibe la base de datos (puntero a estructura tipo Guarderia) y el titu-
 lo de animal buscado (string)
POST: Devuelve el numero de animal correspondiente en la lista de Animales de la 
 Base de Datos, si el animal no lo encuentra devuelve la Cantidad de Animales en 
 la base de datos.
_______________________________________________________________________________*/
int buscar_titulo (Guarderia* mi_Guarderia, string titulo_buscado);


/*________mostrar_un_animal()___________________________________________________
PRE:  Recibe la base de datos (puntero a estructura tipo Guarderia) y el nume-
ro_de_animal en la lista (int)
POST: Imprime en terminal una linea con los datos de animal de forma completa
    TITULO, GENERO, PUNTAJE
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