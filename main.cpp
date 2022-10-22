#include <iostream> 
#include <string>
#include <fstream> 
#include "funciones_main.h"
using namespace std; 


// COMANDO: g++ *.cpp Especies/*.cpp -o TP2 -Wall -Werror -Wconversion
//./TP2
// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./TP1
// gdb ./Prueba

// git status                                   Para ver lo que esta para subirse
// git add .                                    Para agregar a las cosas a subirse
// git commit -m "mensaje para nuestro grupo"   Para guardarlo y en un futuro subirlo con git push
// git log --oneline                            Para ver el historial de Commits
// git push                                     Lo sube a la nube 
//          ponen su nombre de usuario
//          ponen la siguiente clave --->  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
// git pull                                     Ponerlo para verificar si alguine del grupo pusheó algún cambio
//                                              te asegurás tenes la úlrima versión
// git checkout nombre_branch                   Primero hacerlo con la main y despues con la brunch en la que estás trabajando
// git chechout -b nombre_nueva_brunch          Crear brunch
// git push origin nombrE_nueva_brunch          Luego de haber hecho add y commit

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