#include <iostream> 
#include <string>
#include <fstream>
#include <algorithm>
using namespace std; 

const int DISTANCIA_aA_ASCII = (int) 'a' - (int) 'A';

// En este .cpp defino funciones que no estan directamente relacionadas con el 
//objetivo del TP2


char char_a_mayuscula(char letra){
    if (letra >= 'a' && letra <= 'z') {
        letra = (char) ((int) letra - DISTANCIA_aA_ASCII);
    }
    return letra;}



string string_a_mayuscula(string texto){
    //for_each( texto.begin() ,texto.end() , char_a_mayuscula);
    long unsigned int largo = (long unsigned int)texto.length();
    for( long unsigned int i =0;  i<largo  ; i++){
        texto[i] = char_a_mayuscula( texto[i] );
    }
    return texto;}



string elimina_espacios(string texto){
    texto.erase( remove_if( texto.begin(), texto.end(), ::isspace ) , texto.end());
    return texto;
}


// PARA ESTO ESTÁ LA FUNCIÓN stoi()
int string_a_entero( string texto ){
    long unsigned int largo= (long unsigned int)texto.length();
    int entero = 0;

    if (largo == 0) entero = 0;
    else{
        for(long unsigned int i = 0; i < largo; i++){
            if (texto[i] >= '0' && texto[i] <= '9') { 
                entero =  10 * entero + ((int) texto[i] - 48);
            }
        }
    }
    return entero;
}



int buscar_en_array_de_string( const string* array, string buscado, int largo ){
    int posicion;
    for ( posicion = 0 ; ( posicion < largo ) && (array[ posicion ] != buscado) ; posicion++ ); 
    // En AND, si la primera es falsa NO verifica la segunda, es decir no la ejecuta
    return posicion;
}



void shiftear_a_derecha( int * array, int largo){
    if (largo != 1){
        int ultimo = array[largo-1];
        for( int i = largo-1; i > 0; i--){
            array[i] = array[i-1];
        }
        array[0] = ultimo;
    }
}



string menor_alfabetico( string texto1, string texto2){
    string texto1_aux = elimina_espacios(texto1);
    string texto2_aux = elimina_espacios(texto2);
    string string_menor;
    
    bool lo_encontre = false;

    long unsigned int largo_1 = (long unsigned int)texto1_aux.length();
    long unsigned int largo_2 = (long unsigned int)texto2_aux.length();
    long unsigned int largo_min = min( largo_1, largo_2);
    
    long unsigned int i = 0;
    for( ; ( i < largo_min ) && !lo_encontre ; i++){
        if      ( (long unsigned int) texto1_aux[i] == (long unsigned int) texto2_aux[i] );
        else if ( (long unsigned int) texto1_aux[i] <  (long unsigned int) texto2_aux[i] ){
            string_menor = texto1;
            lo_encontre = true;
        }
        else {
            string_menor = texto2;
            lo_encontre = true;
        }
    }
    if ( ( i == largo_min ) && !lo_encontre){
        if ( largo_1 <= largo_2){
            //son iguales o el texto 1 es mas corto, por lo que va primero
            string_menor = texto1;
        }
        else {
            string_menor = texto2;
        }
    }
    return string_menor;
}



void llenar_con_int ( int* array_int, int entero, int largo ){
    for( int i = 0; i < largo; i++ ){
        array_int[ i ] = entero;
    }
}



