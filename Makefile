##
## EPITECH PROJECT, 2024
## Pool
## File description:
## Makefile
##

SRC =	Main.cpp \
		AComponent.cpp

CC =     g++

CFLAGS = -Wall -Wextra

LIB_NAME =    string
LIB_FILE_NAME =    libstring.a

OBJ =    $(SRC:%.cpp=%.o)

NAME = nanotekspice

all:    $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@rm -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(LIB_FILE_NAME)
		@rm -f $(NAME)

re: fclean all
