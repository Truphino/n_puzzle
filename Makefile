# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.2                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trecomps <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 08:26:49 by trecomps          #+#    #+#              #
#    Updated: 2018/05/07 09:56:45 by trecomps         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp\
		Heuristics.class.cpp\
		AStar.class.cpp\
		Grid.class.cpp\
		Node.class.cpp\
		NpuzzleSolver.class.cpp

INC = AStar.class.hpp\
		Grid.class.hpp\
		Heuristic.class.hpp\
		Node.class.hpp\
		NpuzzleSolver.class.hpp

OBJ = $(SRC:.cpp=.o)

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
INC_FILES = $(addprefix $(INC_DIR)/, $(INC))
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJ))
DEPENDS = $(OBJ_FILES:.o=.d)

NAME = n_puzzle
FLAGS = -Wall -Wextra -Werror -MMD

.PHONY: all, clean, fclean, re

$(NAME) : $(OBJ_FILES)
	g++ $(FLAGS) -o $(NAME) $(OBJ_FILES)

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	g++ $(FLAGS) -c -I$(INC_DIR) $< -o $@

-include $(DEPENDS)

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
