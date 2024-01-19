#include "monty.h"

#define RUN 0
#define STOP 1
#define BLANK " "
#define WIN 0
#define FAIL -1
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MAX_BUF_SIZE 1024

unsigned int line_num = 0;
char *current_line[MAX_BUF_SIZE];

/**
 * read_from_file - read the monty file line by line.
 * this will populate the stack as program runs, dep on command received.
 * @filename: the path of the file.
 * @instr_stack: the stack to hold them instructions
 * @fobj: pointer to FILE object
 * Return: nothing. will exit with proper status.
 */
void read_from_file(char *filename, stack_t *instr_stack, int file_dsc)
{
	int eval = RUN, exit_stat = FAIL;
	ssize_t bytes_read = -1, i;
	char linebuf[MAX_BUF_SIZE], **argv = NULL;
	void (*run_instr)(stack_t **, unsigned int);
	(void)filename;

/*
#include <fcntl.h>

    while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
        // Process the content of the buffer (which may contain multiple lines)
        // You can iterate through the buffer to find line breaks and process lines accordingly
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                // Process the line
                // ...
            }
        }
    }
*/
	while (bytes_read = read(fd, linebuf, sizeof(linebuf)) > 0)
	{

	}

	do {
		bytes_read = getline(&line, &line_length, fobj);
		if (bytes_read < 0)
		{
			if (feof(stdin))
				exit_stat = WIN;
			else
				exit_stat = FAIL;
			break;
		}
		line_num += 1;
		argv = make_tokens(line, BLANK);
		if (argv == NULL)
			continue;
		if (count_args(argv) > 0)
		{
			run_instr = get_instruction(argv[0]);
			if (run_instr == NULL)
			{
				fprintf(stderr, UNKNOWN, line_num, argv[0]);
				exit_stat = FAIL;
				eval = STOP;
			}
			else
				run_instr(&instr_stack, line_num);
		}
		free_table(argv);
	} while (eval == RUN);
	cleanup(line, argv);

	if (exit_stat == FAIL)
		exit(EXIT_FAILURE);
}

/*
#include <fcntl.h>

int main() {
    char buffer[MAX_LINE_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
        // Process the content of the buffer (which may contain multiple lines)
        // You can iterate through the buffer to find line breaks and process lines accordingly
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                // Process the line
                // ...
            }
        }
    }
*/
