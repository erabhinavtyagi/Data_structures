//5. Write a program to implement queue using linked list.

#include<stdio.h>
#include<stdlib.h>

struct node			// Structure Declaration
{
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue ();		// Function Declaration
void dequeue ();
void display ();
void peek ();

//------------- MAIN FUNCTION-----------------------
int
main ()
{
  int choice;
  while (choice != 5)
    {
      printf ("\n----------------------------------------\n");
      printf
	("OPERATIONS:\n 1. Enqueue Item\n 2. Dequeue Item\n 3. Display Queue\n 4. Show Top Element\n 5. Exit\n");
      printf ("Enter Choice: ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  enqueue ();
	  break;
	case 2:
	  dequeue ();
	  break;
	case 3:
	  display ();
	  break;
	case 4:
	  peek ();
	  break;
	case 5:
	  exit (0);
	default:
	  printf ("PLEASE ENTER THE VALID CHOICE.\n");
	}
    }
  return 0;
}

//------------------------FUNCTION TO INSERT VALUE IN QUEUE------------------------
void
enqueue ()
{
  int data;
  struct node *newnode;		//create a new node to add an element in queue.
  newnode = (struct node *) malloc (sizeof (struct node));

  printf ("Enter data to Enqueue: ");
  scanf ("%d", &data);
  newnode->data = data;		// Enter data into newnode
  newnode->next = NULL;		// Assign NULL to its next link part.

  if (front == 0 && rear == 0)	// CASE 1: Check for Empty Queue
    {
      front = rear = newnode;
    }
  else
    {
      rear->next = newnode;	// CASE 2: if not empty then assign newnode address to rear
      rear = newnode;
    }
}

//---------------------FUNCTION TO DELETE VALUE FROM THE QUEUE--------------------------
void
dequeue ()
{
  struct node *temp = front;		// assign address of front to temp pointer

  if (front == 0 && rear == 0)		// CASE 1: Check for Empty Queue.
    {
      printf ("Queue is Empty.\n");
    }
  else if (front == rear)		// CASE 2: Only one element in Queue.
    {
      printf ("Deleted %d\n", temp->data);
      front = 0;			// Queue is empty now after deleting that last element	
      rear = 0;
    }
  else
    {					// CASE 3: Delete the element and increment the queue.
      printf ("Deleted %d\n", temp->data);
      front = front->next;
    }
  free (temp);				// Free the memory that contains the Deleted item
}

//-------------------FUNCTION TO DISPLAY THE QUEUE------------------------------------	
void
display ()
{
  struct node *temp;
  if (front == 0 && rear == 0)
    {
      printf ("Queue is Empty.\n");
    }
  else
    {
      temp = front;			// Initialize "temp pointer" to Front of the Queue
      while (temp != 0)			// print till temp reaches the last value.
	{
	  printf ("%d\n", temp->data);
	  temp = temp->next;
	}
    }
}

//-----------------FUNCTION TO CHECK THE LAST ITEM OF QUEUE-------------------------
void
peek ()
{
  if (front == 0 && rear == 0)
    {
      printf ("Queue is Empty.\n");
    }
  else
    {
      printf ("Last item in Queue is %d\n", rear->data);
    }
}
