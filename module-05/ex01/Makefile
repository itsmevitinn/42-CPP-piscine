NAME = maggots

INCLUDES = includes

FUNCS = main.cpp Bureaucrat.cpp Form.cpp

SRC = $(addprefix src/, $(FUNCS))

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

C++ = c++

all:		${NAME}

${NAME}:	${SRC}
			${C++} ${FLAGS} ${SRC} -o ${NAME} -I $(INCLUDES)

fclean:
			${RM} ${NAME}

re: fclean all

.PHONY: fclean, all, re
