#include "objs/checker/checker.h"
#include <stdio.h>
#include "helpers/helpers.h"

int main(int argc, char **argv) {
	t_checker *checker;
	int ret;

	ret = 0;
	if (argc > 1) {
		// checker = new_checker(argc - 1, &argv[1]);

		checker = new_checker(6, get_numbers_helper());
		if (checker) {
			ret = checker_execute_instructions(checker);
			checker_destructor(checker);
		} else {
			ret = 1;
		}
	}
	return ret;
}
