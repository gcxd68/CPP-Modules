# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 12:58:09 by gdosch            #+#    #+#              #
#    Updated: 2025/12/19 10:39:59 by gdosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= btc

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS			= BitcoinExchange.cpp main.cpp

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
