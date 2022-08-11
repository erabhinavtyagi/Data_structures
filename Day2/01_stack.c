// Implement Stack Using Array.
// Operations - push, pop, top, IsEmpty, IsFULL, Overflow, print


#include<stdio.h>
#include<stdlib.h>
#define MAX 5			// MAXIMUM ARRAY SIZE is 5

int a[MAX];			// Declaring values of top and array globally.
int top = 0;

// FUNCTION IS_EMPTY
int
is_empty ()
{
  if (top == -1)		// Return true if stack is empty.
    return 1;
  else
    return 0;
}

//FUNCTION IS_FULL
int
is_full ()
{
  if (top == MAX)		// Return true if stack is full.
    return 1;
  else
    return 0;
}

// FUNCTION PUSH
int
push ()
{
  int x;
  printf ("PUSH : ");
  scanf ("%d", &x);			// Input the number to be Pushed on to the Stack.

  if (!is_full ())			// If Stack is not full then enter the value to a[++top] location.
    {
      a[++top] = x;
    }
  else
    printf ("Overflow Occurs.");
}

// FUNCTION POP
int
pop ()
{
  int pop_value;
  pop_value = a[top];			// To check which value is popped from Stack.
  top--;
  return pop_value;
}

// FUNCTION TOP
int
Top_value (int c)			
{
  return a[top];			// Return the value of top. 
}

// Print the current values of Stack
int
pr_stack ()
{
  for (int i = 0; i <= top; i++)
    printf ("a[%d]: %d\n", i, a[i]);
}

// MAIN FUNCTION
int
main ()
{
  printf ("Enter the Values:\n");
  push ();
  push ();
  push ();
  printf ("AFTER PUSH OPERATION: \n");
  pr_stack ();

  if (!is_empty ())				// print the value of Popped item is the stack is not empty otherwise give error.
    {
      int removed = pop ();
      printf ("Removed Value is: %d\n", removed);
    }

  printf ("AFTER POP OPERATION: \n");
  pr_stack ();
  printf ("\n");
}
