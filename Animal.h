#ifndef _ANIMAL_H
#define _ANIMAL_H
#include <string>
using namespace std; 

const int EDAD_MAX = 100;
const int HAMBRE_MAX = 100;
const int HIGIENE_MAX = 100;


class Animal{
protected:
    string nombre;
    int    edad;	        //  [0-100]
    string tamano;	        //	[ D <2, P<10, M >= 10, Gr>= 20, Gi >= 50 ]
    string personalidad;	// 	[D J S T]
    bool   es_domestico;	//  [lo define la especie, indica si es adoptable]
    int    hambre; 	        //	[0-100]
    int    higiene;	        //	[0-100]
    char   especie;
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


/*________mostrar_animal()_____________________________________________________
 PRE: -
 POST:  El Animal se muestra individualmente,
        nombre, edad, tamano, especie, personalidad, hambre e higiene.
_______________________________________________________________________________*/
    void mostrar();

/*________mostrar()___________________________________________________________
 PRE:   Las clases hijas deben tener este método
 POST:  Le pasa al método mostrar_animal() la especie
    esta última se encargará de mostrarlo
_______________________________________________________________________________*/
    // virtual void mostrar() = 0;


};
#endif // SISTEMA_H