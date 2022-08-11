//2. Write a program to print the elements in a link list.

#include <stdio.h>
#include <stdlib.h>

//structure of a node
struct node
{
  int data;
  struct node *next;
} *head;

void createlist (int);
void search_node ();

//-------------- MAIN FUNCTION----------------------

int
main ()
{
  int num;
  printf ("Enter No. of Nodes: ");
  scanf ("%d", &num);

  createlist (num);
  search_node ();

  return 0;
}

// ------------ FUNCTION TO CREATE LINKED LIST---------------

void
createlist (int n)
{
  struct node *newnode, *ptr;
  int data;
  head = (struct node *) malloc (sizeof (struct node));

  if (head == NULL)
    {
      printf ("Unable to allocate memory.\n");
      return;
    }
  else
    {
      printf ("Enter data for Node 1 : ");
      scanf ("%d", &data);
      head->data = data;
      head->next = NULL;	// Node 1 created.
      ptr = head;

      for (int i = 2; i <= n; i++)	// creation of next nodes.
	{
	  newnode = (struct node *) malloc (sizeof (struct node));

	  if (newnode == NULL)
	    {
	      printf ("Unable to Allocate Memory for newnode.\n");
	      break;
	    }
	  else
	    {
	      printf ("Enter data for Node %d : ", i);
	      scanf ("%d", &data);

	      newnode->data = data;
	      newnode->next = NULL;

	      ptr->next = newnode;
	      ptr = ptr->next;
	    }
	}
      printf ("List is created.\n");
    }
}

//---------FUNCTION TO SEARCH NODE AND PRINT THE VALUE----------------

void
search_node ()
{
  struct node *ptr;
  int index;
  int count = 1;

  if (head == NULL)
    {
      printf ("List is Empty.\n");
    }
  else
    {
      ptr = head;
      printf ("Enter the index whose data you want to know: ");
      scanf ("%d", &index);
      while (ptr != NULL)	//Here If we check "ptr->next != Null" then it will not print the last node value.
	{
	  if (count == index)
	    printf ("Data at node %d is %d.\n", index, ptr->data);
	  count++;
	  ptr = ptr->next;
	}
    }
}
