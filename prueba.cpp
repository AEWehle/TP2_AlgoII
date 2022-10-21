// #include <string>
// #include <iostream>
// using namespace std; 


// // g++ prueba.cpp -o TP2 -Wall -Werror -Wconversion

// string TAMANOS_STRING[5]= { "diminuto", "pequeño", "mediano", "grande", "gigante" };

// int string_a_entero( string texto ){
//     long unsigned int largo= texto.length();
//     int entero = 0;

//     if (largo == 0) entero = 0;
//     else{
//         for(long unsigned int i = 0; i < largo; i++){
//             if (texto[i] >= '0' && texto[i] <= '9') { 
//                 entero =  10 * entero + ((int) texto[i] - 48);
//             }
//         }
//     }
//     return entero;
// }


// string numero_a_tamano( int numero ){
//     //	[ D <2, P<10, M >= 10, Gr>= 20, Gi >= 50 ]
//     // es 0 -> D, 1 -> P , 2 -> M , 3 -> Gr , 4 -> Gi
//     int i = (int)( numero >= 50) + (int)( numero >= 20) + (int)( numero >= 10) + (int)( numero >= 2);
//     return TAMANOS_STRING[i];
// }

// int main(){
//     string tamano_string = "0";  
//     while (tamano_string != "fin"){
//         getline( cin, tamano_string, '\n'); 
//         cout << numero_a_tamano(  string_a_entero( tamano_string ) ) << endl;
//     }
//     return 0;
// }