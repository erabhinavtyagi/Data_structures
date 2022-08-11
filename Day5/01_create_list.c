//01. Write a program to create a Linked list with n elements.

#include<stdio.h>
#include<stdlib.h>

struct node			// Structure Declaration i.e it contains one int data and one self referential pointer (pointer to structure)
{
  int data;
  struct node *next;
} *head;

void createlist (int n);
void display ();

int
main ()
{
  int n;
  printf ("Enter the Total Number of Nodes: ");
  scanf ("%d", &n);
  createlist (n);
  printf ("Elements in List: \n");
  display ();
  return 0;
}

void
createlist (int n)
{
  struct node *newnode, *ptr;	// create two pointers to node structure i.e newnode and ptr.
  int data, i;
  head = (struct node *) malloc (sizeof (struct node));	// Allocate the memory and save the address in head.
  if (head == NULL)		// If head is still NULL that means no memory allocated.
    {
      printf ("Unable to allocate Memory");
    }
  else
    {
      printf ("Enter the data of Node 1: ");
      scanf ("%d", &data);
      head->data = data;	// First Node Created
      head->next = NULL;
      ptr = head;		// Copy the address of head to ptr.

      for (i = 2; i <= n; i++)	// Create next nodes
	{
	  newnode = (struct node *) malloc (sizeof (struct node));
	  if (newnode == NULL)
	    {
	      printf ("Unable to allocate memory.\n");
	      break;
	    }
	  else
	    {
	      printf ("Enter the data of Node %d: ", i);
	      scanf ("%d", &data);
	      newnode->data = data;
	      newnode->next = NULL;

	      ptr->next = newnode;	// newnode address is linked to previous node
	      ptr = ptr->next;	// address of newnode saved to ptr
	    }
	}
      printf ("List is created.\n\n");
    }
}

void
display ()
{
  struct node *ptr;
  if (head == NULL)
    {
      printf ("List is Empty.\n");
    }
  else
    {
      ptr = head;
      while (ptr != NULL)
	{
	  printf ("Data is %d.\n", ptr->data);
	  ptr = ptr->next;
	}
    }
}
