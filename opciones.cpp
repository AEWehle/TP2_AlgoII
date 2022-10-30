#include <iostream>  
#include <string> 
#include <fstream> 
#include "Archivos_auxiliares/funciones_auxiliares.h" 
#include "Archivos_auxiliares/nodo.h"
#include "funciones_main.h" 
#include "Guarderia.h"
// #include "Animal.h"  // Se incluyen a traves de guarderia
// #include "Especies/Perro.h"
// #include "Especies/Gato.h"
// #include "Especies/Caballo.h"
// #include "Especies/Roedor.h"
// #include "Especies/Conejo.h"
// #include "Especies/Erizo.h"
// #include "Especies/Lagartija.h"
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
        cout << " >> "; 
        getline( cin, nombre, '\n' ); 
    } 
    nombre = string_a_mayuscula(nombre);    //es necesario?
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
    string edad_string;  
    getline( cin, edad_string, '\n'); 
    int edad = string_a_entero( edad_string ); 
    while( ( edad > EDAD_MAX) || ( edad < 0) || ( edad_string == "" ) ){ 
        cout << "Tiene que ser entre 0 y "<< EDAD_MAX << ", volvé a ingresar la edad:\n >> "; 
        getline( cin, edad_string, '\n'); 
        edad = string_a_entero( edad_string ); 
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
    cout << "Cuánto espacio en m2 necesita para vivir cómodo?\n >> ";
    string tamano_string;  
    getline( cin, tamano_string, '\n'); 
    int tamano = string_a_entero( tamano_string ); 
    while( tamano_string == "" ){ 
        cout << "Tiene que ser un número, volvé a ingresar el tamaño:\n >> "; 
        getline( cin, tamano_string, '\n'); 
        tamano = string_a_entero( tamano_string ); 
    }
    tamano = numero_a_tamano(tamano);
    return tamano; 
} 



void imprimir_tabla_especies(){
    for (int i = 0 ; i < CANTIDAD_ESPECIES ; i++ ){
        cout << "  " << ESPECIE_CHAR[i] << " - " << ESPECIE_STRING[i] << endl;
    }
}


/*________es_espeice_posible()__________________________________________________ 
    PRE: Recibe la especie ingresada todo en mayusculas, lo busca entre los pos- 
    ibles. 
    POST: Devuelve true o false si está o no respectivamente 
_______________________________________________________________________________*/ 
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
} 

 
/*________pedir_especie()______________________________________________________ 
PRE:  Le pide al usuario el especie hasta que cumpla las condiciones 
POST: Devuelve char del especie. 
_______________________________________________________________________________*/ 
char pedir_especie(){ 
    string especie; 
    cout << "Decime el especie.\n"; 
    cout << "Puede ser de las siguientes, podes poner su caracter caracteístico o completo, sin restricción:" << endl;
    imprimir_tabla_especies(); 

    bool todo_bien = false;  
    while( !todo_bien ){ 
        cout << " >> "; 
        getline( cin, especie); 
        especie = string_a_mayuscula( elimina_espacios( especie ) ); 
        todo_bien = es_especie_posible( especie ); 
    } 
    return especie[0];
}


void imprimir_personalidades(){
    cout << "Seleccioná un número de la lista de personalidades:" << endl;
    for ( int i = 0 ; i < CANTIDAD_PERSONALIDADES ; i++){
        cout << "      " << i+1 << "-  " << PERSONALIDADES[i] << endl;
    }


}

/*________pedir_especie()______________________________________________________ 
PRE:  Le pide al usuario la personalidad hasta que sea uno posible
POST: Devuelve el string de la personalidad.
_______________________________________________________________________________*/ 
string pedir_personalidad(){
    cout << "Decime cómo se comporta.\n"; 
    imprimir_personalidades();
    string opcion = "";
    int opcion_int = CANTIDAD_PERSONALIDADES+1;
    while( (opcion_int > CANTIDAD_PERSONALIDADES) | ( opcion == "" ) ){ 
        cout << " >> "; 
        getline( cin, opcion); 
        opcion_int = string_a_entero( opcion ); 
    } 
    opcion = PERSONALIDADES[ opcion_int -1 ]; 
    return opcion;
}
 
 
void rescatar_animal( Guarderia* mi_guarderia ){ 
    cout << "Rescataste un animal!" << endl; 
 
    string nombre = pedir_nombre(); 
 
    int numero_de_animal = buscar_nombre( mi_guarderia, nombre );
    
    if (numero_de_animal != mi_guarderia->obtener_cantidad()){  
        cout << "Este nombre ya lo tiene otro animal:" << endl; 
        mi_guarderia->mostrar(numero_de_animal); 
    } 
    else{ // No esta en mi_guarderia 
        int edad = pedir_edad();
        int tamano = pedir_tamano(); 
        char especie = pedir_especie();
        string personalidad = pedir_personalidad();
 
        string animal_csv = nombre + ',' + to_string(edad) + ',' + TAMANOS_STRING[ tamano ] + ',' + especie + ',' + personalidad;
        guardar_un_animal( mi_guarderia, animal_csv ); 
 
        cout << "\nSe agregó a tu reserva de animales el siguiente animal:" << endl; 
        ( mi_guarderia -> mostrar(numero_de_animal) ); 
    } 
    cout << "\nQué mas te gustaria hacer?\n"; 
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
