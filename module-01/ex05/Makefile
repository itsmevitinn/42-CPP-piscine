NAME = harl

SRC = main.cpp Harl.cpp

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
			./${NAME} DEBUG
			./${NAME} INFO
			./${NAME} WARNING
			./${NAME} ERROR
			./${NAME} INVALID
			./${NAME} MANY ARGC

.PHONY: fclean, all, re
