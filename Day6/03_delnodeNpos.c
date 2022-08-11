//3. Write a program to delete a node from linked list at nth position.


#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
} *head;

struct node *ptr, *newnode;

//--------- Function Declaration ---------------------
void createlist (int);
void display ();
void delete_node ();

//-------------- MAIN FUNCTION ---------------------
int
main ()
{
  int choice, num;

  while (choice != 4)
    {
      printf
	("----------------------------------------------------------------------------------");
      printf
	("\nOPERATIONS:\n 1: Create linked list\n 2: Delete Node\n 3: Display List\n 4: Exit\n");
      printf ("Enter Your Choice: ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  printf ("\nNumber of Nodes:");
	  scanf ("%d", &num);
	  createlist (num);
	  break;
	case 2:
	  delete_node ();
	  break;
	case 3:
	  display ();
	  break;
	case 4:
	  exit (1);
	default: printf("Invalid Input\n");
	}
    }
  return 0;
}

//--------------- FUNCTION TO CREATE LINKED LIST ---------------------------

void
createlist (int n)
{
  int data;
  head = (struct node *) malloc (sizeof (struct node));

  if (head == NULL)		// List is Empty.
    {
      printf ("Memory Not Allocated.\n");
    }
  else
    {
      printf ("Enter data for Node 1: ");
      scanf ("%d", &data);
      head->data = data;
      head->next = NULL;	// NODE 1 Created.
      ptr = head;
    }

  //Creation of Next nodes
  {
    for (int i = 2; i <= n; i++)
      {
	newnode = (struct node *) malloc (sizeof (struct node));
	printf ("Enter data for Node %d: ", i);
	scanf ("%d", &data);

	newnode->data = data;
	newnode->next = NULL;
	ptr->next = newnode;	// Link created between Node 1 & 2 and so on
	ptr = ptr->next;	// Address of node copied to ptr
      }
  }
  printf ("List is Created.\n");
}

//-----------------FUNCTION TO DELETE Nth NODE--------------------

void
delete_node ()
{
  struct node *temp;		// Two pointers taken : "ptr" for previous node and  "temp" for main node.
  int n;
  ptr = head;			// We will Traverse the list through ptr
  printf ("Enter the node which you want to delete:");
  scanf ("%d", &n);

      if (n == 0)		// CASE 1: LIST IS EMPTY
	{
	  printf ("List is Empty.\n");
	}
      else if (n == 1 && head->next == NULL)	// CASE 2: Only Head Node is there.                             
	{
	  head = head->next;
	  ptr->next = NULL;
	  printf ("Deleted %d\n", ptr->data);
	  free (ptr);
	}
      else if (n == 1)		// CASE 3: To delete first node. 
	{
	  head = head->next;
	  ptr->next = NULL;
	  printf ("Deleted %d\n", ptr->data);
	  free (ptr);
	}
      else
	{
	  for (int i = 1; i < n - 1; i++)	// CASE 4: Removing Nth Node. Traverse till n-1 node.
	    {
	      ptr = ptr->next;	// save address of Node to be deleted in ptr.
	    }

	  temp = ptr->next;	// save address of (n+1)th node in temp.
	  ptr->next = temp->next;	// link n-1 & n+1 node.

	  printf ("Deleted %d\n", temp->data);
	  free (temp);		// free nth node.
	}
}

// ----------------FUNCTION TO DISPLAY LIST---------------------

void
display ()
{
  struct node *link;
  int i = 1;
  if (head == NULL)
    {
      printf ("List is Empty.\n");
    }
  else
    {
      link = head;
      while (link != NULL)
	{
	  printf ("Node %d: %d\n", i, link->data);
	  link = link->next;
	  i++;
	}
    }
}
