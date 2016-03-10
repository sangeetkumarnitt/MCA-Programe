#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node* npx;  
};
struct node *XOR (struct node *a, struct node *b)
{
    return (struct node*) ((unsigned int) (a) ^ (unsigned int) (b));
}
void insert(struct node **head_ref, int data)
{  
    struct node *new_node  = (struct node *) malloc (sizeof (struct node) );
       new_node->data = data;
       new_node->npx = XOR(*head_ref, NULL);
        if (*head_ref != NULL)
        {
            struct node *next = XOR((*head_ref)->npx,  NULL);
            (*head_ref)->npx = XOR(new_node, next);
        }
           *head_ref = new_node;
}
void printList (struct node *head)
{
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;
    printf ("Following are the nodes of Linked List: \n");
    while (curr != NULL)
    {
          printf ("%d ", curr->data);
          next = XOR (prev, curr->npx);
          prev = curr;
          curr = next;
    }
}
   void insertend(struct node **head_ref, int data)
{  
    struct node *new_node  = (struct node *) malloc (sizeof (struct node) );
       new_node->data = data;
       new_node->npx = XOR(*head_ref, NULL);
    //struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;
    while ((*head_ref)->npx != NULL)
    {
          printf ("%d ", (*head_ref)->data);
          next = XOR (prev, (*head_ref)->npx);
          prev = (*head_ref);
          (*head_ref) = next;
    }

        	
            next = XOR((*head_ref)->npx,  NULL);
            (*head_ref)->npx = XOR(new_node, next);
        
}
 

int main ()
{
    int i,n,data;
    struct node *head = NULL;
    printf("Enter the No. of nodes=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      printf("Enter the data=");
      scanf("%d",&data);              
      insert(&head,data);
     }
      scanf("%d",&data);  
     insertend(&head,data);
     
    printList (head);
    system("pause");
    return (0);
}
