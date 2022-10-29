#include <iostream> 
#include <string>
#include <fstream> 
#include "funciones_main.h"
#include "Animal.h"
#include "Guarderia.h"
using namespace std; 

/*_____________________________TP2: LA RESERVA SOÑADA____________________*/
int main(){

    cout << "Hola,\nEn este programa te aseguramos una Reserva Soñada.\n     DISFRUTALO!" << endl;
    
// VER COMO MANEJAMOS EL MAIN, DONDE LEEMOS EL ARCHIVO?
// HACEMOS UN CONSTRUCTOR QUE RECIBA LA RUTA DEL ARCHIVO?

    // Guarderia* mi_guarderia  =  leer_archivo();
    // Guarderia mi_guarderia;
    int eleccion = 0;
    int estado_guarderia = ESTADO_ABIERTA;

    while ( estado_guarderia == ESTADO_ABIERTA ){
        eleccion = pedir_eleccion();
        cout << "Elegiste la opcion "<< eleccion << endl << endl;
        // ejecutar_eleccion( mi_guarderia, eleccion );
    }
    
    // delete mi_guarderia;
    // mi_guarderia = nullptr;
    return 0;
}
