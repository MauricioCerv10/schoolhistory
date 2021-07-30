/* PROYECTO: SOLUCIONADOR DE EXPRESIONES MATEMÁTICAS PASO A PASO
 - POR: Fuentes García Alan Kevin 
 - GRUPO: 1CM8

  DESCRIPCIÓN:
	EL PROYECTO PRETENDE SOLUCIONAR EXPRESIONES MATEMÁTICAS SIMPLES CON OPERACIONES BÁSICAS
	Y DAR A CONOCER LOS PASOS DE LA SOLUCIÓN DE LAS MISMAS. ESTO SE REALIZA MEDIANTE UN ARBOL
	DE EXPRESIÓN EL CUAL SE FORMA AL INGRESAR EL USUARIO UNA CADENA DE CARACTERES.
	YA RESUELTA, SE LE DA LA OPCIÓN AL USUARIO DE GUARDAR LA SOLUCION MOSTRADA EN PANTALLA
	O NO. ESTO SE HARÁ MEDIANTE UNA TABLA HASH FINITA.
*/

#include <stdio.h>
#include <stdlib.h>
#include "expresion.h"
#include "solucion.h"
#include "hash.h"
#include "archivos.h"

int
main (void)
{
  int opcion = 0, n_hash = 0;
  char entrada[1000], expresion[1000], *nombre = NULL, opc = '0';
  struct narbol *arbol = NULL;
  struct nhash **tabla =
    (struct nhash **) malloc (sizeof (struct nhash *) * 1000);
  iniciar (tabla);
  cargar (tabla);
  printf ("\nPulse una tecla para continuar");
  fgets (entrada, 1000, stdin);
  while (1)
    {
      system ("clear");
      printf ("\nSOLUCIONADOR DE EXPRESIONES MATEMATICAS PASO A PASO.");
      printf ("\nOPCIONES: ");
      printf ("\n1. Leer las instrucciones.");
      printf ("\n2. Usar el solucionador.");
      printf ("\n3. Ver historial de soluciones.");
      printf ("\n4. Borrar historial de soluciones.");
      printf ("\n*Otro numero para salir");
      printf ("\n->");
      fgets (entrada, 1000, stdin);
      sscanf (entrada, "%d", &opcion);
      switch (opcion)
	{
	case 1:
	  printf ("\n*Solamente hay algunas consideraciones:");
	  printf ("\na) No ingrese espacios en su expresion.");
	  printf ("\nb) Cree juegos completos de parentesis ().");
	  printf ("\nc) Use solo operadores basicos +-*/ y no dos juntos.");
	  printf ("\nPulse una tecla para continuar");
	  fgets (entrada, 1000, stdin);
	  break;
	case 2:
	  printf ("\n*Ingrese una expresion matematica:");
	  printf ("\n-> ");
	  fgets (entrada, 1000, stdin);
	  sscanf (entrada, "%s", expresion);
	  n_hash = hash (expresion);
	  nombre = IntToName (n_hash);
	  if (buscar (expresion, tabla) == -1)
	    {
	      insertar (expresion, tabla);
	      FormarArbol (expresion, strlen (expresion), &arbol);
	      resolver (&arbol, nombre, 1);
	    }
	  leer (nombre);
	  printf ("\nAprendiste los pasos? [S/N]->");
	  fgets (entrada, 1000, stdin);
	  sscanf (entrada, "%c", &opc);
	  if (opc == 'S' || opc == 's')
	    {
	      eliminar (expresion, tabla);
	      borrar (nombre);
	    }
	  else
	    {
	      printf ("\nTranquilo, podras repasarlos cuando quieras.");
	    }
	  GuardarExps (tabla);
	  printf ("\nPulse una tecla para continuar.");
	  fgets (entrada, 1000, stdin);
	  break;
	case 3:
	  printf ("\n");
	  leer ("tabla.txt");
	  printf ("\nPulse una tecla para continuar.");
	  fgets (entrada, 1000, stdin);
	  break;
	case 4:
	  MasterClear (tabla);
	  break;
	default:
	  return 0;
	}
    }
}
