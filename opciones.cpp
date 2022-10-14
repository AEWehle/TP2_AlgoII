#include <iostream> 
#include <string>
#include <fstream>
#include "Funciones_EDL.h"
#include "FuncionesAuxiliares.h"
using namespace std; 



/*************************************** FUNCIONES DE LA OPCION 1 ***************************************/

void listar_libros( Biblioteca* mi_biblioteca ){
    Libro** lista_libros = mi_biblioteca -> lista_de_libros;
    int cantidad = mi_biblioteca -> cantidad_de_libros;
    
    if (cantidad > 0){
        cout << "Leiste los siguientes libros:\n";
        
        for( int i= 0; i<cantidad; i++){
            string genero = GENEROS_STRING [GENEROS_CHAR.find( lista_libros[i] -> genero ) ];
            cout << "   -  " << lista_libros[i] -> titulo << COMA_ESPACIO << genero << COMA_ESPACIO << lista_libros[i] -> puntaje << endl;
        }
    }
    else{
        cout << "No tienes libros guardados, podés empezar a agregar ya mismo." << endl;
        preguntar_agregar_libro( mi_biblioteca );
    }
    cout << "\nQué te gustaria hacer?\n";
}



/*************************************** FUNCIONES DE LA OPCION 2 ***************************************/



string pedir_titulo(){
    string titulo;
    while ( titulo.length() == 0 ){
        cout << " >> ";
        getline( cin, titulo, '\n' );
    }
    titulo = string_a_mayuscula(titulo);
    return titulo;
}



/*________imprimir_tabla_generos()_____________________________________________
 PRE:  
 POST: Imprime en terminal la tabla de generos y su respectivo caracter repres-
 entativo. 
_______________________________________________________________________________*/
void imprimir_tabla_generos(){
    cout << "           Género-----------Representación\n";
    cout << "           Aventura-----------A\n";
    cout << "           Ciencia Ficción----C\n";
    cout << "           Didáctica----------D\n";
    cout << "           Policíaca----------P\n";
    cout << "           Romance------------R\n";
    cout << "           Terror-------------T\n";
}



/*________es_genero_posible()__________________________________________________
    PRE: Recibe el genero ingresado todo en mayusculas, lo busca entre los pos-
    ibles.
    POST: Devuelve true o false si está o no respectivamente
_______________________________________________________________________________*/
bool es_genero_posible ( string genero ) {
    bool todo_bien = false;
    long unsigned int posicion = buscar_en_array_de_string( GENEROS_STRING, genero, CANTIDAD_GENEROS );
        if (posicion != CANTIDAD_GENEROS){
            todo_bien = true;
        }
        else if ( genero.length() == 1 ){
            posicion = GENEROS_CHAR.find( genero[0] );
            if (posicion < CANTIDAD_GENEROS && posicion >= 0){
                todo_bien = true;
            }
        }
        else{
            cout << "No tengo ese genero, debe ser según la siguiente tabla:\n";
            imprimir_tabla_generos();
        }
    return todo_bien;
}



/*________pedir_genero()______________________________________________________
PRE:  Le pide al usuario el genero hasta que cumpla las condiciones
POST: Devuelve char del genero.
_______________________________________________________________________________*/
char pedir_genero(){
    string genero;
    cout << "Decime el género.\n";

    bool todo_bien = false; 
    while( !todo_bien ){
        cout << " >> ";
        getline( cin, genero);
        genero = string_a_mayuscula( elimina_espacios( genero ) );
        todo_bien = es_genero_posible( genero );
    }
    return genero[0];
}



/*________pedir_puntaje()______________________________________________________
PRE:  Le pide al usuario el puntaje hasta que cumpla que va de 0 a PUNTAJE_MAX
POST: Devuelve int con el valor.
_______________________________________________________________________________*/
int pedir_puntaje(){
    string puntaje_string; 
    getline( cin, puntaje_string, '\n');
    int puntaje = string_a_entero( puntaje_string );
    while( ( puntaje > PUNTAJE_MAX) || ( puntaje < 0) || ( puntaje_string == "" ) ){
        cout << "Tiene que ser entre 0 y "<< PUNTAJE_MAX << ", volvé a ingresar el puntaje:\n >> ";
        getline( cin, puntaje_string, '\n');
        puntaje = string_a_entero( puntaje_string );
    }
    return puntaje;
}



