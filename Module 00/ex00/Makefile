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

SRCS =			megaphone.cpp

OBJS =			$(SRCS:.cpp=.o)

NAME =			megaphone
CXX =			c++
CXXFLAGS =		-Wall -Wextra -Werror #-std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
