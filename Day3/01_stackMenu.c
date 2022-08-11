//01. Write a menu driven program for stack implementation.

#include<stdio.h>
#include<stdlib.h>
#define MAX 5			// MAXIMUM ARRAY SIZE is 5

//---------------FUNCTION DECLARATION---------------------
int is_empty ();
int is_full ();
void push ();
void pop ();
void Top_value ();
void pr_stack ();

int a[MAX];			// Declaring values of top and array globally.
int top = 0;

//--------------- MAIN FUNCTION-----------------------
int
main ()
{
  int op;
  while (op != 5)
    {
      printf
	("-------------------------------------------------------------------\n");
      printf ("1. PUSH\n2. POP\n3. Display Top\n4. Display Stack\n5. Exit\n");
      printf ("Enter the choice[1-5]: ");
      scanf ("%d", &op);
      switch (op)
	{
	case 1:
	  push ();
	  break;
	case 2:
	  pop ();
	  break;
	case 3:
	  Top_value ();
	  break;
	case 4:
	  pr_stack ();
	  break;
	case 5:
	  exit (0);
	default:
	  printf ("Invalid value.\n");
	}
    }
  return 0;
}

//------------------ FUNCTION TO CHECK STACK IS EMPTY OR NOT----------------------
int
is_empty ()
{
  if (top == -1)		// Return "True" if stack is empty.
    return 1;
  else
    return 0;
}

//------------------FUNCTION TO CHECK STACK IS FULL OR NOT------------------------
int
is_full ()
{
  if (top == MAX)		// Return "True" if stack is full.
    return 1;
  else
    return 0;
}

//----------------- FUNCTION TO ADD AN ELEMENT IN STACK--------------------------
void
push ()
{
  int x;

  if (!is_full ())		// If Stack is not full then enter the value to a[++top] location.
    {
      printf ("PUSH : ");
      scanf ("%d", &x);		// Input the number to be Pushed on to the Stack.
      a[++top] = x;
    }
  else
    printf ("ERROR: OVERFLOW OCCURS!!\n");

}

//----------------- FUNCTION TO DELETE AN ELEMENT FROM STACK---------------------
void
pop ()
{
  int pop_value;
  if (!is_empty ())
    {
      pop_value = a[top];	// To check which value is popped from Stack.
      printf ("Deleted %d\n", pop_value);
      top--;
    }
  else
    printf ("Stack is Already Empty.\n");

}

//----------------- FUNCTION TO CHECK TOP OF STACK------------------------------
void
Top_value ()
{
  printf ("Value of Top is %d\n", a[top]);
}

//---------------- FUNCTION TO DISPLAY STACK VALUES-----------------------------
void
pr_stack ()
{
  printf ("Entered Values of Stack are: \n");
  for (int i = 1; i <= top; i++)
    {
      printf ("a[%d]: %d\n", i, a[i]);
    }
  printf ("\n");
}
