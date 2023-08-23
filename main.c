#include "monty.h"
int main(int ac, char *args[])
{
	stack_t *stack = NULL;
	char *buffer_line = NULL;
	size_t length = 0;
	int line_num = 0, val;
	char *file_path = args[1], *opcode, *val_str;
	FILE *file = fopen(file_path, "r");

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s \n", file_path);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer_line, &length, file) != -1)
	{
		line_num++;
		opcode = strtok(buffer_line, " \t\n");
		if (opcode == NULL || strlen(opcode) == 0)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			val_str = strtok(NULL, " \t\n");
			if (val_str == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				free(buffer_line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			val = atoi(val_str);
			push(&stack, val);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s \n", line_num, opcode);
			free(buffer_line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free(buffer_line);
	fclose(file);

	return (0);
}
