#include <iostream>  
#include <string> 
#include <fstream>
#include <limits>
#include "Archivos_auxiliares/funciones_auxiliares.h" 
#include "Archivos_auxiliares/nodo.h"
#include "funciones_main.h" 
#include "Guarderia.h"
using namespace std;  


/*************************************** FUNCIONES DE LA OPCION 1 ***************************************/ 
// Listar animales

void listar_animales( Guarderia* mi_guarderia ){ 
    mi_guarderia->ver_lista_de_animales();
/*
    if (mi_guarderia->obtener_cantidad()==0) {
        preguntar_agregar_animal( mi_guarderia );   //es necesario esto?
    }*/
}
 
/*
void preguntar_agregar_animal( Guarderia* mi_guarderia ){ 
    cout << "Querés agregar un animal nuevo?\n [SI, NO]\n >> "; 
    string linea_aux; 
    while ( linea_aux.length() == 0 ){ 
        cout << " >> "; 
        getline( cin, linea_aux, '\n' ); 
    } 
 
    if (string_a_mayuscula(linea_aux) == "SI"){ 
        rescatar_animal( mi_guarderia ); 
    } 
    else { 
        cout << "Ok, no agregamos nada." << endl;  
        cout << endl << "Qué mas te gustaría hacer?\n"; 
    } 
} 
*/
 
/*************************************** FUNCIONES DE LA OPCION 2 ***************************************/ 
//Rescatar animal

//  nombre, edad, tamano, especie, personalidad, hambre e higiene.
 
string pedir_nombre(){ 
    cout << "Cómo se va a llamar?" << endl; 
    string nombre; 
    while ( nombre.length() == 0 ){ 
        //cout << " >> "; 
        getline( cin, nombre, '\n' ); 
    } 
    //nombre = string_a_mayuscula(nombre);    //es necesario?
    return nombre; 
} 

int buscar_nombre (Guarderia* mi_guarderia, string animal_buscado){
    return mi_guarderia->obtener_posicion(animal_buscado);
}

 
/*________pedir_edad()______________________________________________________ 
PRE:  Le pide al usuario la edad hasta que cumpla que va de 0 a EDAD_MAX 
POST: Devuelve int con el valor. 
_______________________________________________________________________________*/ 
int pedir_edad(){ 
    cout << "Cuántos años tiene?" << endl << " >> ";
    int edad;  
    cin >> edad; //Si ingresan una letra lo toma como edad 0. Habría que arreglarlo
    while( !(edad >= 0 && edad <= EDAD_MAX) ){ 
        cout << "Tiene que ser entre 0 y "<< EDAD_MAX << ", volvé a ingresar la edad:" << endl << " >> "; 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> edad;
    } 
    return edad; 
} 
 

string numero_a_tamano_string( int numero ){
    //	[ D <2, P<10, M >= 10, Gr>= 20, Gi >= 50 ]
    // es 0 -> D, 1 -> P , 2 -> M , 3 -> Gr , 4 -> Gi
    int i = (int)( numero >= 50) + (int)( numero >= 20) + (int)( numero >= 10) + (int)( numero >= 2);
    return TAMANOS_STRING[i];
}

int numero_a_tamano( int numero ){
    return (int)( numero >= 50) + (int)( numero >= 20) + (int)( numero >= 10) + (int)( numero >= 2);
}


/*________pedir_tamano()______________________________________________________ 
PRE:  Le pide al usuario el yamano hasta que sea un numero.
    Si ingresa un número negativo ignora el signo.
POST: Devuelve la calsificación correspondiente con el valor. 
_______________________________________________________________________________*/ 
int pedir_tamano(){ 
    cout << "Qué tamaño tiene?" << endl 
    << "Elegí de entre los siguientes según el espacio que necesite:" << endl << endl

    << "1 - Diminuto -> menos de 2 m^2" << endl
    << "2 - Pequeño  -> menos de 10 m^2" << endl
    << "3 - Mediano  -> 10 m^2 o más" << endl
    << "4 - Grande   -> 20 m^2 o más" << endl
    << "5 - Gigante  -> 50 m^2 o más" << endl << endl;
    
    int tamano;  
    cin >> tamano;

    while( !(tamano >= 1 && tamano <= 5)){ 
        cout << "Ingresá el número correspondiente a una categoría:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> tamano;
    }
    
    return tamano-1; 
} 


/*
void imprimir_tabla_especies(){
    for (int i = 0 ; i < CANTIDAD_ESPECIES ; i++ ){
        cout << "  " << ESPECIE_CHAR[i] << " - " << ESPECIE_STRING[i] << endl;
    }
}
*/

