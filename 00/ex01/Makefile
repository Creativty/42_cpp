# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aindjare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 18:49:55 by aindjare          #+#    #+#              #
#    Updated: 2024/12/21 19:15:36 by aindjare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			:=	g++
CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror -g
NAME		:= book
SOURCES		:= $(wildcard *.cpp)
OBJECTS		:=	$(SOURCES:%.cpp=%.o)

all:	 $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) -o $(NAME) $(OBJECTS)

fclean:	 clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS)

re:		 fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJECTS)