void agregar_libro( Biblioteca* mi_biblioteca ){
    cout << "Leiste un libro nuevo!\n";
    cout << "Cuál es el título?\n";

    string titulo = pedir_titulo();

    int numero_de_libro = buscar_titulo( mi_biblioteca, titulo );
    if (numero_de_libro != mi_biblioteca -> cantidad_de_libros){ 
        cout << "Este libro ya está en tu lista, tiene estas características:\n";
        mostrar_un_libro( mi_biblioteca, numero_de_libro );
    }
    else{ // No esta en la mi_biblioteca
        char genero = pedir_genero();

        cout << "Por úlitmo el puntaje, va entre 0 y "<< PUNTAJE_MAX << " incluídos.\n >> ";
        int puntaje = pedir_puntaje();    

        string libro_csv = titulo + COMA_ESPACIO +   genero  + COMA_ESPACIO + to_string( puntaje );
        guardar_un_libro( mi_biblioteca, libro_csv );

        cout << "\nSe agregó a tu lista de libros el siguiente libro:" << endl;
        mostrar_un_libro( mi_biblioteca, numero_de_libro );
        mi_biblioteca -> hubo_cambios = true;
    }
    cout << "\nQué mas te gustaria hacer?\n";
}



/*************************************** FUNCIONES DE LA OPCION 3 ***************************************/



/*________modificar_puntaje()__________________________________________________
PRE:  Dada la biblioteca, el numerod e libro a modificar y el puntaje nuevo ya
 verificados.
POST: Modifica en la biblioteca el puntaje en ese libro y lo muestra al usuario
_______________________________________________________________________________*/
void modificar_puntaje( Biblioteca* mi_biblioteca, int numero_de_libro, int puntaje ) {
    mi_biblioteca -> lista_de_libros[ numero_de_libro ] -> puntaje = puntaje;
    mi_biblioteca -> hubo_cambios = true;

    cout << "\nSe modificó tu libro en tu lista y ahora es:\n" ;
    mostrar_un_libro( mi_biblioteca, numero_de_libro );
}



void editar_puntaje( Biblioteca* mi_biblioteca ){
    cout << "Dale, decime a qué libro queres editarle su puntaje?\nSolo necesito el titulo.\n >> ";

    int numero_de_libro = buscar_titulo( mi_biblioteca, pedir_titulo() );
    if ( numero_de_libro == mi_biblioteca -> cantidad_de_libros ){ 
        cout << "Este libro no esta en tu lista. ";
        preguntar_agregar_libro( mi_biblioteca );
    }
    else{
        cout << "Tiene puntaje " << mi_biblioteca -> lista_de_libros[ numero_de_libro ] -> puntaje << endl;
        cout << "Qué puntaje querés ponerle del 0 al "<< PUNTAJE_MAX << "?\n >> ";
        int puntaje = pedir_puntaje();
        modificar_puntaje( mi_biblioteca, numero_de_libro, puntaje);
        
        cout << endl << "Qué mas te gustaría hacer?\n";
    }
}



/*************************************** FUNCIONES DE LA OPCION 4 ***************************************/



/*________mostrar_libros_favoritos()___________________________________________
PRE:  Recibe la biblioteca, los numero de libro correspondientes a mayor punta-
je, y la cantidad de libros en esa lista
POST: Los muestra en terminal
_______________________________________________________________________________*/
void mostrar_libros_favoritos( Biblioteca* mi_biblioteca, int* libro_puntaje_max, int cant_libros_fav ){
    if ( cant_libros_fav != 1){ cout << "Tus libros favoritos son:\n"; }
    else{ cout << "Tu libro favorito es:\n "; }
    
    for( int i = 0; i < cant_libros_fav; i++){
        cout << mi_biblioteca -> lista_de_libros[ libro_puntaje_max[i] ] -> titulo;
        if ( cant_libros_fav!=1 && i == (cant_libros_fav -2) )  { cout << " y "; }
        else if (cant_libros_fav !=1 && i != ( cant_libros_fav-1 ) )  { cout << COMA_ESPACIO; }
    }
    cout << ". Con un puntaje de: " << mi_biblioteca -> lista_de_libros[ libro_puntaje_max[0] ] -> puntaje << endl;
}



