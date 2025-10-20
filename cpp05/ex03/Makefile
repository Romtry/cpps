NAME=	a.out

VPATH=

SRC=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp\


OFILES= ${SRC:%.cpp=obj/%.o}

CC= 	c++ -Wextra -Wall -Werror -std=c++98
CFLAGS= -g3
RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m

ORANGE = \033[38;5;216m
DARKBLUE = \033[38;5;21m
LIGHT_RED = \033[38;5;196m
RED = \033[38;5;130m
DARK_RED = \033[38;5;88m
GREEN = \033[38;5;85m

#change value with number of src files !
NBR_TOT_FICHIER = $(words ${SRC})

FICH_COUNT = 0
NBR_COMPILER = ${shell expr 100 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
BAR =  ${shell expr 23 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
REST = ${shell expr 23 - ${BAR}}

all:	${NAME}

${NAME}:		${OFILES}
	   @${CC} ${CFLAGS} ${OFILES} -o ${NAME}
	@echo "${GREEN}[✓] - ${_GREEN}${NAME}${GREEN} Successfully Compiled!${RESET}"


obj/%.o:%.cpp
	@mkdir -p obj/$(dir $<)
	@${eval FICH_COUNT = ${shell expr ${FICH_COUNT} + 1}}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -rf obj
	@rm -f ${NAME}.log

fclean:	clean
	@rm -f ${NAME}
	@${RM} ${NAME}

re:	fclean all

.PHONY:		all bonus clean fclean re
