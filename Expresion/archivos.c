/*PROYECTO: ÁRBOL DE EXPRESIÓN - POR: Fuentes García Alan Kevin - GRUPO: 1CM8*/
#include "archivos.h"

void
leer (char *n_archivo)		/*LEE EL ARCHIVO CUYA CLAVE SE INGRESA, SI ES QUE EXISTE. */
{
  int letra;
  FILE *archivo = fopen ((const char *) n_archivo, "r");
  if (archivo == NULL)
    {
      printf ("\nARCHIVO NO EXISTENTE.\n");
      return;
    }
  for (printf ("\n"); (letra = fgetc (archivo)) != EOF; putchar (letra))
    {
      if (letra == '\n')
	{
	  printf ("\n");
	}
    }
  fclose (archivo);
}

void
borrar (char *n_archivo)
{
  int l = strlen (n_archivo) + 4;
  char *comando = (char *) malloc (sizeof (char) * l);
  *comando = 'r';
  *(comando + 1) = 'm';
  *(comando + 2) = ' ';
  *(comando + 3) = '\0';
  strcat (comando, n_archivo);
  system ((const char *) comando);
}

void
limpiar (char cadena[1000])
{
  int i = 0;
  for (i = 0; i < 1000; i++)
    {
      cadena[i] = '\0';
    }
}

void
cargar (struct nhash **tabla)
{
  FILE *ftabla = fopen ("tabla.txt", "r");
  int letra = 0, i = 0;
  char entrada[1001], expresion[1000], tmp[1000];
  limpiar (expresion);
  limpiar (tmp);
  printf ("\nCargando tabla...");
  if (ftabla == NULL)
    {
      printf ("Error al recuperar datos");
      return;
    }
  while (1)
    {
      fgets (entrada, 1000, ftabla);
      sscanf (entrada, "%s", expresion);
      if (strcmp (expresion, tmp) != 0)
	{
	  insertar (expresion, tabla);
	  printf ("\nCargado %d", hash (expresion));
	  strcpy (tmp, expresion);
	}
      else
	{
	  break;
	}
    }
  printf ("\nRegistros cargados.");
  fclose (ftabla);
}

void
MasterClear (struct nhash **tabla)
{
  FILE *ftabla = fopen ("tabla.txt", "r");
  int n_hash = 0;
  char entrada[1001], expresion[1000], tmp[1000], *nombre = NULL;
  limpiar (expresion);
  limpiar (tmp);
  printf ("\nBorrando...");
  if (ftabla == NULL)
    {
      printf ("Error al recuperar datos");
      return;
    }
  while (1)
    {
      fgets (entrada, 1000, ftabla);
      sscanf (entrada, "%s", expresion);
      if (strcmp (expresion, tmp) != 0)
	{
	  eliminar (expresion, tabla);
	  n_hash = hash (expresion);
	  nombre = IntToName (n_hash);
	  borrar (nombre);
	  printf ("\nBorrado %d", n_hash);
	  strcpy (tmp, expresion);
	}
      else
	{
	  break;
	}
    }
  fclose (ftabla);
  ftabla = fopen ("tabla.txt", "w");
  fprintf (ftabla, "\n");
  fclose (ftabla);
  printf ("\nRegistros borrados.");
}
