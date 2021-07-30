/*PROYECTO: ÁRBOL DE EXPRESIÓN - POR: Fuentes García Alan Kevin - GRUPO: 1CM8*/
#include "solucion.h"

int
mayor (int a, int b)
{
  if (a > b)
    {
      return a;
    }
  return b;
}

int
altura (struct narbol *arbol)
{
  if (arbol == NULL)
    {
      return 0;
    }
  return 1 + mayor (altura (arbol->izq), altura (arbol->der));
}

void
operar (struct narbol *nodo)	/*RESUELVE LA OPERACION DE UN NODO EN ÉL MISMO */
{
  float a = nodo->izq->n, b = nodo->der->n;
  switch (nodo->c)
    {
    case '+':
      nodo->n = a + b;
      break;
    case '-':
      nodo->n = a - b;
      break;
    case '*':
      nodo->n = a * b;
      break;
    case '/':
      nodo->n = a / b;
      break;
    }
  free (nodo->izq);
  nodo->izq = NULL;
  free (nodo->der);
  nodo->der = NULL;
  nodo->tipo = 1;
}

struct narbol *
BuscarOperable (struct narbol *arbol)
{
  if (altura (arbol) <= 1)
    {
      return NULL;
    }
  if (altura (arbol) == 2)
    {
      return arbol;
    }
  if (altura (arbol->der) > altura (arbol->izq))
    {
      return BuscarOperable (arbol->der);
    }
  return BuscarOperable (arbol->izq);
}

void
resolver (struct narbol **arbol, char *n_archivo, int i)
{
  if (*arbol != NULL)
    {
      struct narbol *operacion = BuscarOperable (*arbol);
      FILE *archivo = fopen ((const char *) n_archivo, "a");
      if (archivo == NULL)
	{
	  printf ("\nERROR AL CREAR ARCHIVO.");
	}
      if (i == 1)
	{
	  fprintf (archivo, "~PASOS PARA RESOLVER LA EXPRESION: ");
	}
      if (operacion == NULL)
	{
	  fprintf (archivo, "\n%d. El resultado final es %.2f.\n", i,
		   (*arbol)->n);
	  free (*arbol);
	  *arbol = NULL;
	  fclose (archivo);
	}
      else
	{
	  fprintf (archivo, "\n%d. Efectuar %.2f %c %.2f.", i,
		   operacion->izq->n, operacion->c, operacion->der->n);
	  operar (operacion);
	  fprintf (archivo, " (Resultado es %.2f)", operacion->n);
	  fclose (archivo);
	  resolver (arbol, n_archivo, i + 1);
	}
    }
}