void libro_favorito( Biblioteca* mi_biblioteca ){
    int puntaje_max = -1;
    int libro_puntaje_max[ mi_biblioteca -> cantidad_de_libros ]; // En el peor de los casos todos tienen mismo puntaje
    int cant_libros_fav = 0;
    
    for ( int numero_de_libro = 0; numero_de_libro < mi_biblioteca -> cantidad_de_libros ; numero_de_libro++ ){
        if ( puntaje_max <= ( mi_biblioteca -> lista_de_libros[ numero_de_libro ] -> puntaje ) ){
            if ( puntaje_max == ( mi_biblioteca -> lista_de_libros[ numero_de_libro ] -> puntaje ) ){
                libro_puntaje_max[ cant_libros_fav ] =  numero_de_libro;
                cant_libros_fav++;
            }
            else {
                puntaje_max = ( mi_biblioteca -> lista_de_libros[ numero_de_libro ] -> puntaje );
                libro_puntaje_max[0] = numero_de_libro;
                cant_libros_fav = 1;
            }
        }
    }
    mostrar_libros_favoritos( mi_biblioteca, libro_puntaje_max, cant_libros_fav );
    cout << "\nQué más te gustaría hacer?\n";
}



/*************************************** FUNCIONES DE LA OPCION 5 ***************************************/



/*________esquivar_menores_guardados()_________________________________________
PRE:  Recibe la biblioteca, 
            el numero de libro a comparar en biblioteca, 
            lista de libros ya guardados como menores en puntaje y alfabeticam-
            ente, 
            y la cantidad en esa lista
POST: va sumando el valor de numero de libro si encuentra que es un libro ya 
  guardado
_______________________________________________________________________________*/
void esquivar_menores_guardados( Biblioteca* mi_biblioteca, int& numero_libro, string * titulos_libros_min, int cant_guardados ){
    // Ignoro los libros que ya tengo guardados, si es que ya tengo (i!=0)
    string titulo_actual = mi_biblioteca -> lista_de_libros[numero_libro] -> titulo;
    while ( ( numero_libro < mi_biblioteca -> cantidad_de_libros ) && ( buscar_en_array_de_string( titulos_libros_min, titulo_actual, ( cant_guardados ) ) != cant_guardados ) ){
        numero_libro++;
        if ( numero_libro < mi_biblioteca -> cantidad_de_libros ){
            titulo_actual = mi_biblioteca -> lista_de_libros[numero_libro] -> titulo;}
    }
}


/*________ Buscar_titulos_menor_iguales()______________________________________
PRE:  Recibe la biblioteca, 
        Los puntajes minimos, arreglo de enteros
        Lista de libros ya guardados como menores en puntaje y alfabeticamente
        y la cantidad en esa lista
POST: en una recorrida de la lista de libros guarda el libro con menor puntaje
    y menor alfabeticamnete entre los empates, esquiva los libros ya guardados en
    el arreglo titulos_libros_min
_______________________________________________________________________________*/
void Buscar_titulos_menor_iguales( Biblioteca* mi_biblioteca, int* puntajes_min, string* titulos_libros_min, int cant_guardados ){
    string titulo_actual;
    int cantidad_libros = mi_biblioteca -> cantidad_de_libros;
    for( int numero_libro = 0; numero_libro < cantidad_libros ; numero_libro++ ){ // Busco los que tienen el mismo y menor puntaje
        titulo_actual = mi_biblioteca -> lista_de_libros[numero_libro] -> titulo;
        if (  cant_guardados  != 0 ){ esquivar_menores_guardados( mi_biblioteca, numero_libro, titulos_libros_min, cant_guardados ); }

        if ( ( numero_libro < cantidad_libros ) && ( puntajes_min[ cant_guardados ] == mi_biblioteca -> lista_de_libros[numero_libro] -> puntaje ) ){
            titulos_libros_min[ cant_guardados ] = menor_alfabetico( titulo_actual, titulos_libros_min[ cant_guardados ] );
        }

        if ( ( numero_libro < cantidad_libros ) && ( puntajes_min[ cant_guardados ] > mi_biblioteca -> lista_de_libros[numero_libro] -> puntaje ) ){
            titulos_libros_min[ cant_guardados ] = titulo_actual;
            puntajes_min[ cant_guardados ] = mi_biblioteca -> lista_de_libros[numero_libro] -> puntaje;
        }
    }
}



