/*PROYECTO: ÁRBOL DE EXPRESIÓN - POR: Fuentes García Alan Kevin - GRUPO: 1CM8*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
void leer (char *n_archivo);	/*LEE EL ARCHIVO CUYA CLAVE SE INGRESA, SI ES QUE EXISTE. */
void borrar (char *n_archivo);	/*BORRA UN ARCHIVO POR SU NOMBRE */
void limpiar (char cadena[1000]);	/*LIMPIA UNA CADENA */
void cargar (struct nhash **tabla);	/*CARGA EL CONTENIDO DE tabla.txt EN LA TABLA HASH */
void MasterClear (struct nhash **tabla);	/*BORRA TODA LA TABLA Y EL CONTENIDO DE tabla.txt */
