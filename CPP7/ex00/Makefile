# Variables
.SILENT:

NAME		= Operation
OBJDIR		= .obj

SRC			= main.cpp

OBJ			= ${SRC:%.cpp=${OBJDIR}/%.o}

# Compiler
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Rules
all: 		${NAME}
			echo "Project up to date"

${NAME}:	${OBJ}
			${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}
			echo "Build done"

${OBJDIR}/%.o: %.cpp
			mkdir -p ${OBJDIR}
			${CXX} ${CXXFLAGS} -c $< -o $@

clean:
			rm -rf ${OBJDIR}
			echo "clean done"

fclean:		clean
			rm -f ${NAME}
			echo "fclean done"

re:			fclean all

.PHONY:		all clean fclean re
