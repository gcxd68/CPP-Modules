# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 12:58:09 by gdosch            #+#    #+#              #
#    Updated: 2025/11/20 11:54:28 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= form

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS			= main.cpp Bureaucrat.cpp Form.cpp
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
