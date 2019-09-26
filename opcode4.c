#include "monty.h"

/**
 * _pstr - Print all the elements with ASCII in the stack.
 * @stack: Stack.
 * @line_number: Line number.
 * Return: void.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		/*printf("%d\n", current->n);*/
		if (current->n < 32 || current->n > 126)
		{
			putchar('\n');
			return;
		}
		else
			putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
