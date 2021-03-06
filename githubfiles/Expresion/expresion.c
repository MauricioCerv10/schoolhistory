/*PROYECTO: ÁRBOL DE EXPRESIÓN - POR: Fuentes García Alan Kevin - GRUPO: 1CM8*/
#include "expresion.h"

struct narbol *
CrearNodo (char *c, float *n)	/*CREA UN NUEVO NODO */
{
  struct narbol *nuevo = (struct narbol *) malloc (sizeof (struct narbol));
  if (c != NULL)
    {
      nuevo->tipo = 0;
      nuevo->c = *c;
    }

  if (n != NULL)
    {
      nuevo->tipo = 1;
      nuevo->n = *n;
    }
  nuevo->izq = NULL;
  nuevo->der = NULL;
  return nuevo;
}

void
CopiarCadena (char *cadena, char **copia, int l)
{
  int i = 0;
  *copia = (char *) malloc (sizeof (char) * l);
  for (i = 0; i < l; i++)
    {
      *(*copia + i) = *(cadena + i);
    }
}

float
TenToThe (int n)
{
  int i = 0;
  float r = 1;
  for (i = 0; i < n; i++)
    {
      r *= 10.0f;
    }
  return r;
}

int
EsOperador (char x)		/*COMPRUEBA SI UN CARACTER ES UN OPERADOR */
{
  switch (x)
    {
    case '+':
      return 1;
    case '-':
      return 1;
    case '*':
      return 1;
    case '/':
      return 1;
    default:
      return 0;
    }
}

int
parentesis (char *cadena, int l)
{
  int i = 0;
  for (i = 0; i < l; i++)
    {
      if (*(cadena + i) == '(' || *(cadena + i) == ')')
	{
	  return 1;
	}
    }
  return 0;
}

int
operadores (char *cadena, int l)
{
  int i = 0;
  for (i = 0; i < l; i++)
    {
      if (EsOperador (*(cadena + i)) == 1)
	{
	  return 1;
	}
    }
  return 0;
}

float
CharToFloat (char *cadena, int l)
{
  int i = 0;
  float r = 0;
  for (i = 0; i < l; i++)
    {
      r += (float) (*(cadena + i) - '0') * TenToThe (l - 1 - i);
    }
  return r;
}

void
simplificar (char **cadena, int *l)	/*DETECTA PARÉNTESIS INNECESARIOS DE LOS EXTREMOS DE LA EXPRESIÓN */
{
  if (*(*cadena) == '(')
    {
      int i = 0, r = 1;
      for (i = 1; i < *l; i++)
	{
	  if (*(*cadena + i) == '(')
	    {
	      r++;
	    }
	  if (*(*cadena + i) == ')')
	    {
	      r--;
	    }
	  if (r == 0)
	    {
	      break;
	    }
	}
      if (i == *l - 1)
	{
	  (*l) -= 2;
	  char *nueva = (char *) malloc (sizeof (char) * (*l));
	  for (i = 0; i < *l; i++)
	    {
	      *(nueva + i) = *(*cadena + i + 1);
	    }
	  free (*cadena);
	  *cadena = nueva;
	  simplificar (cadena, l);
	}
    }
}

int
SumaParentesis (char *cadena, int l)	/*DETECTA SI ESTÁN CERRADOS LOS PARENTESIS DE UNA CADENA */
{
  int i = 0, r = 0;
  for (i = 0; i < l; i++)
    {
      if (*(cadena + i) == '(')
	{
	  r++;
	}
      if (*(cadena + i) == ')')
	{
	  r--;
	}
    }
  return r;
}

void
OpLibres (char *cadena, int l, char **ops, int **poss, int *t)	/*OBTIENE OPERADORES LIBRES */
{
  int i = 0;
  (*t) = 0;
  for (i = 0; i < l; i++)
    {
      if (EsOperador (*(cadena + i)) == 1)
	{
	  if (SumaParentesis (cadena, i) == 0)
	    {
	      (*t)++;
	      *ops = (char *) realloc (*ops, sizeof (char) * (*t));
	      *(*ops + (*t) - 1) = *(cadena + i);
	      *poss = (int *) realloc (*poss, sizeof (int) * (*t));
	      *(*poss + (*t) - 1) = i;
	    }
	}
    }
}

int
MenorLibre (char *cadena, int l)	/*OBTIENE AL MENOR OPERADOR LIBRE DE UNA CADENA */
{
  char *ops = NULL;
  int *poss = NULL, t = 0, i = 0;
  OpLibres (cadena, l, &ops, &poss, &t);
  for (i = t - 1; i >= 0; i--)
    {
      if (*(ops + i) == '+' || *(ops + i) == '-')
	{
	  return *(poss + i);
	}
    }
  return *(poss + t - 1);
}

void
FormarArbol (char *cadena, int l, struct narbol **arbol)	/*FORMA EL ARBOL DE UNA EXPRESIÓN */
{
  char *copia = NULL, *auxc = 0;
  int l2 = l, auxi = 0;
  float auxf = 0.0f;
  CopiarCadena (cadena, &copia, l);//crear replica de una cadea
  simplificar (&copia, &l2);//detecta parentecis inecesarios en los extremos de la expresion
  if (parentesis (copia, l2) == 0 && operadores (copia, l2) == 0)// confirma existencia de parentecis y de cadena en la copia
    {
      auxf = CharToFloat (copia, l2);
      *arbol = CrearNodo (NULL, &auxf);
    }
  else if (*copia == '-')
    {
      auxc = (char *) malloc (sizeof (char) * (l2 + 1));
      *auxc = '0';
      for (auxi = 0; auxi < l2; auxi++)
	{
	  *(auxc + auxi + 1) = *(copia + auxi);
	}
      free (copia);
      FormarArbol (auxc, l2 + 1, arbol);
    }
  else
    {
      auxi = MenorLibre (copia, l2); //obtiene el operador libre de una cadena 
      *arbol = CrearNodo (copia + auxi, NULL);
      FormarArbol (copia, auxi, &(*arbol)->izq);
      FormarArbol (copia + auxi + 1, l2 - auxi - 1, &(*arbol)->der);
    }
}
