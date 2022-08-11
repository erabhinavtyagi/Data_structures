//02. Write a program to implement circular queue using array.

#include<stdio.h>
#include<stdlib.h>

#define MAX 5			// Maximum Location in Queue =5.

void enqueue (int);
void dequeue ();
void display ();
int is_empty ();
int is_full ();

int front = -1, rear = -1;
int cq[MAX];

//-------------------MAIN FUNCTION--------------------------
int
main ()
{
  int choice, num;
  while (choice != 4)
    {
      printf
	("-----------------------------------------------------------\n");
      printf
	("\n1. Enter the Element to Circular Queue.\n2. Delete an Element.\n3. Display the Circular Queue.\n4. Exit\n");
      printf ("Enter the choice: ");
      scanf ("%d", &choice);

      switch (choice)
	{
	case 1:
	  if (is_full ())	// Queue is Full.
	    {
	      printf ("Circular Queue is Full.\n");
	      break;
	    }
	  printf ("Add the Element into Queue:  ");
	  scanf ("%d", &num);
	  enqueue (num);
	  break;

	case 2:
	  dequeue ();
	  break;

	case 3:
	  display ();
	  break;

	case 4:
	  exit (0);		//Successfully Terminated
	  break;

	default:
	  printf ("Enter Valid Choice.\n");
	}
    }
}

//------------------FUNCTION TO CHECK EMPTY QUEUE----------------
int
is_empty ()
{
  if (rear == -1 && front == -1)
    return 1;			//TRUE
  else
    return 0;			//FALSE
}

//------------------FUNCTION TO CHECK FULL QUEUE---------------------
int
is_full ()
{
  if ((rear + 1) % MAX == front)	// if Rear is 2 then (2+1) MOD 5 i.e then remainder is 3 == Front.
    return 1;
  else
    return 0;
}

//-----------------FUNCTION TO ADD AN ELEMENT IN QUEUE-------------------
void
enqueue (int num)
{
  if (is_empty ())		// Queue is Empty.
    {
      front = 0;		// Increment Rear & Front to index 0.
      rear = 0;
      cq[rear] = num;
    }
  else
    {
      rear = (rear + 1) % MAX;	// Increment the Rear Index.
      cq[rear] = num;		// ADD ELEMENT
    }
}

//-----------------FUNCTION TO REMOVE AN ELEMENT FROM QUEUE--------------
void
dequeue ()
{
  int removed;
  if (is_empty ())
    {
      printf ("Queue is already Empty.\n");
      return;
    }
  else if (front == rear)
    {
      front = -1;
      rear = -1;
    }
  else
    {
      removed = cq[front];	//JUST TO CHECK WHICH ELEMENT IS REMOVED
      printf ("Removed Element is %d.\n", removed);

      front = (front + 1) % MAX;	//INCREMENT FRONT TO REMOVE THE ELEMENT
    }
}

//-----------------DISPLAY THE QUEUE--------------------------------------
void
display ()
{
  int i;
  if (is_empty ())
    {
      printf ("Queue is Empty.\n");
      return;
    }
  else
    {
      for (i = front; i != rear; i = (i + 1) % MAX)	// LOGIC NOT WORKING PROPERLY **********
	{
	  printf ("cq[%d]: %d\n", i, cq[i]);
	}
      printf ("cq[%d]: %d\n", i, cq[rear]);
    }
}
