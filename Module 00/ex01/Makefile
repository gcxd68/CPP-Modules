# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/20 18:22:53 by gdosch            #+#    #+#              #
#    Updated: 2025/09/21 14:01:13 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			main.cpp \
				contact.cpp \
				phonebook.cpp

OBJS =			$(SRCS:.cpp=.o)

NAME =			phonebook
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
