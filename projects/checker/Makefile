CC := clang
CFLAGS := -Wall -Wextra -Werror
DEBUG := -g
PROGRAM = checker
SOURCES_DIR:= ./src
SOURCES_FILES := $(shell find $(SOURCES_DIR) -name '*.c')
BUILD_DIR := ./build
MATCHING_RULE := $(addprefix $(BUILD_DIR)/,$(SOURCES_FILES:%.c=%.o))

all: mkdirs $(PROGRAM)
	@echo "$(PROGRAM) created"

mkdirs:
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)/$(notdir $@)

$(PROGRAM): $(MATCHING_RULE)
	$(CC) $(CFLAGS) $(shell find $(BUILD_DIR) -name '*.o') -o $@
	
clean:
	rm -Rf $(BUILD_DIR)

fclean: clean
	rm -Rf $(PROGRAM)

re: fclean all

.PHONY: all mkdirs clean fclean re