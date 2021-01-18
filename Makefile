##
## EPITECH PROJECT, 2018
## Delivery
## File description:
## __DESCRIPTION__
##

SRC	=	main.c	\
		end.c	\
		sprite.c	\
		move.c	\
		car.c	\
		check.c

OBJ	=	$(SRC:.c=.o)

NAME =	my_runner

all:	$(NAME)

CFLAGS	=	-g

LDFLAGS += -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

$(NAME):	$(OBJ)
		ar rc libmy.a $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)
		@echo "\n_________---ce genre de \e[1;31m./$(NAME)\e[37m toi même tu sais---________\n"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libmy.a
	rm -f my.h

re: fclean	all
