# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aindjare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 15:37:18 by aindjare          #+#    #+#              #
#    Updated: 2025/03/13 10:04:51 by aindjare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			:=	g++
CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror -g
NAME		:=	orthodoxful
SOURCES		:=	$(wildcard *.cpp)
OBJECTS		:=	$(SOURCES:%.cpp=%.o)

CC			:=	$(CXX)
CFLAGS		:=	$(CXXFLAGS)

all:	 $(NAME)

$(NAME): $(OBJECTS)

fclean:	 clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS)

re:		 fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJECTS)
