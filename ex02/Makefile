# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 23:11:37 by hugo-mar          #+#    #+#              #
#    Updated: 2025/07/30 11:09:27 by hugo-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = executor

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS_PATH = ./srcs/

SRCS = $(SRCS_PATH)Bureaucrat.cpp \
	   $(SRCS_PATH)AForm.cpp \
	   $(SRCS_PATH)ShrubberyCreationForm.cpp \
	   $(SRCS_PATH)RobotomyRequestForm.cpp \
	   $(SRCS_PATH)PresidentialPardonForm.cpp \
	   $(SRCS_PATH)main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(ARCHIVE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re