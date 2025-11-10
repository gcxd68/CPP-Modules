# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 11:13:22 by gdosch            #+#    #+#              #
#    Updated: 2025/11/10 13:57:41 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fragtrap

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
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
