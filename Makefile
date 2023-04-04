CC := clang
CFLAGS := -Wall -Wextra -Werror -g
DEBUG := -g
CHECKER_DIR = ./checker_program
PUSH_SWAP_DIR = ./push_swap_program
LIBFT_DIR := ./libft

all: lft checker push_swap

lft:
	@cd $(LIBFT_DIR) && $(MAKE)

checker:
	@cd $(CHECKER_DIR) && $(MAKE)
	@cp -f $(CHECKER_DIR)/checker .

push_swap:
	@cd $(PUSH_SWAP_DIR) && $(MAKE)
	@cp -f $(PUSH_SWAP_DIR)/push_swap .

clean:
	@cd $(LIBFT_DIR) && $(MAKE) -s clean
	@cd $(CHECKER_DIR) && $(MAKE) -s clean
	@cd $(PUSH_SWAP_DIR) && $(MAKE) -s clean

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) -s fclean
	@cd $(CHECKER_DIR) && $(MAKE) -s fclean
	@cd $(PUSH_SWAP_DIR) && $(MAKE) -s fclean
	@rm -Rf checker
	@rm -Rf push_swap

re: fclean all

.PHONY: all lft checker push_swap clean fclean re