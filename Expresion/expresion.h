/*PROYECTO: ÁRBOL DE EXPRESIÓN - POR: Fuentes García Alan Kevin - GRUPO: 1CM8*/
#ifndef _EXPRESION_H_
#define _EXPRESION_H_
#include <string.h>
#include <stdlib.h>

struct narbol
{
  int tipo;			/* 1 es entero, 0 es operador */
  float n;
  char c;
  struct narbol *izq;
  struct narbol *der;
};

struct narbol *CrearNodo (char *c, float *n);	/*CREA UN NUEVO NODO */

void CopiarCadena (char *cadena, char **copia, int l);	/*CREA UNA RÉPLICA DE UNA CADENA */

float TenToThe (int n);		/*ELEVA 10 A LA N-ÉSIMA POTENCIA */

int EsOperador (char x);	/*COMPRUEBA SI UN CARACTER ES UN OPERADOR */

int parentesis (char *cadena, int l);	/*CONFIRMA EXISTENCIA DE PARÉNTESIS EN CADENA */

int operadores (char *cadena, int l);	/*CONFIRMA EXISTENCIA DE OPERADORES EN CADENA */

float CharToFloat (char *cadena, int l);	/*CONVIERTE UNA CADENA A UN NÚMERO ENTERO */

void simplificar (char **cadena, int *l);	/*DETECTA PARÉNTESIS INNECESARIOS DE LOS EXTREMOS DE LA EXPRESIÓN */

int SumaParentesis (char *cadena, int l);	/*DETECTA SI ESTÁN CERRADOS LOS PARENTESIS DE UNA CADENA */

void oplibres (char *cadena, int l, char **ops, int **poss, int *t);	/*OBTIENE OPERADORES LIBRES */

int MenorLibre (char *cadena, int l);	/*OBTIENE AL MENOR OPERADOR LIBRE DE UNA CADENA */

void FormarArbol (char *cadena, int l, struct narbol **arbol);	/*FORMA EL ARBOL DE EXPRESIÓN A PARTIR DE UNA CADENA */
#endif
