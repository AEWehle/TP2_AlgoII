#include <iostream> 
#include <string>
#include <fstream> 
#include "funciones_main.h"
using namespace std; 

/*_____________________________TP2: LA RESERVA SOÑADA____________________*/
int main(){

    cout << "Hola,\nEn este programa te aseguramos una Reserva Soñada.\n     DISFRUTALO!" << endl;
    
    Guarderia* mi_guarderia  =  leer_archivo();
    int eleccion = 0;

    while ( mi_guarderia -> lista_de_animales != nullptr ){
        eleccion = pedir_eleccion();
        cout << "Elegiste la opcion "<< eleccion << endl << endl;
        ejecutar_eleccion( mi_guarderia, eleccion );
    }
    
    delete mi_guarderia;
    mi_guarderia = nullptr;
    return 0;
}
