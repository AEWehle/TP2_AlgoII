# TP2_AlgoII

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

## COSAS A MODIFICAR/CORREGIR:

1. En archivo funciones_main.h --> funcion buscar_nombre --> en post cond dice "POST: Devuelve el numero de animal correspondiente en la lista de Animales de la Base de Datos, si no lo encuentra devuelve la Cantidad de Animales en la base de datos.", pero en realidad devuelve -1 si no lo encuentra 

Además, en buscar_nombre: cambiar titulo_buscado por animal_buscado

2. En archivo Guaderia.h --> quizas mejor reemplazar -1 por un const int NO_SE_ENCUENTRA o NO_EXISTE o similar, utilizado por el metodo obtener_posicion


## COSAS HECHAS:

* LUCIANA: en branch funcion_buscar_animal resolví puntos 1 y 2, pero espero a ver qué opina el resto
