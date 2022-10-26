# TP2_AlgoII

## COSAS A MODIFICAR/CORREGIR:

1. En archivo opciones.h --> definido como OPCIONES_MENU pero despues dice opciones.h, definir

2. En archivo Animal.h --> la última línea dice SISTEMA_H (no afecta pero si lo dejamos no estaría bien, habría que cambiarlo o borrarlo)

3. En archivo funciones_main.h --> funcion buscar_nombre --> en post cond dice "POST: Devuelve el numero de animal correspondiente en la lista de Animales de la Base de Datos, si no lo encuentra devuelve la Cantidad de Animales en la base de datos.", pero en realidad devuelve -1 si no lo encuentra 

Además, en buscar_nombre: cambiar titulo_buscado por animal_buscado

4. En archivo Guaderia.h --> quizas mejor reemplazar -1 por un const int NO_SE_ENCUENTRA o NO_EXISTE o similar, utilizado por el metodo obtener_posicion


## COSAS HECHAS:

* LUCIANA: en branch funcion_buscar_animal resolví puntos 3 y 4, pero espero a ver qué opina el resto
