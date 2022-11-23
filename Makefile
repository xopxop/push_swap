CC := clang
CFLAGS := -Wall -Wextra -Werror
DEBUG := -g
CHECKER_DIR = ./checker_program
LIBFT_DIR := ./libft

all: lft checker

lft:
	@cd $(LIBFT_DIR) && $(MAKE)

checker:
	@cd $(CHECKER_DIR) && $(MAKE)
	@cp -f $(CHECKER_DIR)/checker .

clean:
	@cd $(LIBFT_DIR) && $(MAKE) -s clean
	@cd $(CHECKER_DIR) && $(MAKE) -s clean

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) -s fclean
	@cd $(CHECKER_DIR) && $(MAKE) -s fclean
	@rm -Rf checker

re: fclean all

.PHONY: all lft checker clean fclean re