/*Muetsra los tres lirbos con menor puntaje*/
void mostrar_3_peores( string* titulos_libros_min, int* puntajes_min, int cantidad_a_comparar ){
    cout << "Tus "<< cantidad_a_comparar <<" peores libros son:" << endl;
    for( int i = 0; i < cantidad_a_comparar; i++){
        cout << "   - " << titulos_libros_min[i] << endl;
        cout << "       Con un puntaje de: " << puntajes_min[i] << "." << endl;
    }
}



void tres_menor_puntaje ( Biblioteca* mi_biblioteca ){
    int cantidad_a_comparar = 3;
    if ( mi_biblioteca -> cantidad_de_libros <= (cantidad_a_comparar-1) ){
        cout << "Tenes solo " << mi_biblioteca -> cantidad_de_libros << " libros leídos, necesito 3, pero te los muestro:\n";
        //listar_libros( mi_biblioteca );
        cantidad_a_comparar = mi_biblioteca -> cantidad_de_libros;
    }
        //int cantidad_a_buscar
    int puntajes_min[ cantidad_a_comparar ];
    llenar_con_int ( puntajes_min, PUNTAJE_MAX+1 , cantidad_a_comparar );
    string titulos_libros_min[ cantidad_a_comparar ];
                                                    //cantidad a buscar
    for( int cant_guardados = 0;  cant_guardados < cantidad_a_comparar;  cant_guardados++){
        Buscar_titulos_menor_iguales( mi_biblioteca, puntajes_min, titulos_libros_min, cant_guardados );
    }                                               //cantidad a buscar
    mostrar_3_peores( titulos_libros_min, puntajes_min, cantidad_a_comparar );
    cout << "\nQué más querés hacer?\n";
}



/*************************************** FUNCIONES DE LA OPCION 6 ***************************************/



/*Muestra al usuario los generos que aparecen mas veces*/
void mostrar_generos_mas_leidos( string* mas_leido, int cant_mas_leido, int max_veces ){
    cout << "Tu género mas leído es:  ";
    for( int i = 0;  i <= cant_mas_leido ; i++){
        cout << mas_leido[i];
        if ( cant_mas_leido !=0 && i == (cant_mas_leido -1) )  { cout << " y "; }
        else if ( cant_mas_leido !=0 && i != cant_mas_leido  )  { cout << COMA_ESPACIO; }
    }

    if ( cant_mas_leido !=0)  { cout << ". Tenes " << max_veces << " libros de esos géneros." << endl; }
    else{ cout << ". Tenes " << max_veces << " libros de ese género." << endl; }
}



void genero_mas_leido( Biblioteca* mi_biblioteca ){
    cout << "Buscando..." << endl;
    int veces_genero[ CANTIDAD_GENEROS ] = {};
    for( int i = 0; i < mi_biblioteca -> cantidad_de_libros ; i++ ){
        veces_genero[ GENEROS_CHAR.find( mi_biblioteca -> lista_de_libros[i] -> genero ) ] ++;
    }

    string mas_leido[ CANTIDAD_GENEROS ];
    int max_veces = -1;
    int cant_mas_leidos = 0;
    for( int i = 0; i < CANTIDAD_GENEROS ; i++){
        if( max_veces == veces_genero[i] ){
            mas_leido[ ++cant_mas_leidos ] = GENEROS_STRING[i];
        }
        if( max_veces < veces_genero[i] ){
            cant_mas_leidos = 0;
            mas_leido[ cant_mas_leidos ] = GENEROS_STRING[i];
            max_veces = veces_genero[i];
        }
    }
    mostrar_generos_mas_leidos( mas_leido , cant_mas_leidos, max_veces);
    cout << "\nQué más te gustaría hacer?" << endl;
}



