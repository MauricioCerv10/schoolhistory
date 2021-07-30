/*PROYECTO: ÁRBOL DE EXPRESIÓN - POR: Fuentes García Alan Kevin - GRUPO: 1CM8*/
#ifndef _HASH_H_
#define _HASH_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct nhash
{
  char *exp;
  struct nhash *sig;
};
int transfomar (char c);	/*ASIGNA UN VALOR ÚNICO A CADA CARACTER */
int hash (char *cadena);	/*CREA UNA CLAVE ÚNICA PARA UNA EXPRESIÓN */
char *IntToName (int n_hash);	/*CREA EL NOMBRE DE UN ARCHIVO CON EL NUMERO HASH DE LA EXPRESIÓN */
void iniciar (struct nhash *tabla[1000]);	/*MARCA COMO NULOS TODOS LOS ELEMENTOS DE UNA NUEVA TABLA */
struct nhash *CrearLugar (char *exp);	/*CREA UN NODO PARA LA TABLA */
void insertar (char *exp, struct nhash *tabla[1000]);	/*GUARDA UNA EXPRESIÓN EN LA TABLA */
int buscar (char *exp, struct nhash *tabla[1000]);	/*DEVUELVE LA POSICION EN LA LISTA QUE ESTÉ */
void eliminar (char *exp, struct nhash *tabla[1000]);	/*ELIMINA UNA EXPRESIÓN */
void GuardarExps (struct nhash *tabla[1000]);	/*GUARDA LAS EXPRESIONES EN UN ARCHIVO */
void mostrar (struct nhash *tabla[1000]);	/*MUESTRA LA TABLA HASH COMPLETA */
#endif
