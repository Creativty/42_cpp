# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aindjare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 15:37:18 by aindjare          #+#    #+#              #
#    Updated: 2025/01/01 09:22:33 by aindjare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			:=	c++
CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror -g
NAME		:=	ClapTrap
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
