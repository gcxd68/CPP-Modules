# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 13:50:20 by gdosch            #+#    #+#              #
#    Updated: 2025/09/30 13:50:21 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			violence

CXX =			c++
CXXFLAGS =		-Wall -Wextra -Werror -std=c++98

SRCS =			main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS =			$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
