/*PROYECTO: ÁRBOL DE EXPRESIÓN - POR: Fuentes García Alan Kevin - GRUPO: 1CM8*/
#include "hash.h"

int
transformar (char c)
{
  int i = 0;
  char menu[17] = "0123456789()+-*/";
  for (i = 0; c != menu[i]; i++);
  return i;
}

int
hash (char *cadena)
{
  int l = strlen (cadena), i = 0, r = 0;
  for (i = 0; i < l; i++)
    {
      r += transformar (*(cadena + i)) * i;
    }
  return r;
}

char *
IntToName (int n_hash)		/*CREA EL NOMBRE DE UN ARCHIVO CON EL NUMERO HASH DE LA EXPRESION */
{
  char *cadena = NULL, letra;
  int aux = n_hash, tam = 0, i = 0;
  do
    {
      cadena = (char *) realloc (cadena, sizeof (char) * (tam + 1));
      *(cadena + tam) = (char) ('0' + aux % 10);
      aux /= 10;
      tam++;
    }
  while (aux != 0);

  for (i = 0; i < tam / 2; i++)
    {
      letra = *(cadena + i);
      *(cadena + i) = *(cadena + tam - 1 - i);
      *(cadena + tam - 1 - i) = letra;
    }

  cadena = realloc (cadena, sizeof (int) * (tam + 1));
  *(cadena + tam) = '\0';
  strcat (cadena, ".txt");
  return cadena;
}

void
iniciar (struct nhash **tabla)
{
  int i = 0;
  for (i = 0; i < 1000; i++)
    {
      *(tabla + i) = NULL;
    }
}

struct nhash *
CrearLugar (char *exp)
{
  int l = strlen (exp) + 1, i = 0;
  struct nhash *nuevo = (struct nhash *) malloc (sizeof (struct nhash));
  nuevo->exp = (char *) malloc (sizeof (char) * l);
  for (i = 0; i < l; i++)
    {
      *(nuevo->exp + i) = *(exp + i);
    }
  nuevo->sig = NULL;
  return nuevo;
}

void
insertar (char *exp, struct nhash **tabla)
{
  int i = hash (exp) % 1000;
  struct nhash **aux = NULL;

  for (aux = tabla + i; *aux != NULL; aux = &(*aux)->sig);
  *aux = CrearLugar (exp);
}

int
buscar (char *exp, struct nhash **tabla)	/*DEVUELVE LA POSICION EN LA LISTA QUE ESTÉ */
{
  int i = hash (exp) % 1000, j = 0;
  struct nhash **aux = NULL;
  for (aux = tabla + i; *aux != NULL; aux = &(*aux)->sig)
    {
      if (hash (exp) == hash ((*aux)->exp))
	{
	  return j;
	}
      j++;
    }
  return -1;
}

void
eliminar (char *exp, struct nhash **tabla)
{
  int i = hash (exp) % 1000, j = buscar (exp, tabla), k = 0;
  struct nhash **aux = NULL, *tmp = NULL;
  if (j != -1)
    {
      if (j == 0)
	{
	  aux = &(*(tabla + i))->sig;
	  free (*(tabla + i));
	  *(tabla + i) = *aux;

	}
      else
	{
	  for (aux = tabla + i; k < j - 1; aux = &(*aux)->sig)
	    {
	      k++;
	    }
	  tmp = (*aux)->sig;
	  (*aux)->sig = tmp->sig;
	  free (tmp);
	}
    }
}

void
GuardarExps (struct nhash **tabla)
{
  int i = 0;
  struct nhash **aux = NULL;
  FILE *archivo = fopen ("tabla.txt", "w");
  if (archivo == NULL)
    {
      printf ("Error al guardar la tabla");
      return;
    }
  for (i = 0; i < 1000; i++)
    {
      for (aux = tabla + i; *aux != NULL; aux = &(*aux)->sig)
	{
	  fprintf (archivo, "%s\n", (*aux)->exp);
	}
    }
  fclose (archivo);
}

void
mostrar (struct nhash **tabla)
{
  int i = 0;
  struct nhash **aux = NULL;
  for (i = 0; i < 1000; i++)
    {
      printf ("\n%d.", i);
      for (aux = tabla + i; *aux != NULL; aux = &(*aux)->sig)
	{
	  printf (" %s", (*aux)->exp);
	}
    }
}
