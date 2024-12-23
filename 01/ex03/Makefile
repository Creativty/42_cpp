# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aindjare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 13:26:09 by aindjare          #+#    #+#              #
#    Updated: 2024/12/23 13:30:28 by aindjare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			:=	g++
CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror -g
NAME		:=	violenz
SOURCES		:=	$(wildcard *.cpp)
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
