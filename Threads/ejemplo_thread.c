//*****************************************************************
//EDGARDO ADRIÁN FRANCO MARTÍNEZ 
//Curso: Análisis de algoritmos
//ESCUELA SUPERIOR DE CÓMPUTO - IPN
//(C) Marzo 2013
//Ejemplo del empleo de Threads
//Compilación: ""gcc -lm -lpthread -o ejemplo_thread ejemplo_thread.c"
//Ejecución: "./ejemplo_thread 4"
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads;			//Número de threads
int N;

//********************************************************************************
//COMPORTAMIENTO DE LOS THREADS
//********************************************************************************

//********************************************************************************
//1 Saludar 
//********************************************************************************
void* saludar(void* id)
{
	printf("\nHola desde Saludar\tSoy el thread %d",(int)id);
}

//********************************************************************************
//2 Realizar un procesamiento
//********************************************************************************
void* procesar(void* id)
{	
	int n_thread=(int)id;
	int inicio,fin,i,a;

	//Revisar la parte de los datos a procesar	
	inicio=(n_thread*N)/NumThreads;
	if(n_thread==NumThreads-1)	
		fin=N;
	else
		fin=((n_thread+1)*N)/NumThreads-1;

	printf("\nHola desde procesar\tSoy el thread %d\tInicio %d\tTermino %d",n_thread,inicio,fin);
	for(i=inicio;i<=fin;i++)
		a=i*i;		
		//printf("\nProcesando dato %d",i);

	printf("\nBye desde procesar\tSoy el thread %d\tHe terminado",n_thread);

}
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
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char *argv[])
{	
	int i,j,k; 	//Variables auxiliares para loops
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************	
	
	//********************************************************************************
	//Obtener el número de threads a usar y el arreglo para la identificacion de los mismos
	//********************************************************************************
	pthread_t *thread;
	if (argc<2) 
	{
		printf("Indique el número de threads - \tEjemplo: [user@equipo]$ %s 4\n\n",argv[0]);
		exit(-1);
	}  
	NumThreads=atoi(argv[1]);
	thread = malloc(NumThreads*sizeof(pthread_t));

	//***************************************************************************************************************************
	//Saber cuál es el tamaño del problema N
	//***************************************************************************************************************************	
	//Si no se introduce correctamente N
	if (argc!=3) 
	{
		printf("\nIndique el tamaño de N - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
		exit(-1);
	}
	N=atoi(argv[2]);


	//***************************************************************************************************************************
	//1 Saludar desde cada hilo "saludar"
	//***************************************************************************************************************************
	//Crear los threads con el comportamiento "segmentar"
	for (i=1; i<NumThreads; i++) 
	{
		if (pthread_create (&thread[i], NULL, saludar,(void*)i) != 0 ) 
		{
			perror("El thread no  pudo crearse");
			exit(-1);
		}
	}
	
	//El main ejecuta el thread 0
	saludar(0);
	
	//Esperar a que terminen los threads (Saludar)
	for (i=1; i<NumThreads; i++) pthread_join (thread[i], NULL);
				
	//***************************************************************************************************************************
	//2 Procesar desde cada hilo "procesar"
	//***************************************************************************************************************************
	//Crear los threads con el comportamiento "segmentar"
	for (i=1; i<NumThreads; i++) 
	{
		if (pthread_create (&thread[i], NULL, procesar,(void*)i) != 0 ) 
		{
			perror("El thread no  pudo crearse");
			exit(-1);
		}
	}
	
	//El main ejecuta el thread 0
	procesar(0);
	
	//Esperar a que terminen los threads (Saludar)
	for (i=1; i<NumThreads; i++) pthread_join (thread[i], NULL);

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
	printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", NumThreads,(utime1 - utime0)/NumThreads);	
	printf("sys (Tiempo en acciónes de E/S)  %.3f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
	
	//Terminar programa normalmente	
	exit (0);	
}
