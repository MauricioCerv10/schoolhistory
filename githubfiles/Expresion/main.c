#include <stdio.h>
#include <stdlib.h>
#include "expresion.h"
#include "solucion.h"


int
main (void)
{
  int opcion = 0, n_hash = 0;
  char entrada[1000], expresion[1000], *nombre = NULL, opc = '0';
  struct narbol *arbol = NULL;
  while (1)
    {
      system ("clear");
      printf ("\nSolucionador de expresiones Matematicas");
      printf ("\nOpciones:  ");
      printf ("\n1. Comenzar");
      printf ("\n2. Salir");
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

	  printf ("\n*Ingrese una expresion matematica:");
	  printf ("\n-> ");
	  fgets (entrada, 1000, stdin);
	  sscanf (entrada, "%s", expresion);
	  
	  FormarArbol (expresion, strlen (expresion), &arbol);
	  resolver (&arbol, 1);
	  printf ("\nPulse una tecla para continuar.");
	  fgets (entrada, 1000, stdin);
	  
	default:
	  return 0;
	}
    }
}
