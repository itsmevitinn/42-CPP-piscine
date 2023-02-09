NAME = overload

SRC = main.cpp Fixed.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

C++ = c++

all:		${NAME}

${NAME}:	${SRC}
			${C++} ${FLAGS} ${SRC} -o ${NAME}

fclean:
			${RM} ${NAME}

re: fclean all

.PHONY: fclean, all, re
