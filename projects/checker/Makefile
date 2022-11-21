CC := clang
CFLAGS := -Wall -Wextra -Werror
DEBUG := -g
PROGRAM_NAME = checker
SOURCES_DIR:= ./src
SOURCES := $(shell find $(SOURCES_DIR) -name '*.c')
OBJECT_FILES := main.o checker.o node.o stack.o helpers.o

# %.o : %.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

tell:
	echo $(SOURCES)

all:
	$(CC) $(CFLAGS) -c $(FILES)
	$(CC) main.o checker.o node.o stack.o helpers.o -o $(PROGRAM_NAME)

clean:
	rm -Rf $(PROGRAM_NAME)
	rm -Rf *.o

# $(OBJECT_FILES):

# $(PROGRAM): $(CC) $(CFLAGS) 

# all:

# clean:

# fclean:

# re: fclean all