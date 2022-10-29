# TP2_AlgoII

COMANDO: g++ *.cpp Especies/*.cpp -o TP2 -Wall -Werror -Wconversion

Para ejecutar ./TP2

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./TP2

gdb ./Prueba

git status                                   Para ver lo que esta para subirse

git add .                                    Para agregar a las cosas a subirse

git commit -m "mensaje para nuestro grupo"   Para guardarlo y en un futuro subirlo con git push

git log --oneline                            Para ver el historial de Commits

git push                                     Lo sube a la nube 

ponen su nombre de usuario

ponen la siguiente clave --->  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

git pull                                     Ponerlo para verificar si alguine del grupo pusheó algún cambio
                                                te asegurás tenes la úlrima versión

git checkout nombre_branch                   Primero hacerlo con la main y despues con la brunch en la que estás trabajando

git chechout -b nombre_nueva_brunch          Crear brunch

git push origin nombrE_nueva_brunch          Luego de haber hecho add y commit

## COSAS A MODIFICAR/CORREGIR:

1 * Revisar que no haya funciones que no se usen (por ejemplo que hayan quedado del TP1)

2 * Revisar que todo esté con clases y no estructuras, incluso descripciones de pos y pre condiciones

3 * LISTO - Definir como manejar el main. Incluí una variable "estado_guarderia" que empieza con una constante ESTADO_ABIERTA de forma tal que salga del while cuando esté en ESTADO_CERRADA (se pone estado_guarderia = ESTADO_CERRADA cuando se ejecuta la funcion guardar_salir)...se me ocurrió usar esto mientras tanto, pero se puede cambiar, fue lo que usé en mi TP1.

4 * LISTO - Definir cómo vamos a manejar la creación de la Guarderia a partir del archivo: llamamos a la función leer_archivo y que dentro se llame a la creación de la clase Guarderia? o que el constructor de Guarderia reciba como parametro el archivo y ella llame a leer_archivo? o qué otra forma sino?

5 * Revisar métodos de guarderia, si se necesitan todos o si algunos sobran ya que ahora se usan listas. Por ejemplo: el método privado "swap" lo vamos a usar?

6 * Dejamos el constructor de copia? En caso de que sí, hay que adaptarlo a listas

7 * Falta la función cuidar_animales() (dentro de opciones.cpp)

8 * Falta la función adoptar_animal() (dentro de opciones.cpp)

9 * Definir cómo quedará guardar_salir

10 * Revisar pos y pre condiciones de todo

11 * PROBAR Y VER QUE TODO FUNCIONE Y QUE SE CUMPLA LO QUE PIDE EL ENUNCIADO DEL TP

12 * La función rescatar_animal no hace exactamente lo que dice el TP, si el nombre ya está en la lista hay que preguntar si se quiere ingresar otro nombre o volver al menú

13 * Las funciones internas de un .cpp (que no van en el .h) tienen que ir si o si antes de ser usadas? si es así va a haber que reordenar algunas funciones (al menos en funciones_main.cpp). Si lo saben digan, y sino lo veremos cuando podamos compilar y salte el error.


## COSAS HECHAS:

A.V. - Acomodé el main, creería que ya no va a haber que cambiarlo
A.V. - Hice la función que lee el archivo y va guardando los animales en la lista de guardería
A.V. - Acomodé un poco la funciones de pedir eleccion
A.V. - En algunos archivos puse una división con ///// para separar funciones que o bien no se usan o bien van en otra parte (creo). Así queda más ordenada la modularización
A.V. - Fui dejando algunos comentarios en algunas líneas que no entiendo o no se si son necesarias
A.V. - Fui sacando todos los \n que encontré y cambiandolos por endl, me parece que al usar C++ es lo más correcto. Habría que revisar todo el final.
A.V. - 
A.V. - 
A.V. - 
A.V. - 
A.V. - 
A.V. - 
