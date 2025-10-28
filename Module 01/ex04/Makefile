# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 09:03:30 by gdosch            #+#    #+#              #
#    Updated: 2025/10/28 09:03:30 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			replace

CXX =			c++
CXXFLAGS =		-Wall -Wextra -Werror -std=c++98

SRCS =			main.cpp
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
