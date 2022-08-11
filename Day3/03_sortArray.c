// 03. Program to sort the Stack using stack.

#include <stdio.h>
#include <stdlib.h>

//--------------Structure Declaration---------------------------
struct stack
{
  int data;
  struct stack *ptr;
};

//---------------FUNCTION PROTOTYPE------------------------------
void create (struct stack **);
int isEmpty (struct stack *);
void push (struct stack **, int);
int pop (struct stack **);
int top (struct stack *);
void sort_stack_and_insert (struct stack **, int data);
void sort_stack (struct stack **);
void display_stack (struct stack *);

//----------------MAIN FUNCTION------------------------------------
int
main (void)
{
  struct stack *top;		// Structure of Top pointer is created.
  create (&top);		// Call Create function to enter the elements to stack.

  int n, data;
  printf ("\nEnter the number of elements to be pushed to the stack : ");
  scanf ("%d", &n);

  printf ("\nInput the stack elements :\n");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &data);
      push (&top, data);	// Take input from user and update in stack by calling Push function.
    }
  printf ("\n");
  sort_stack (&top);		// Sort the values in stack by calling this function.
  printf ("Sorted Stack : ");
  display_stack (top);		// Display the sorted Stack
  return 0;
}

//----------------FUNCTION TO CREATE-------------------
void
create (struct stack **s)
{
  *s = NULL;			// Initialize the Stack by assigning Top = Null
}

//---------------FUNCTION TO CHECK STACK EMPTY OR NOT------------
int
isEmpty (struct stack *s)
{
  if (s == NULL)
    return 1;			// True
  return 0;			// False
}

//--------------FUNCTION TO ADD VALUE TO STACK----------------
void
push (struct stack **s, int data)
{
  struct stack *temp = (struct stack *) malloc (sizeof (*temp));	// Create a Temporary Pointer.
  if (temp == NULL)
    {
      return;
    }
  temp->data = data;
  temp->ptr = *s;
  *s = temp;
}

//-------------FUNCTION TO REMOVE VALUE FROM STACK----------------
int
pop (struct stack **s)
{
  int data;
  struct stack *temp;
  data = (*s)->data;
  temp = *s;
  (*s) = (*s)->ptr;
  free (temp);
  return data;
}

//-------------FUNCTION TO CHECK TOP VALUE OF STACK-----------
int
top (struct stack *s)
{
  return (s->data);
}

//------------FUNCTION TO SORT THE STACK AND INSERT THE VALUES TO IT------------
void
sort_stack_and_insert (struct stack **s, int data)
{
  if (isEmpty (*s) || data > top (*s))
    {
      push (s, data);
      return;
    }
  int temp = pop (s);
  sort_stack_and_insert (s, data);	// Recursion is used.
  push (s, temp);
}

//------------ FUNCTION TO SORT THE STACK-----------------------
void
sort_stack (struct stack **s)
{
  if (!isEmpty (*s))
    {
      int data = pop (s);
      sort_stack (s);		// Recursion
      sort_stack_and_insert (s, data);
    }
}

//----------- FUNCTION TO DISPLAY STACK-------------------------
void
display_stack (struct stack *s)
{
  while (s)
    {
      printf ("%d ", s->data);
      s = s->ptr;
    }
  printf ("\n");
}
