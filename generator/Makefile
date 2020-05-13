##
## EPITECH PROJECT, 2018
## makefile
## File description:
## make a file
##

NAME	= generator

SRCS	= 	src/generator.c	\
			src/my_putchar.c	\
			src/my_putstr.c	\
			src/create_path.c	\
			src/my_strlen.c	\
			src/decrypt_neighbor.c	\
			src/map.c	\
			src/stack.c

MAIN	=	src/main.c

TEST	=	tests/test_bistro.c

OBJS	= $(SRCS:.c=.o)

MOBJS	= $(MAIN:.c=.o)

CFLAGS = -Iinclude/ -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS) $(MOBJS)
	 gcc $(OBJS) $(MOBJS) -o $(NAME) $(CFLAGS)

tests_run: $(OBJS) $(MOBJS)
	gcc -o unit_tests $(CFLAGS) $(SRCS) $(TEST) -lcriterion
	./unit_tests

val_run: $(OBJS)
	gcc -g $(OBJS) $(MOBJS) -o $(NAME) $(CFLAGS)

clean:
	rm -rf $(OBJS)
	rm -rf $(MOBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf ./unit_tests

re: fclean all

.PHONY: all clean fclean re
