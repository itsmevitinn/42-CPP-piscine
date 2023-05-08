NAME = RPN

SRCS = main.cpp RPN.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

C++ = c++

OBJS = $(SRCS:.cpp=.o)

%.o:	%.cpp
			${C++} ${FLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
					${C++} ${FLAGS} ${OBJS} -o ${NAME}

clean:
				${RM} ${OBJS}

fclean:	clean
				${RM} ${NAME}

re: fclean all

.PHONY: clean, fclean, all, re
