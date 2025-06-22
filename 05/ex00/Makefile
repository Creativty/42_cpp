# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aindjare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 16:08:33 by aindjare          #+#    #+#              #
#    Updated: 2025/06/22 16:16:40 by aindjare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:=	c++
CXX			:=	c++
CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Wconversion -Werror -g

NAME		:=	bin
SOURCES		:=	$(wildcard *.cpp)
OBJECTS		:=	$(SOURCES:.cpp=.o)

all:		$(NAME)
clean:
	$(RM) $(OBJECTS)
fclean:		clean
	$(RM)	$(NAME)
re:			fclean all

$(NAME):	$(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@	$^

.PHONY:	all clean fclean re
.SECONDARY:	$(OBJECTS)
