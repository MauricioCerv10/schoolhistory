
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
operar (struct narbol *nodo)
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
resolver (struct narbol **arbol, int i)
{
  
  if (*arbol != NULL)
    {
      struct narbol *operacion = BuscarOperable (*arbol);
      if (operacion == NULL)
	{
	  printf ("\n%d. El resultado final es %.2f.\n", i,
		   (*arbol)->n);
	  free (*arbol);
	  *arbol = NULL;
	}
      else
	{
	  operar (operacion);
	  resolver (arbol, i + 1);
	}
    }
}
