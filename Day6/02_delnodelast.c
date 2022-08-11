//2. Write a program to delete a node from linked list at last position.


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
void delete_lastnode ();

//-------------- MAIN FUNCTION ---------------------
int
main ()
{
  int choice, num;

  while(choice!=4)
  {
  printf("OPERATIONS:\n 1: Create linked list\n 2: Delete Last node from List\n 3: Display List\n 4: Exit\n");
  printf("Enter Your Choice: ");
  scanf ("%d", &choice);
  switch (choice)
    {
    case 1:
      printf ("\nNumber of Nodes:");
      scanf ("%d", &num);
      createlist (num);
      break;
    case 2:
      delete_lastnode ();
      break;
    case 3:
      display ();
      break;
    case 4:
      exit (1);
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

//-----------------FUNCTION TO DELETE LAST NODE--------------------

void delete_lastnode()
{
	struct node *ptr,*prev ;			// Two pointers taken : "Ptr" for last node and  "prev" for Second last node.
	if (head == NULL)				// CASE 1: LIST IS EMPTY
	{
	printf("List is Empty.\n");
	}
	else	
	{
	ptr = head; 
	prev = head;
	
	while(ptr->next != NULL)
	{					// CASE 2: Delete Last node in list of 'n' nodes.
	prev = ptr;				// Address of Last node copied to Previous node.
	ptr= ptr->next;			
	}
	if (ptr == head)
	{
	head = NULL;				// CASE 3: Only one node is there.
	}
	
	printf("Deleted %d\n",ptr->data);		// Data of node to be deleted.
	prev->next =NULL; 
	free(ptr);

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
	    link =head;
      while (link != NULL)
	{
	  printf ("Node %d: %d\n", i, link->data);
	  link = link->next;
	  i++;
	}
    }
}
