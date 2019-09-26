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

/**
* add_dnodeint_end - function that adds a new node at the end
* @head: doubly linked list
* @n: data of the node
* Return: the address of the new element
*/

void add_dnodeint_end(stack_t **head, unsigned int n)
{
	stack_t *last = (*head);
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	new_node->n = n;
	new_node->next = NULL;
	if ((*head) == NULL)
	{
		new_node->prev = NULL;
		(*head) = new_node;
	}
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	new_node->prev = last;
}

/**
* _rotl - rotates the stack to the top
* @stack: header
* @line_number: elements
*/

void _rotl(stack_t **stack, unsigned int line_number)
{
	unsigned int tmp;
	stack_t *current = *stack;

	tmp = current->n;
	_pop(stack, line_number);
	add_dnodeint_end(stack, tmp);
}
