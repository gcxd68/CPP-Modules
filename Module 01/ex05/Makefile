# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 18:38:21 by gdosch            #+#    #+#              #
#    Updated: 2025/10/28 18:38:22 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			harl

CXX =			c++
CXXFLAGS =		-Wall -Wextra -Werror -std=c++98

SRCS =			main.cpp Harl.cpp
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
