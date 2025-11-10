# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 11:13:22 by gdosch            #+#    #+#              #
#    Updated: 2025/11/10 14:02:57 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= diamondtrap

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -Wno-shadow

SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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
