#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using namespace std; 

const int EDAD_MAX = 100;
const int HAMBRE_MAX = 100;
const int HIGIENE_MAX = 100;
const int CANTIDAD_ESPECIES = 7; 
const int CANTIDAD_PERSONALIDADES = 4;
const int CANTIDAD_TAMANOS = 5;

const char ESPECIE_CHAR[ CANTIDAD_ESPECIES ] = { 'P', 'G', 'C', 'R', 'O', 'E', 'L' }; 
const string ESPECIE_STRING[ CANTIDAD_ESPECIES ]= { "Perro", "Gato", "Caballo", "Roedor", "Conejo", "Erizo", "Lagartija" }; 
const string PERSONALIDADES[ CANTIDAD_PERSONALIDADES ] = { "Dormilón", "Juguetón", "Sociable", "Travieso" };
const string TAMANOS_STRING[ CANTIDAD_TAMANOS ] = { "Diminuto", "Pequeño", "Mediano", "Grande", "Gigante" };

enum Especie { ESPECIE_INVALIDA = 0, P, G, C, R, O, E, L }; 

class Animal{
protected:
    string nombre;
    int    edad;	        //  [0-100]
    string tamano;	        //	[ D<2, P<10, M>=10, Gr>=20, Gi>=50 ]    
    string personalidad;	// 	[D J S T]
    bool   es_domestico;	//  [lo define la especie, indica si es adoptable]
    int    hambre; 	        //	[0-100]
    int    higiene;	        //	[0-100]
    string comida;	        //	[lo define la especie, es lo que va a imprimir]
public:

/*________constructor Animal default___________________________________________
 PRE: - 
 POST: En el objeto Animal establece higiene = 100 y hambre = 0
_______________________________________________________________________________*/
    Animal();


/*________constructor Animal con parametros____________________________________
 PRE: Los datos ingresados deben ser validados y correctos
 POST: En el objeto Animal carga los datos ingresados
       Establece higiene = 100 y hambre = 0
_______________________________________________________________________________*/
    Animal( string nombre, int edad, string tamano, string personalidad );

/*________destructor Animal con parametros____________________________________
 PRE: 
 POST: 
_______________________________________________________________________________*/
    virtual ~Animal() = 0;


/*________alimentar()_______________________________________________________
 PRE: -
 POST: Establece hambre = 0 y muestra al usuario su nombre y comida
_______________________________________________________________________________*/
    void alimentar();


/*________duchar()_____________________________________________________________
 PRE: -
 POST: Establece higiene = 100
_______________________________________________________________________________*/
    void duchar();


/*________mostrar()_____________________________________________________
 PRE: -
 POST:  El Animal se muestra individualmente,
        nombre, edad, tamano, especie, personalidad, hambre e higiene.
_______________________________________________________________________________*/
    virtual void mostrar();


/*________obtener_nombre()_____________________________________________________
 PRE: -
 POST:  Devuelve el nombre del animal
_______________________________________________________________________________*/
    string obtener_nombre();

    int obtener_edad();

    string obtener_tamano();

    string obtener_personalidad();

    virtual Especie resolver_especie() = 0;

    bool es_adoptable();

};
#endif
