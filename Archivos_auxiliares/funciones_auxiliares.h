#ifndef _FUNCIONESAUXILIARES_H_
#define _FUNCIONESAUXILIARES_H_
#include <string>
using namespace std; 


/*__________________________FuncnionesAuxioliares.h____________________________
    En este.h estan declaradas funciones auxiliares necesarias para el funcion-
amiento general del programa, no son especificas para el TP, se pueden usar en
 cualquier otro respetando las especificaciones.
_______________________________________________________________________________*/


/*________char_a_mayuscula()___________________________________________________
 PRE: Recive una letra (char), no entiende letras con tilde
 POST: Devuelve la misma (char) pero en mayucula.
_______________________________________________________________________________*/
char char_a_mayuscula(char letra);


/*________string_a_mayuscula()_________________________________________________
 PRE: Recive un texto (string)
 POST: Devuelve el mismo (string) pero en mayucula.
_______________________________________________________________________________*/
string string_a_mayuscula(string texto);


/*________elimina_espacios()___________________________________________________
 PRE: Recive un texto (string)
 POST: Devuelve el mismo (string) pero sin los isspace().
_______________________________________________________________________________*/
string elimina_espacios(string texto);


/*________string_a_entero()____________________________________________________
 PRE: Recive un texto (string)
 POST: Devuelve un entero con los numeros que fueron apareciendo.
_______________________________________________________________________________*/
int string_a_entero(string texto);


/*________buscar_en_array_de_string()__________________________________________
PRE:  Recibe el array de strings, el string buscado y el largo del array
POST: Devuelve la posicion correspondiente en el array.
 Si no lo encuentra devuelve el largo del array.
_______________________________________________________________________________*/
int buscar_en_array_de_string( const string* array, string buscado, int largo );


/*________shiftear_a_derecha()_________________________________________________
PRE:  Recibe el array de enteros, y el largo del array
POST: mueve todos los elementos a la derecha y el utimo queda primero
_______________________________________________________________________________*/
void shiftear_a_derecha( int * array, int largo);


/*________menor_alfabetico()___________________________________________________
PRE:  Recibe dos string a comparar
POST: Devuelve el string que esta primeor alfabeticamente
_______________________________________________________________________________*/
string menor_alfabetico( string texto1, string texto2);


/*________llenar_con_int()_____________________________________________________
PRE:  Recibe el array a llenar, el valor con el cual llenarlo y el largo
POST: Llena el array ngresado con el enterod eseado
_______________________________________________________________________________*/
void llenar_con_int ( int* array_int, int entero, int largo );

#endif