//4. Write a program to insert a new node after nth node.

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
} *head;

void createlist (int);
void insertnode ();
void display ();
int sizeoflist (struct node *);

int
main ()
{
  int n;
  printf ("Enter the number of Nodes: ");
  scanf ("%d", &n);
  createlist (n);		// calling Function to create the linked list
  printf ("Elements of the List are----------------------------\n\n");
  display ();			// Display Initial Linked List
  insertnode ();		// Updated Linked List
  return 0;
}

//-----------FUNCTION TO FIND LENTGH OF LINKED LIST----------
int
sizeoflist (struct node *head)
{
  int size = 0;
  struct node *link = head;

  while (link != NULL)
    {
      link = link->next;
      size++;
    }
  return size;
}

//------------FUNCTION TO CREATE LINKED LIST------------------
void
createlist (int n)
{
  struct node *newnode, *ptr;
  int data;

	//create head node
  head = (struct node *) malloc (sizeof (struct node));

  if (head == NULL)
    {
      printf ("Unable to allocate Memory\n");
    }
  else
    {
      printf ("Enter the Data for Node[1]: ");
      scanf ("%d", &data);

      head->data = data;
      head->next = NULL;
      ptr = head;
    }

	// create next nodes upto n terms.
  for (int i = 2; i <= n; i++)
    {
      newnode = (struct node *) malloc (sizeof (struct node));

      printf ("Enter the data for Node[%d]: ", i);
      scanf ("%d", &data);

      newnode->data = data;
      newnode->next = NULL;

      ptr->next = newnode;
      ptr = ptr->next;
    }
  printf ("List is Created.\n");
}

// FUNCTION TO INSERT NODE AT ANY LOCATION ----------------------

void
insertnode ()
{
  int data, index;
  int count = 1;
  int size = sizeoflist (head);
  struct node *ptr, *inserted;

  inserted = (struct node *) malloc (sizeof (struct node));	// Allocate memory for data to be inserted.

		//-----------------Enter Details for New Node----------------------

  printf ("Enter the location after which you want to insert a node : ");
  scanf ("%d", &index);

  if (index < 0 || index > size)	//CASE 1: INVALID INDEX LOCATION
    {
      printf ("Enter Valid Index.\n");
      return;
    }
  else
    printf ("Enter the data:");
  scanf ("%d", &data);

  printf
    ("Final Linked List after Insertion of new node--------------------\n");

  if (index == 0)		//CASE 2: INSERTION AT BEGINNING OF LINKED LIST.
    {
      inserted->data = data;	// Data is inserted in node
      inserted->next = head;	// head address is copied to inserted node link part. To link it to the rest of the node.
      head = inserted;		// Address of inserted node is given to head pointer.

      printf ("Element Inserted as first node.\n");
    }
  else
    {
      ptr = head;

      while (ptr != NULL)	//CASE 3: INSERTION UPTO SECOND LAST NODE.
	{
	  if (count == index)
	    {
	      inserted->data = data;
	      inserted->next = ptr->next;
	      ptr->next = inserted;
	    }
	  printf ("NODE[%d]: %d\n", count, ptr->data);
	  ptr = ptr->next;
	  count++;
	}
    }
}

//------------- FUNCTION TO DISPLAY INITIAL LIST-------------

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
	  printf ("Data is %d\n", ptr->data);
	  ptr = ptr->next;
	}
    }
}
