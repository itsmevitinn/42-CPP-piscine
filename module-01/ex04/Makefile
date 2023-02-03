NAME = sedIsForLosers

SRC = main.cpp sedInfo.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

C++ = c++

all:		${NAME}

${NAME}:	${SRC}
			${C++} ${FLAGS} ${SRC} -o ${NAME}

fclean:
			${RM} ${NAME}

re: fclean all

test: ${NAME}
			./${NAME} invalid.txt meu visao
			./${NAME} invalid argc
			./${NAME} ratos.txt meu visao

.PHONY: fclean, all, re
