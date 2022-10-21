#include <iostream>  
#include <string> 
#include <fstream> 
#include "funciones_main.h" 
#include "funciones_auxiliares.h" 
using namespace std;  
 
 
 
/*************************************** FUNCIONES DE LA OPCION 1 ***************************************/ 
 
void listar_animales( Guarderia* mi_guarderia ){ 
    Animal** lista_animales = mi_guarderia -> lista_de_animales; 
    int cantidad = mi_guarderia -> cantidad_de_animales; 
     
    if (cantidad > 0){ 
        cout << "Salvaste los siguientes animales:\n"; 
         
        for( int i= 0; i < cantidad ; i++){ 
            lista_animales[i] -> mostrar();  
        } 
    } 
    else{ 
        cout << "No tienes animales guardados, podés empezar a agregar ya mismo." << endl; 
        preguntar_agregar_animal( mi_guarderia ); 
    } 
    cout << "\nQué te gustaria hacer?\n"; 
} 
 
 
 
/*************************************** FUNCIONES DE LA OPCION 2 ***************************************/ 
 
//  nombre, edad, tamano, especie, personalidad, hambre e higiene.
 
string pedir_nombre(){ 
    cout << "Cómo se llama?\n"; 
    string nombre; 
    while ( nombre.length() == 0 ){ 
        cout << " >> "; 
        getline( cin, nombre, '\n' ); 
    } 
    nombre = string_a_mayuscula(nombre); 
    return nombre; 
} 
 
 
/*________pedir_edad()______________________________________________________ 
PRE:  Le pide al usuario la edad hasta que cumpla que va de 0 a EDAD_MAX 
POST: Devuelve int con el valor. 
_______________________________________________________________________________*/ 
int pedir_edad(){ 
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
 

string numero_a_tamano( int numero ){
    cout << "CREAR ESTA FUNCION, tiene que devolver el tamaño que le corresponde segun el numero" << endl;
    return "tu tia";
}
 
/*________pedir_tamano()______________________________________________________ 
PRE:  Le pide al usuario el yamano hasta que sea un numero.
    Si ingresa un número negativo ignora el signo.
POST: Devuelve string con la calsificación correspondiente con el valor. 
_______________________________________________________________________________*/ 
string pedir_tamano(){ 
    string tamano_string;  
    getline( cin, tamano_string, '\n'); 
    int tamano = string_a_entero( tamano_string ); 
    while( tamano_string == "" ){ 
        cout << "Tiene que ser un número, volvé a ingresar el tamaño:\n >> "; 
        getline( cin, tamano_string, '\n'); 
        tamano = string_a_entero( tamano_string ); 
    }
    tamano_string = numero_a_tamano(tamano);
    return tamano_string; 
} 


void imprimir_tabla_especies(){
    cout << "PONER TABLA DE ESPECIES, CON SU CARACTER CARACTERISTICO" << endl;
}


/*________es_espeice_posible()__________________________________________________ 
    PRE: Recibe la especie ingresada todo en mayusculas, lo busca entre los pos- 
    ibles. 
    POST: Devuelve true o false si está o no respectivamente 
_______________________________________________________________________________*/ 
bool es_especie_posible ( string especie ) { 
    bool todo_bien = false; 
    long unsigned int posicion = buscar_en_array_de_string( ESPECIE_STRING, especie, CANTIDAD_ESPECIES ); 
        if (posicion != CANTIDAD_ESPECIES){ 
            todo_bien = true; 
        } 
        else if ( especie.length() == 1 ){ 
            posicion = ESPECIE_CHAR.find( especie[0] ); 
            if (posicion < CANTIDAD_ESPECIES && posicion >= 0){ 
                todo_bien = true; 
            } 
        } 
        else{ 
            cout << "No se recastan animales de esa especie, debe ser según la siguiente tabla:\n"; 
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
    cout << "Seleccioná un número de la lista:" << endl;
    cout << "CREAR ESTA TABLA ENUMERANDO LAS PERSONALIDADES, EL USUARIO ELIGIRÁ POR NUMERO" << endl;
}

/*________pedir_especie()______________________________________________________ 
PRE:  Le pide al usuario la personalidad hasta que sea uno posible
POST: Devuelve el string de la personalidad.
_______________________________________________________________________________*/ 
string pedir_personalidad(){
    cout << "Decime cómo se comporta.\n"; 
    imprimir_personalidades();
    string opcion;
    int opcion_int = -1;
    while( (opcion_int <= CANTIDAD_PERSONALIDADES) & ( opcion_int >0 )){ 
        cout << " >> "; 
        getline( cin, opcion); 
        opcion_int = string_a_entero( opcion ); 
    } 
    string personalidad = PERSONALIDADES[ opcion_int ]; 
    return personalidad;
}
 
 
void rescatar_animal( Guarderia* mi_guarderia ){ 
    cout << "Rescataron un animal!\n"; 
 
    string nombre = pedir_nombre(); 
 
    int numero_de_animal = buscar_nombre( mi_guarderia, nombre ); 
    if (numero_de_animal != mi_guarderia -> cantidad_de_animales){  
        cout << "Este nombre ya lo tiene otro animal:\n"; 
        mi_guarderia -> lista_de_animales[numero_de_animal] -> mostrar(); 
    } 
    else{ // No esta en mi_guarderia 
        int edad = pedir_edad();
        string tamano = pedir_tamano(); 
        char especie = pedir_especie();
        string personalidad = pedir_personalidad();
 
        string animal_csv = nombre + ',' + to_string(edad) + ',' + tamano + ',' + especie + ',' + personalidad;
        guardar_un_animal( mi_guarderia, animal_csv ); 
 
        cout << "\nSe agregó a tu reserva de animales el siguiente animal:" << endl; 
        mi_guarderia -> lista_de_animales[numero_de_animal] -> mostrar(); 
        mi_guarderia -> hubo_cambios = true; 
    } 
    cout << "\nQué mas te gustaria hacer?\n"; 
} 
 
 
 
/*************************************** FUNCIONES DE LA OPCION 3 ***************************************/ 

void buscar_animal( Guarderia* mi_guarderia ){}
 
/*************************************** FUNCIONES DE LA OPCION 4 ***************************************/ 
 
void cuidar_animales( Guarderia* mi_guarderia ){}
 
 
/*************************************** FUNCIONES DE LA OPCION 5 ***************************************/ 
 
void adoptar_animal( Guarderia* mi_guarderia ){}

 
/*************************************** FUNCIONES DE LA OPCION 6 ***************************************/ 
 
 
void guardar_salir( Guarderia* mi_guarderia ){ 
    // cout << "Guardando...\n"; 
    // if ( mi_guarderia -> hubo_cambios == true ){ 
    //     escribir_archivo( mi_guarderia ); 
    // } 
 
    // cout << "Listo, tu registro de animales esta terminado.\nHasta la proxima!\n"; 
 
    // for( int numero_animal = 0; numero_animal < mi_guarderia -> cantidad_de_animales; numero_animal++){ 
    //     delete mi_guarderia -> lista_de_animales[ numero_animal ]; 
    //     mi_guarderia -> lista_de_animales[ numero_animal ] = nullptr; 
    // } 
 
    // delete [] (mi_guarderia -> lista_de_animales); 
    // mi_guarderia -> lista_de_animales = nullptr; 
} 
