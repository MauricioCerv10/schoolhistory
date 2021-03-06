/*PROYECTO: ÁRBOL DE EXPRESIÓN - POR: Fuentes García Alan Kevin - GRUPO: 1CM8*/
#include <stdio.h>
#include "expresion.h"

int mayor (int a, int b);	/*OBTIENE EL MAYOR DE DOS NÚMEROS */

int altura (struct narbol *arbol);	/*CALCULA LA ALTURA DE UN ARBOL */

void operar (struct narbol *nodo);	/*RESUELVE LA OPERACION DE UN NODO EN ÉL MISMO */

struct narbol *BuscarOperable (struct narbol *arbol);	/*BUSCA UN NODO OPERABLE EN LA MENOR ALTURA */

void resolver (struct narbol **arbol, char *n_archivo, int i);	/*RESUELVE EL ARBOL Y PONE LOS PASOS EN UN ARCHIVO */
