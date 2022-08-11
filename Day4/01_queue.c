//01. Implement Queue

#include<stdio.h>
#include<stdlib.h>
#define MAX 5			// Queue Maximum size = 5

void enqueue ();		// Function Prototypes
void dequeue ();
void display ();

int front = -1, rear = -1;	// Global variables Declared.
int q[MAX];			// queue with size = max =5 is taken

int
main ()
{
  int ch;
  while (ch != 4)		// Until not Exit command. Take input again and again.
    {
      printf
	("1. Insert an Element in queue\n2. Delete an Element from queue\n3. Display Elements\n4. Exit\n");
      printf ("Enter choice:\n");
      scanf ("%d", &ch);
      switch (ch)
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
	  exit (0);
	  break;

	default:
	  printf ("Selection is Invalid.");
	}
    }
}

// FUNCTION TO ADD ELEMENT TO QUEUE.
void
enqueue ()
{
  int num;
  printf ("Enter the Number to queue: ");
  scanf ("%d", &num);
  if (rear == MAX - 1)			//i.e queue is completely filled from q[0] to q[4]. 
    {
      printf ("Element can't be Entered. Queue is Full.\n");
    }
  else if (front == -1 && rear == -1)	// Queue is Empty. Initialize the queue.
    {
      front = 0;
      rear = 0;
    }
  else
    {
      rear = rear + 1;			//Increment Rear index 
    }
  q[rear] = num;			// Place entered element "num" to incremented index in queue
}

// FUNCTION TO REMOVE ELEMENT FROM QUEUE.
void
dequeue ()
{

  if (front == -1 && rear == -1)	// If Queue is empty we can't remove anything from it as obvious.
    {
      printf ("QUEUE is already Empty.\n");
    }
  else
    {
      int num = q[front];		//Value of Front index is saved to "num" to show the deleted element.
      if (front == rear)		// Only one element remaining in queue.
	{
	  front = -1;
	  rear = -1;
	}
      else
	{
	  front += 1;			// Increment "front" to remove/ delink the element. 
	}
      printf ("Removed Element: %d\n", num);
    }
}

// FUNCTION TO DISPLAY ELEMENTS OF QUEUE.
void
display ()
{
  if (rear == -1)			//Check Queue is empty or not.
    {
      printf ("Queue is Empty.\n");
    }
  else
    {
	 for (int i = front; i <= rear; i++)
	{
	  printf ("q[%d]: %d\n", i, q[i]);
	}
    }
}
