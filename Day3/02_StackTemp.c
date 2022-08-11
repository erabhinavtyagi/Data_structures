//02. Write a program to Sort a stack using a temporary stack

#include <stdio.h>
#include <stdlib.h>

void
sortStack (int input[], int size)
{
  int tmpStack[size];
  int top = -1;

  while (size >= 0)
    {
      int tmp = input[size];
      size--;
      while (top >= 0 && tmpStack[top] < tmp)	// while temporary stack is not empty and top of stack is greater than temp 
	{
	  input[++size] = tmpStack[top];	// pop from temporary stack and push it to the input stack 
	  top--;
	}

      tmpStack[++top] = (tmp);	// push temp in tempory of stack 
    }

  while (top >= 0)
    {
      printf ("%d ", tmpStack[top]);
      top--;
    }
}


int
main ()
{
  int n, x;
  printf ("Enter the number of elements to be pushed into stack:");
  scanf ("%d", &n);

  int input[n];
  int top = -1;
  printf ("Enter the stack elements:\n");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &x);
      input[++top] = x;
    }

  printf("Sorted Stack is:\n");
  sortStack (input, top);
  printf ("\n");
  return 0;
}
