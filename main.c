#include "monty.h"
stack_t *head = NULL;

/**
 * main  entry pointof the programm
 * @argc: argument count
 * @argv: lists of argument
 * Return: always 0 upon conclusion
 * clap for yourself if you understand
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_files(argv[1]);
	free_node();
	return (0);
}

/**
 * create_node - Creates nodes.
 * @n: Numbers to go into nodes.
 * Return: Upon sucess a pointer to the node. 
 * Otherwise NULL.
 */
stack_t *create_nodes(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		_err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_node - Frees node in  stack.
 */
void free_node(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_queue - Adds a node to queue.
 * @new_nodes: Pointer to new node.
 * @ln: line number of opcode.
 */
void add_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