/*************************************** FUNCIONES DE LA OPCION 7 ***************************************/



/*Muestra al usuario los generos que tienen mejor e igual promedio*/
void mostrar_genero_favorito( string* generos_mejor_promedio, int cant_maximos, float promedio_max ){
    cout << "Tu género con mejores puntajes es:  ";
    for( int i = 0;  i <= cant_maximos ; i++){
        cout << generos_mejor_promedio[i];
        if ( cant_maximos !=0 && i == (cant_maximos -1) ){ cout << " y "; }
        else if ( cant_maximos !=0 && i != cant_maximos  ){ cout << COMA_ESPACIO; }
    }
    cout << ". Con promedio: " << promedio_max << "." << endl;
}


/*________me_quedo_mayor_iguales()_________________________________________
PRE:  Recibe 
            un arreglo de string con los generos con mejor e igual promeido,
            la cantidad de generos en el arreglo, por referencia
            la suma de puntajes de cada genero
            la cantidad de lobros de cada genero
POST: Deja en generos_mejor_promedio los generos con mejor e igual promedio
      Deja en cant_maximos la cantidad de genero en el array anterior
      Devuelve (float) el valor del promedio que tienen los genero en el array
_______________________________________________________________________________*/
float me_quedo_mayor_iguales( string* generos_mejor_promedio, int& cant_maximos, double* suma_puntajes_genero, int* veces_genero ){
    float promedio_max = -1;
    float promedio_genero;
    for( int i = 0; i < CANTIDAD_GENEROS ; i++ ){
        promedio_genero = (float) (suma_puntajes_genero[i] / veces_genero[i]);
        if( promedio_max == promedio_genero ){
            generos_mejor_promedio[ ++cant_maximos ] = GENEROS_STRING[i];
        }
        if( promedio_max < promedio_genero ){
            cant_maximos  = 0;
            generos_mejor_promedio[ cant_maximos ] = GENEROS_STRING[i];
            promedio_max = promedio_genero;
        }
    }
    return promedio_max;
}



void genero_favorito( Biblioteca* mi_biblioteca ){
    cout << "Buscando genero con mejor promedio..." << endl;

    int veces_genero[ CANTIDAD_GENEROS ] = {};
    double suma_puntajes_genero [ CANTIDAD_GENEROS ] = {};
    for( int i = 0; i < mi_biblioteca -> cantidad_de_libros ; i++ ){
        veces_genero[ GENEROS_CHAR.find( mi_biblioteca -> lista_de_libros[i] -> genero ) ] ++;
        suma_puntajes_genero[ GENEROS_CHAR.find( mi_biblioteca -> lista_de_libros[i] -> genero ) ] += mi_biblioteca -> lista_de_libros[i] -> puntaje;
    }

    string generos_mejor_promedio[ CANTIDAD_GENEROS ];
    int cant_maximos = 0;
    float promedio_max = me_quedo_mayor_iguales( generos_mejor_promedio, cant_maximos, suma_puntajes_genero, veces_genero  );
    
    mostrar_genero_favorito( generos_mejor_promedio, cant_maximos, promedio_max );
    cout << "\nQué más te gustaría hacer?" << endl;
}



/*************************************** FUNCIONES DE LA OPCION 8 ***************************************/



void guardar_salir( Biblioteca* mi_biblioteca ){
    cout << "Guardando...\n";
    if ( mi_biblioteca -> hubo_cambios == true ){
        escribir_archivo( mi_biblioteca );
    }

    cout << "Listo, ya podes seguir leyendo mas libros.\nHasta la proxima!\n";

    for( int numero_libro = 0; numero_libro < mi_biblioteca -> cantidad_de_libros; numero_libro++){
        delete mi_biblioteca -> lista_de_libros[ numero_libro ];
        mi_biblioteca -> lista_de_libros[ numero_libro ] = nullptr;
    }

    delete [] (mi_biblioteca -> lista_de_libros);
    mi_biblioteca -> lista_de_libros = nullptr;
}
