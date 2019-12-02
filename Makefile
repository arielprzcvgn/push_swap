# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariperez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 14:43:48 by ariperez          #+#    #+#              #
#    Updated: 2019/11/14 18:37:14 by ariperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re main norme

NAME	=	push_swap

SRC_DIR =	./srcs
INC_DIR =	./includes
OBJ_DIR =	./objs
LIB_DIR	=	./libft

INC_NAME=	push_swap.h
SRC_NAME=	checker.c init.c operations.c visu.c
OBJ_NAME=	$(SRC_NAME:.c=.o)
LIB_NAME=	ft_strcmp.c ft_strlen.c ft_strclr.c
LIB_OBJ	=	$(LIB_NAME:.c=.o)

INC		=	$(addprefix $(INC_DIR)/, $(INC_NAME))
SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ		=	$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
LIB		=	$(addprefix $(LIB_DIR)/, $(LIB_NAME))
OBJLIB	=	$(addprefix $(OBJ_DIR)/, $(LIB_OBJ))

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC) $(LIB)
	@mv $(OBJ_NAME) $(LIB_OBJ) $(OBJ_DIR)
	@gcc -g $(OBJ) $(OBJLIB) -o checker
	@echo "\033[1;32mPush_swap and Checker are ready.\033[0m"

clean:
	@rm -f $(OBJ) $(OBJLIB)
	@echo "\033[1;31mObject files has been deleted.\033[0m"

fclean: clean
	@rm -f $(NAME) $(LIB_OBJ) $(OBJ_NAME)
	@rm -f test debug
	@echo "\033[1;31mPush_Swap has been deleted.\033[0m"

re: fclean all

main:
	@gcc $(NAME) main.c -o test
	@echo "Test main has been created."

debug:
	@gcc -g $(SRC) $(NAME) main.c -o debug
	@echo "lldb file has been created."
	@lldb ./debug

norme:
	@echo "\033[1;33mNorminette\033[0m"
	@norminette $(INC) $(LIB) $(SRC)
