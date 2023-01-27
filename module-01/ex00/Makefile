NAME = plantVsZombie

SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

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
