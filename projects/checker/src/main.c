#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "checker.h"

bool  is_valid(char **argv) {
	int i = 0;
	int j = 0;

	while (argv[i] != NULL) {
		j = 0;
		while (argv[i][j] != '\0') {
			if (!isdigit(argv[i][j])) {
				return false;
			}
			j++;
		}
		i++;
	}
	return true;
}

int main(int argc, char **argv) {
	t_checker *program;
	int ret;

	if (argc > 1) {
		char **real_argv = &argv[1];
		if (is_valid(real_argv) && !is_dup(real_argv)) {
			program = new_checker(real_argv);
			if (program != NULL) {
				return checker_execute_instructions(program);
			};
		} else {
			fprintf(stderr, "Error\n");
		}
		return 1;
	}
	return 0;
}
