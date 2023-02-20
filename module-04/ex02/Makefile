NAME = abstract

FUNCS = main.cpp Cat.cpp Dog.cpp DeadAnimal.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

SRC = $(addprefix src/, $(FUNCS))

FLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = ./includes

RM = rm -rf

C++ = c++

all:		${NAME}

${NAME}:	${SRC}
			${C++} ${FLAGS} ${SRC} -I ${INCLUDES} -o ${NAME}

fclean:
			${RM} ${NAME}

re: fclean all

.PHONY: fclean, all, re
