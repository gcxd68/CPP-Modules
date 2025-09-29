# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/20 18:08:53 by gdosch            #+#    #+#              #
#    Updated: 2025/09/20 18:08:53 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			megaphone

CXX =			c++
CXXFLAGS =		-Wall -Wextra -Werror -std=c++98

SRCS =			megaphone.cpp

OBJS =			$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