/*________es_espeice_posible()__________________________________________________ 
    PRE: Recibe la especie ingresada todo en mayusculas, lo busca entre los pos- 
    ibles. 
    POST: Devuelve true o false si está o no respectivamente 
_______________________________________________________________________________*/ 
/*
bool es_especie_posible ( string especie ) { 
    bool todo_bien = false; 
    int posicion = buscar_en_array_de_string( ESPECIE_STRING, especie, CANTIDAD_ESPECIES ); 
        if (posicion != CANTIDAD_ESPECIES){ 
            todo_bien = true; 
        } 
        else if ( especie.length() == 1 ){ 
            //posicion = ESPECIE_CHAR.find( especie[0] ); 
            if (posicion < CANTIDAD_ESPECIES && posicion >= 0){ 
                todo_bien = true; 
            } 
        } 
        else{ 
            cout << "No se recastan animales de esa especie, puede ser:\n"; 
            imprimir_tabla_especies(); 
        } 
    return todo_bien; 
} */

 
/*________pedir_especie()______________________________________________________ 
PRE:  Le pide al usuario el especie hasta que cumpla las condiciones 
POST: Devuelve char del especie. 
_______________________________________________________________________________*/ 
int pedir_especie(){ 

    cout << "De qué especie es?" << endl 
    << "Elegí de entre las siguientes:" << endl << endl

    << "1 - Perro" << endl
    << "2 - Gato" << endl
    << "3 - Caballo" << endl
    << "4 - Roedor" << endl
    << "5 - Conejo" << endl
    << "6 - Erizo" << endl
    << "7 - Lagartija" << endl << endl;
    
    int especie;
    cin >> especie;

    while( !(especie >= 1 && especie <= 7)){ 
        cout << "Ingresá el número correspondiente a una especie:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> especie;
    }
    
    return especie-1;

}

/*________pedir_especie()______________________________________________________ 
PRE:  Le pide al usuario la personalidad hasta que sea uno posible
POST: Devuelve el string de la personalidad.
_______________________________________________________________________________*/ 
int pedir_personalidad(){

    cout << "Qué personalidad tiene?" << endl 
    << "Elegí de entre las siguientes:" << endl << endl

    << "1 - Dormilón" << endl
    << "2 - Juguetón" << endl
    << "3 - Sociable" << endl
    << "4 - Travieso" << endl << endl;
    
    int personalidad;  
    cin >> personalidad;

    while( !(personalidad >= 1 && personalidad <= 4)){ 
        cout << "Ingresá el número correspondiente a una personalidad:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> personalidad;
    }
    
    return personalidad-1;

}
 
 
void rescatar_animal( Guarderia* mi_guarderia ){ 
    cout << endl << "Rescataste un animal?" << endl; 
 
    string nombre = pedir_nombre();
    int opcion;
    
    while (buscar_nombre( mi_guarderia, nombre ) != NO_SE_ENCUENTRA){  
        cout << "Este nombre ya lo tiene otro animal! Podés elegir otro nombre o volver al menú." << endl
        << "Para elegir otro nombre ingresá 1, para volver al menú ingresá 2:" << endl;
 
        cin >> opcion;

        while( opcion != 1 && opcion != 2 ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingresá 1 para elegir otro nombre o 2 para volver al menú:" << endl;
            cin >> opcion;
        }

        if (opcion == 2) return;

        nombre = pedir_nombre();

    } 

    int edad = pedir_edad();
    string tamano = TAMANOS_STRING[pedir_tamano()]; 
    char especie = ESPECIE_CHAR[pedir_especie()];
    string personalidad = PERSONALIDADES[pedir_personalidad()];

    Animal* nuevo_animal = crear_nuevo_animal(especie, nombre, edad, tamano, personalidad);

    mi_guarderia -> agregar_animal(nuevo_animal);

    cout << endl << nombre << " fue rescatado!" << endl << endl;

} 
 
 
 
/*************************************** FUNCIONES DE LA OPCION 3 ***************************************/ 

void buscar_animal( Guarderia* mi_guarderia ){
    string nombre;

    cout << "Ingrese el nombre del animal que busca:";
    getline(cin,nombre,'\n');

    if(buscar_nombre(mi_guarderia,nombre) == NO_SE_ENCUENTRA){
        cout << nombre << "no se encuentra en la guardería." << endl;
    }else{
        mi_guarderia->mostrar(buscar_nombre(mi_guarderia,nombre));
    }
}
 
/*************************************** FUNCIONES DE LA OPCION 4 ***************************************/ 
 
void cuidar_animales( Guarderia* mi_guarderia ){}
 
 
/*************************************** FUNCIONES DE LA OPCION 5 ***************************************/ 
 
void adoptar_animal( Guarderia* mi_guarderia ){}

 
/*************************************** FUNCIONES DE LA OPCION 6 ***************************************/ 

/*
void guardar_un_animal(Animal* animal, fstream archivo){

    string nombre = animal -> obtener_nombre();
    int edad = animal -> obtener_edad();
    string tamano = animal -> obtener_tamano();
    string especie = ESPECIE_STRING[animal -> resolver_especie()];
    string personalidad = animal -> obtener_personalidad();

    archivo << nombre << "," << edad << "," << tamano << "," << especie << "," << personalidad << endl;

}*/

 
void guardar_salir( Guarderia* mi_guarderia ){ 

    cout << "Guardando..." << endl; 

    fstream archivo_guarderia(RUTA_ARCHIVO, ios::out);
 
    for ( int numero_de_animal = 0; numero_de_animal < (mi_guarderia->obtener_cantidad()) ; numero_de_animal++ ){ 
        
        string nombre = mi_guarderia->mostrar(numero_de_animal) -> obtener_nombre();
        int edad = mi_guarderia->mostrar(numero_de_animal) -> obtener_edad();
        string tamano = mi_guarderia->mostrar(numero_de_animal) -> obtener_tamano();
        string especie = ESPECIE_STRING[mi_guarderia->mostrar(numero_de_animal) -> resolver_especie()];
        string personalidad = mi_guarderia->mostrar(numero_de_animal) -> obtener_personalidad();

        archivo_guarderia << nombre << "," << edad << "," << tamano << "," << especie << "," << personalidad << endl;

    } 
 
    archivo_guarderia.close(); 

    cout << "Listo, tu registro de animales esta terminado." << endl << "Hasta la proxima!" << endl; 

} 
