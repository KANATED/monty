#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - Swaps top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swap_node(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - Adds  two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add_node(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void sub_node(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds  top two elements.
 * @stack: Pointer to a pointer pointing  top node of the stack.
 * @line_number: Interger representing  line number of of the opcode.
 */
void div_node(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_number, "div");

	if ((*stack)->n == 0)
		more_error(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
