# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 12:58:09 by gdosch            #+#    #+#              #
#    Updated: 2025/11/28 14:07:13 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= base

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS			= Base.cpp A.cpp B.cpp C.cpp main.cpp

OBJS			= $(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
.SILENT:
