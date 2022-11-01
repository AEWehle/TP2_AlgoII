#include <iostream>  
#include <string> 
#include <fstream>
#include <limits>
#include "Archivos_auxiliares/funciones_auxiliares.h" 
#include "Archivos_auxiliares/nodo.h"
#include "funciones_main.h" 
#include "Guarderia.h"
#include "opciones.h"
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

    //cout << endl << "Cómo se llama?" << endl << " >> "; -> Imprimo desde afuera por reutilizacion

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


bool validar_edad(string edad_st, int &edad){
    bool edad_valida = true;

    if(!isdigit(edad_st[0])){
        edad_valida = false;
    }else{
        edad = stoi(edad_st);
        edad_valida = (edad >= 0 && edad <= EDAD_MAX);
    }

    return edad_valida;

}
 
/*________pedir_edad()______________________________________________________ 
PRE:  Le pide al usuario la edad hasta que cumpla que va de 0 a EDAD_MAX 
POST: Devuelve int con el valor. 
_______________________________________________________________________________*/ 
int pedir_edad(){ 
    cout << endl << "Cuántos años tiene?" << endl << " >> ";
    int edad;  
    string edad_st;
    bool edad_valida = true;

    cin >> edad_st; //Si ingresan una letra lo toma como edad 0. Habría que arreglarlo
    edad_valida = validar_edad(edad_st, edad);
    

    while( !edad_valida ){ 
        cout << "Tiene que ser entre 0 y "<< EDAD_MAX << ", volvé a ingresar la edad:" << endl << " >> "; 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> edad_st;
        edad_valida = validar_edad(edad_st, edad);
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
PRE:  Le pide al usuario el tamano hasta que sea un numero.
    Si ingresa un número negativo ignora el signo.
POST: Devuelve la calsificación correspondiente con el valor. 
_______________________________________________________________________________*/ 

string pedir_tamano(){ 
    cout << endl << "Qué tamaño tiene?" << endl 
    << "Elegí de entre los siguientes según el espacio que necesite:" << endl << endl

    << "1 - Diminuto -> menos de 2 m^2" << endl
    << "2 - Pequeño  -> menos de 10 m^2" << endl
    << "3 - Mediano  -> 10 m^2 o más" << endl
    << "4 - Grande   -> 20 m^2 o más" << endl
    << "5 - Gigante  -> 50 m^2 o más" << endl << endl << " >> ";
    
    int tamano;  
    cin >> tamano;

    while( !(tamano >= 1 && tamano <= 5)){ 
        cout << "Ingresá el número correspondiente a una categoría:" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> tamano;
    }
    
    return TAMANOS_STRING[ tamano-1]; 
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

    cout << endl << "De qué especie es?" << endl 
    << "Elegí de entre las siguientes:" << endl << endl

    << "1 - Perro" << endl
    << "2 - Gato" << endl
    << "3 - Caballo" << endl
    << "4 - Roedor" << endl
    << "5 - Conejo" << endl
    << "6 - Erizo" << endl
    << "7 - Lagartija" << endl << endl << " >> ";
    
    int especie;
    cin >> especie;

    while( !(especie >= 1 && especie <= 7)){ 
        cout << "Ingresá el número correspondiente a una especie:" << endl << " >> ";
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

    cout << endl << "Qué personalidad tiene?" << endl 
    << "Elegí de entre las siguientes:" << endl << endl

    << "1 - Dormilón" << endl
    << "2 - Juguetón" << endl
    << "3 - Sociable" << endl
    << "4 - Travieso" << endl << endl << " >> ";
    
    
    int personalidad;  
    cin >> personalidad;

    while( !(personalidad >= 1 && personalidad <= 4)){ 
        cout << "Ingresá el número correspondiente a una personalidad:" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> personalidad;
    }
    
    return personalidad-1;

}
 
 
void rescatar_animal( Guarderia* mi_guarderia ){ 
    cout << endl << "Rescataste un animal?" << endl; 
    
    cout << endl << "Cómo se llama?" << endl << " >> "; //Imprime desde afuera p/reutilizar func
    string nombre = pedir_nombre();
    int opcion;
    

    while (buscar_nombre( mi_guarderia, nombre ) == NO_SE_ENCUENTRA){  
        cout << "Este nombre ya lo tiene otro animal! Podés elegir otro nombre o volver al menú." << endl
        << "Para elegir otro nombre ingresá 1, para volver al menú ingresá 2:" << endl;

 
        cin >> opcion;

        while( opcion != 1 && opcion != 2 ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingresá 1 para elegir otro nombre o 2 para volver al menú:" << endl << " >> ";
            cin >> opcion;
        }

        if (opcion == 2) return;

        nombre = pedir_nombre();
    } 

    int edad = pedir_edad();
    string tamano = pedir_tamano(); 
    char especie = ESPECIE_CHAR[pedir_especie()];
    string personalidad = PERSONALIDADES[pedir_personalidad()];

    Animal* nuevo_animal = crear_nuevo_animal(especie, nombre, edad, tamano, personalidad);

    mi_guarderia -> agregar_animal(nuevo_animal);

    cout << endl << nombre << " fue rescatado!" << endl << endl;
    mi_guarderia -> obtener_animal( mi_guarderia -> obtener_cantidad() ) -> mostrar() ;

} 
 
 
 
/*************************************** FUNCIONES DE LA OPCION 3 ***************************************/ 

void buscar_animal( Guarderia* mi_guarderia ){
    string nombre;


    cout << "Ingrese el nombre del animal que busca:" << endl;
    nombre = pedir_nombre();

    if(buscar_nombre(mi_guarderia,nombre) == mi_guarderia->obtener_cantidad()+1){
        cout << nombre << "no se encuentra en la guardería." << endl;
    }else{
        mi_guarderia -> obtener_animal(buscar_nombre(mi_guarderia,nombre))->mostrar();

    }
}
 
/*************************************** FUNCIONES DE LA OPCION 4 ***************************************/ 

void menu_elegir_individualmente(){
    cout << "¿Qué querés hacer con él?" << endl;
    cout << "Ingresá el número de la opción deseada." << endl;
    cout << "1. Alimentar Animal" << endl;
    cout << "2. Duchar Animal" << endl;
    cout << "3. Pasar a Animal siguiente" << endl;
    cout << "4. Volver a Menu Anterior" << endl;
}




void elegir_animal_a_cuidar(Guarderia* mi_guarderia){
    cout << "Elegiste la opción: Elegir Individualmente." << endl;
    cout << "Vamos a pasar por todos los animales en la Guardería." << endl;
    cout << "Ingresá la opción correspondiente según lo que quieras hacer con cada uno." << endl;

    int i = 1;
    int eleccion;
    
    while ( ( i <= (mi_guarderia->obtener_cantidad()) ) && (eleccion != VOLVER_MENU_OP4) ){
    mi_guarderia->obtener_animal(i)->mostrar();
    menu_elegir_individualmente();
    eleccion = pedir_eleccion(CANTIDAD_OPCIONES_EA);
    cout << eleccion << endl;

    switch (eleccion) {
        case ALIMENTAR:
            mi_guarderia->obtener_animal(i)->alimentar();
            break;
        case DUCHAR:
            mi_guarderia->obtener_animal(i)->duchar();
            break;
        case SIGUIENTE:
            ++i;
            break;
        case VOLVER_MENU_OP4:
            break;
        default:
            cout << "Opción Inválida!!!" << endl;
    }

    }

    if(i == (mi_guarderia->obtener_cantidad()+1)){
        cout << "No hay más animales en la lista, volviendo a menú principal..." << endl;
        }
    
}


void alimentar_a_todos(Guarderia* mi_guarderia){
    cout << "Vamos a alimentar a todos los animales" << endl;
    for(int i = 1; i < (mi_guarderia->obtener_cantidad()+1);i++){
        mi_guarderia->obtener_animal(i)->alimentar();
    }
    cout << "Alimentaste a todos los animales! Ellos te lo agradecen!!" << endl;
}

void duchar_a_todos(Guarderia* mi_guarderia){
    cout << "Vamos a duchar a todos los animales" << endl;
    for(int i = 1; i < (mi_guarderia->obtener_cantidad()+1); i++){
        mi_guarderia->obtener_animal(i)->duchar();
    }
    cout << "Duchaste a todos los animales! Ellos te lo agradecen!!" << endl;
}


void volver_menu_ppal(Guarderia* mi_guarderia){
    return;
}


const Manejo_Guarderia opcion_4[ CANTIDAD_OPCIONES_OP4] = {
    elegir_animal_a_cuidar,
    alimentar_a_todos,
    duchar_a_todos,
    volver_menu_ppal,
}; 

 
void ejecutar_eleccion_op4(Guarderia* mi_guarderia, int eleccion){
    opcion_4[ eleccion - 1 ]( mi_guarderia );
}



void cuidar_animales( Guarderia* mi_guarderia ){
    cout << mi_guarderia->obtener_cantidad() << endl;
    if(mi_guarderia->obtener_cantidad()==0){
        cout << "No tenés ningún animal agregado a la guardería para cuidar" << endl;
    }else{
        int eleccion;

        do{
            imprimir_menu(CANTIDAD_OPCIONES_OP4);
            eleccion = pedir_eleccion(CANTIDAD_OPCIONES_OP4);
            ejecutar_eleccion_op4(mi_guarderia, eleccion);
        }while (eleccion != VOLVER_MENU_PPAL);  
    }  

}
 
/*************************************** FUNCIONES DE LA OPCION 5 ***************************************/ 
 
/* Muestra en terminal los animales que cuplen que son menores al tamaño
             TAMANOS_STRING[ tamano_maximo (int) ] 
y que ademas son adoptables, es decir saltea a los erizos y lagartijas
Guarda en la Lista lista_adoptables los mostrados*/
void mostrar_animales_adoptables_segun_tamano( Guarderia* mi_guarderia, int tamano_maximo, Guarderia& lista_adoptables ){
    cout << "Los animales que son aptos para ese espacio son:" << endl;
    Animal* animal_actual;
    for( int numero_de_animal = 1;  numero_de_animal<= mi_guarderia->obtener_cantidad() ;  numero_de_animal++){

        animal_actual =  mi_guarderia -> obtener_animal( numero_de_animal );
        if ( (animal_actual -> es_adoptable()) && (buscar_en_array_de_string( TAMANOS_STRING, animal_actual -> obtener_tamano(), CANTIDAD_TAMANOS) <= tamano_maximo )){
            animal_actual -> mostrar();
            lista_adoptables.agregar_animal( animal_actual );
        }
    }
}

/*  PEDIR EL ADOPTADO:
    Pide al usuario el nombre del animal que desea aoptar, o si desea cancelar.
    Devuelve la posicion del animal que desea adoptar, o -1 si quiere cancelar*/
int pedir_el_adoptado( Guarderia* mi_guarderia , Guarderia& lista_adoptables ){
    string entrada = "";
    int cant_adoptables = lista_adoptables.obtener_cantidad();
    int elegido = cant_adoptables+1;

    while ( ( elegido == (cant_adoptables +1) ) && (entrada != CANCELAR)){ 
        cout << "En caso de no querer adoptar ingrese CANCELAR, y volvera al menú inicial" << endl;
        entrada = pedir_nombre();
        if( string_a_mayuscula( entrada ) == CANCELAR ){
            cout << "Se ha cancelado la adopción" << endl;
            elegido = -1;
        }
        else{
            elegido = lista_adoptables.obtener_posicion( entrada );
            if ( elegido == (cant_adoptables +1) ){
                cout << "El nombre ingresado no es de un animal disponble para adoptar." << endl;
            }
        }
    }
    return elegido;
}

void adoptar_animal( Guarderia* mi_guarderia ){
    cout << endl << "Para adoptar un animal es necesario saber qué tamaño disponen, según eso se le mostrará una lista de los disponibles" << endl;
    int tamano_maximo =  buscar_en_array_de_string( TAMANOS_STRING, pedir_tamano(), CANTIDAD_TAMANOS );
    
    Guarderia lista_adoptables;
    cout << endl << "Si desea adoptar alguno de estos animales ingrese el nombre como se muestra." << endl;
    mostrar_animales_adoptables_segun_tamano( mi_guarderia, tamano_maximo, lista_adoptables );

    cout << endl << "Si desea adoptar alguno, ingrese el nombre." << endl;

    int elegido = pedir_el_adoptado( mi_guarderia, lista_adoptables );
    if ( elegido != -1 ){
        cout << "Adoptaste a " << endl;
        mi_guarderia -> obtener_animal( elegido + 1 ) -> mostrar();
        mi_guarderia -> eliminar_animal( elegido + 1 );
    }
    cout << endl << "Qué más te gustaría hacer?" << endl;
}


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
 
    for ( int numero_de_animal = 1; numero_de_animal < (mi_guarderia->obtener_cantidad()+1) ; numero_de_animal++ ){ 
        
        string nombre       = mi_guarderia -> obtener_animal(numero_de_animal) -> obtener_nombre();
        int edad            = mi_guarderia -> obtener_animal(numero_de_animal) -> obtener_edad();
        string tamano       = mi_guarderia -> obtener_animal(numero_de_animal) -> obtener_tamano();
        char especie      = ESPECIE_CHAR[mi_guarderia -> obtener_animal(numero_de_animal) -> resolver_especie()-1];
        string personalidad = mi_guarderia -> obtener_animal(numero_de_animal) -> obtener_personalidad();

        archivo_guarderia << nombre << "," << edad << "," << tamano << "," << especie << "," << personalidad << endl;

    } 
 
    archivo_guarderia.close(); 

    cout << "Listo, tu registro de animales esta terminado." << endl << "Hasta la proxima!" << endl; 

} 
