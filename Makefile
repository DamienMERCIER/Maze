##
## EPITECH PROJECT, 2018
## makefile
## File description:
## make a file
##

all:
	make -C generator/

clean:
	make clean -s -C generator/

fclean:		clean
	make fclean -s -C generator/
	rm -rf generator/generator
	rm -rf generator/*.o

re:	fclean all

.PHONY:	all
