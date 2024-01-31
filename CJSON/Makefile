##
## EPITECH PROJECT, 2023
## B-PSU-100-BDX-1-1-myls-tom.seng
## File description:
## Makefile
##

##

CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c99

SRC =	lib/get_file_content.c	\
	lib/select_str.c	\
	lib/my_strlen.c	\
	lib/insert_in_str.c	\
	lib/my_realloc_str.c	\
	lib/my_strcmp.c	\
	lib/my_strdup.c	\
	lib/remove_substr.c	\
	src/JSON/GET/JSON_get_from_key.c	\
	src/JSON/GET/JSON_get_from_keys.c	\
	src/JSON/UPDATE/JSON_update_from_key.c	\

OBJ = $(SRC:.c = .o)

NAME = libJSON.a

all : $(NAME)

re : clean all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	rm -f *.o a.out

clean :
	rm -f $(NAME) *.o unit_test *.gcno *.gcda *.gcov

fclean :
	rm -f $(NAME) *.o unit_test *.gcno *.gcda *.gcov

libclean :
	rm -f *.o

debug : $(OBJ)
	$(CC) -g $(LIB) $(CFLAGS) -o $(NAME) $(SRC)


unit_tests : $(OBJ)
	gcc -lcriterion -coverage -o unit_test $(TEST)

