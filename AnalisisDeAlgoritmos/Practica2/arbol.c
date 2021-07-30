#include <stdio.h>
#include <stdlib.h>

int nodes; 
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
        printf("%d ", current->key);
 
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
 
// Driver code
int main()
{
    struct Node* root = newNode(10);
    insert(root,7);
    insert(root,6);
    insert(root,15);
    insert(root,11);
    insert(root,17);
 
    int key = 12;
    insert(root, key);
 
    //cout << endl;
    printf("\nInorder traversal after insertion:\n");
    inorder(root);
 
    return 0;
}

