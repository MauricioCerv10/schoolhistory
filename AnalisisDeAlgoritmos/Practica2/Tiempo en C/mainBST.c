//*****************************************************************
//M. EN C. EDGARDO ADRIÁN FRANCO MARTÍNEZ 
//Curso: Análisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//Ejemplo de medición de tiempo en C y recepción de parametros en C bajo UNIX
//Compilación: "gcc main.c tiempo.x  -o main(teimpo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
//Ejecución: "./main n" (Linux y MAC OS)
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
//******************************************************************/
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//******************************************************************/
int nodes; 
int* A;
/* A binary tree node has key, pointer to left child
and a pointer to right child */
struct Node {
    int key;
    struct Node* left, *right;
};
 
/* function to create a new node of tree and r
   eturns pointer */
struct Node* newNode(int key)
{
    struct Node* temp = (struct Node*)malloc(1*sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
};
 

struct sNode
{
  struct Node *t;
  struct sNode *next;
};
 
/* Stack related functions */
void push(struct sNode** top_ref, struct Node *t);
struct Node *pop(struct sNode** top_ref);
int isEmpty(struct sNode *top);
 
/* Iterative function for inorder tree traversal */
void inorder(struct Node *root)
{
  /* set current to root of binary tree */
  struct Node *current = root;
  struct sNode *s = NULL;  /* Initialize stack s */
  int done = 0;
 
  while (!done)
  {
    /* Reach the left most tNode of the current tNode */
    if(current !=  NULL)
    {
      /* place pointer to a tree node on the stack before traversing 
        the node's left subtree */
      push(&s, current);                                               
      current = current->left;  
    }
        
    /* backtrack from the empty subtree and visit the tNode 
       at the top of the stack; however, if the stack is empty,
      you are done */
    else                                                             
    {
      if (!isEmpty(s))
      {
        current = pop(&s);
        //printf("%d ", current->key);
 	A[nodes++] = current->key;
        /* we have visited the node and its left subtree.
          Now, it's right subtree's turn */
        current = current->right;
      }
      else
        done = 1; 
    }
  } /* end of while */ 
}     
 
/* UTILITY FUNCTIONS */
/* Function to push an item to sNode*/
void push(struct sNode** top_ref, struct Node *t)
{
  /* allocate tNode */
  struct sNode* new_Node =
            (struct sNode*) malloc(sizeof(struct sNode));
 
  if(new_Node == NULL)
  {
     printf("Stack Overflow \n");
     getchar();
     exit(0);
  }            
 
  /* put in the data  */
  new_Node->t  = t;
 
  /* link the old list off the new tNode */
  new_Node->next = (*top_ref);   
 
  /* move the head to point to the new tNode */
  (*top_ref)    = new_Node;
}
 
/* The function returns true if stack is empty, otherwise false */
int isEmpty(struct sNode *top)
{
   return (top == NULL)? 1 : 0;
}   
 
/* Function to pop an item from stack*/
struct Node *pop(struct sNode** top_ref)
{
  struct Node *res;
  struct sNode *top;
 
  /*If sNode is empty then error */
  if(isEmpty(*top_ref))
  {
     printf("Stack Underflow \n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->t;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
 

/*function to insert element in binary tree */
struct Node* insert(struct Node* root, int key)
{
	struct Node* temp=root;
       struct Node* node=newNode(key);
       node->key=key;
       node->left=NULL;
       node->right=NULL;
       if (root==NULL)
       {
           root=node;
	   return root;
           //printf("%d\n",T->Element);
       }
       else
       {
           while(1)
           {
               if (temp->key>=node->key && temp->left==NULL)
               {
                   temp->left=node;
                   break;
               }
               else if (temp->key>=node->key && temp->left!=NULL)
               {

                   temp=temp->left;
               }
               else if (temp->key < node->key && temp->right==NULL)
               {
                   temp->right=node;
                   break;
               }
               else
               {
                   temp=temp->right;
               }
           }   
                 return root;
       }    
    
}
/*hace un recorrido en inorden hasta encontrar el valor buscado, 
si no lo encuentra  retorna 0*/
int search(struct Node* root, int key)
{
	struct Node* temp=root;
       if (root==NULL)
       {
	   return 0;
       }
       else
       {
           while(1)
           {
               if(temp->key == key){
			return 1;
		}
	       else if (temp->key>key && temp->left==NULL)
               {
                   return 0;
               }
               else if (temp->key>key && temp->left!=NULL)
               {

                   temp=temp->left;
               }
               else if (temp->key < key && temp->right==NULL)
               {
                   return  0;
               }
               else
               {
                   temp=temp->right;
               }
           }   
                 return 0;
       }    
    
}


//*****************************************************************
//VARIABLES GLOBALES*/

//******************************************************************/
//*****************************************************************
//PROGRAMA PRINCIPAL 
//******************************************************************/
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//*******************************************************************/	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i; //Variables para loops

	//******************************************************************	
	//Recepción y decodificación de argumentos
	//*******************************************************************/	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
	}
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//*******************************************************************/	
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo
	//*******************************************************************/
	
	int *tmp = (int*)malloc(n*sizeof(int));

	for(int i = 0;i<n;i++){
		scanf("%d",&tmp[i]);
	}


	struct Node* root = newNode(tmp[0]);

	for(int i = 0;i<n-1;i++){
                insert(root,tmp[i]);
        }
	uswtime(&utime0, &stime0, &wtime0);
	//printf("Introduzca numero a buscar\n");
	int numS = 3128036;
	A = (int*)malloc(n*sizeof(int));
    	int res = search(root,numS);
	//if(res == 1) printf("\nEncontrado\n");
	//else printf("\nNo encontrado\n");
    	//inorder(root);
	
 	
    	

	
	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//*******************************************************************/
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	
	//printf("\n");
	//printf("%d",n);
	/*printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));*/
	//printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	//printf("\n");
        printf(" %.10e s ",  wtime1 - wtime0);
	//printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	//printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	//printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	//printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	//printf("\n");
	//******************************************************************

	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************


