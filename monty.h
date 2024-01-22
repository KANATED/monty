#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_files(char *file_name);
int parse_lines(char *buffer, int line_number, int format);
void read_files(FILE *);
int length_chars(FILE *);
void find_funcs(char *, char *, int, int);

/*Stack operations*/
stack_t *create_nodes(int n);
void free_node(void);
void print_to_stack(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void print_to_top(stack_t **, unsigned int);
void pop_to_top(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void swap_node(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_node(stack_t **, unsigned int);
void sub_node(stack_t **, unsigned int);
void div_node(stack_t **, unsigned int);
void mul_node(stack_t **, unsigned int);
void mod_node(stack_t **, unsigned int);

/*String operations*/
void print_to_char(stack_t **, unsigned int);
void print_to_str(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);

/*Error hanlding*/
void _err(int error_code, ...);
void more_error(int error_code, ...);
void string_error(int error_code, ...);
void _rotr(stack_t **, unsigned int);

#endif
