//4. Write a program to implement stack using linked list.


#include<stdio.h>
#include<stdlib.h>

struct node			// Structure Declaration
{
  int data;
  struct node *next;
};

struct node *top = NULL;	// Here we are taking "TOP" in place of "HEAD" 

void push ();			// Function Declaration
void pop ();
void display ();
void peek ();

//---------------------MAIN FUNCTION------------------------------
int
main ()
{
  int choice;

  while (choice != 5)
    {
      printf ("\n-------------------------------------------------------\n");
      printf
	("OPERATIONS:\n 1. PUSH\n 2. POP\n 3. Display\n 4. Top Value\n 5. Exit\n");
      printf ("Enter Your Choice: ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  push ();
	  break;
	case 2:
	  pop ();
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
	  printf ("INVALID INPUT\n");
	}
    }
  return 0;
}

//-------------------------FUNCTION TO INSERT THE ITEM IN STACK-----------------
void
push ()
{
  int data;
  struct node *newnode;
  newnode = (struct node *) malloc (sizeof (struct node));
  //Check for Memory Allocation
  if (newnode == NULL)
    {
      printf ("Memory not allocated.\n");
      return;
    }
  else
    //create Head Node.
    {
      printf ("PUSH DATA:  ");
      scanf ("%d", &data);
      newnode->data = data;	//create newnode.
      newnode->next = top;	//Make this node as TOP of STACK by saving the address of TOP to it.

      top = newnode;		//Increment TOP pointer to newnode.
    }
  printf ("Value Inserted: %d\n", newnode->data);
}

//----------------------FUNCTION TO DELETE THE ITEM FROM TOP OF STACK--------------------------
void
pop ()
{
  struct node *temp;
  temp = top;
  if (top == 0)
    {
      printf ("Stack is Empty\n");
    }
  else
    {
      temp = top;
      printf ("Deleted %d\n", temp->data);	// Print Data of Top i.e Pop item
      top = top->next;		// Top points to next node.
      free (temp);		// as address of popped item was saved in it.
    }
}

//---------------------FUNCTION TO DISPLAY THE STACK-------------------------
void
display ()
{
  struct node *temp;
  temp = top;
  if (top == 0)
    {
      printf ("Stack is Empty\n");
    }
  else
    {
      while (temp != NULL)
	{
	  printf ("%d\n", temp->data);	// Print Data of Top
	  temp = temp->next;	// Temp points to next node.
	}
    }
}

//--------------------FUNCTION TO DISPLAY TOP OF STACK-----------------
void
peek ()
{
  struct node *temp;
  temp = top;
  if (top == 0)
    {
      printf ("Stack is Empty.\n");
    }
  else
    {
      printf ("Top value is %d\n", temp->data);
    }
}
