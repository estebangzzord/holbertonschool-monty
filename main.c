#include "monty.h"

/**
 *main - reads Monty byte codes
 *@argc: the count of arguments in the command line
 *
 *@argv: pointer to pointer of arguments on the command line
 *
 *Return: either EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
FILE *file;
char *line = NULL, *opcode;
size_t len = 0;
ssize_t read;
unsigned int line_number = 1;
stack_t *stack = NULL;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}
read = getline(&line, &len, file);
while (read != -1)
{
opcode = strtok(line, " \t\n");
if (opcode == NULL)
{
line_number = line_number + 1;
read = getline(&line, &len, file);
continue;
}
find_opcode(opcode, &stack, line_number);
read = getline(&line, &len, file);
line_number = line_number + 1;
}
free(line);
free_stack(stack);
fclose(file);
return (EXIT_SUCCESS);
}
