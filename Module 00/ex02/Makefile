# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/21 15:03:36 by gdosch            #+#    #+#              #
#    Updated: 2025/09/21 15:25:32 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			account

CXX =			c++
CXXFLAGS =		-Wall -Wextra -Werror -std=c++98

SRCS =			tests.cpp \
				Account.cpp

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
