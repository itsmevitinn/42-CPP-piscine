NAME = internship

INCLUDES = includes

FUNCS = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

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
