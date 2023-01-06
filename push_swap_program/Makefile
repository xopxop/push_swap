CC := clang
CFLAGS := -Wall -Wextra -Werror
DEBUG := -g
PROGRAM = push_swap
SOURCES_DIR:= ./src
SOURCES_FILES := $(shell find $(SOURCES_DIR) -name '*.c')
BUILD_DIR := ./build
MATCHING_RULE := $(addprefix $(BUILD_DIR)/,$(SOURCES_FILES:%.c=%.o))
LIBFT_DIR := ../libft
LIB := -L$(LIBFT_DIR)/ -lft
SHARED_DIR := ../shared-objs
SHARED_FILES := $(shell find $(SHARED_DIR) -name '*.c')
MATCHING_RULE_SHARED_FILE := $(addprefix $(BUILD_DIR)/,$(SHARED_FILES:%.c=%.o))
SHARED_LIB_DIR := ../shared-lib
SHARED_LIB_FILES := $(shell find $(SHARED_LIB_DIR) -name '*.c')
MATCHING_RULE_SHARED_LIB_FILE := $(addprefix $(BUILD_DIR)/,$(SHARED_LIB_FILES:%.c=%.o))

all: mkdirs $(PROGRAM)
	@echo "$(PROGRAM) created"

mkdirs:
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)/$(notdir $@)

$(PROGRAM): $(MATCHING_RULE) $(MATCHING_RULE_SHARED_FILE) $(MATCHING_RULE_SHARED_LIB_FILE)
	$(CC) $(CFLAGS) $(shell find $(BUILD_DIR) -name '*.o') $(LIB) -o $@
	
clean:
	rm -Rf $(BUILD_DIR)

fclean: clean
	rm -Rf $(PROGRAM)

re: fclean all

.PHONY: all mkdirs clean fclean re