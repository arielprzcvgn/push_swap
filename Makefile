# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariperez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 14:43:48 by ariperez          #+#    #+#              #
#    Updated: 2020/01/06 19:17:46 by ariperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re main norme

NAMEPS	=	push_swap
NAMECHK	=	checker

SRC_DIR =	./srcs
INC_DIR =	./includes
LIB_DIR	=	./libft

INC_NAME=	push_swap.h get_next_line.h libftprintf.h
NAME_CHK=	checker.c
NAME_PS	=	push_swap.c algolot.c highlgofive.c 
NAME_SHA=	init.c operations.c visu.c ps_free.c
NAME_LIB=	ft_atoi.c ft_memcpy.c ft_putchar.c ft_strcmp.c ft_strnew.c speci_c.c speci_s.c\
			ft_bzero.c ft_memmove.c ft_putstr.c ft_strcpy.c ft_strsplit.c speci_d_i.c speci_u.c\
			ft_conv_base.c ft_memset.c ft_putstr_fd.c ft_strdup.c get_next_line.c speci_f.c speci_x.c\
			ft_itoa.c ft_power.c ft_strcat.c ft_strjoinfree.c pfparsing.c speci_o.c\
			ft_memalloc.c ft_printf.c ft_strclr.c ft_strlen.c pftools.c speci_p.c

INC		=	$(addprefix $(INC_DIR)/, $(INC_NAME))
SRC_CHK	=	$(addprefix $(SRC_DIR)/, $(NAME_CHK))
SRC_PS	=	$(addprefix $(SRC_DIR)/, $(NAME_PS))
SRC_SHA	=	$(addprefix $(SRC_DIR)/, $(NAME_SHA))
SRC_LIB	=	$(addprefix $(LIB_DIR)/, $(NAME_LIB))

OBJ_CHK	=	$(SRC_CHK:.c=.o)
OBJ_PS	=	$(SRC_PS:.c=.o)
OBJ_SHA=	$(SRC_SHA:.c=.o)
OBJ_LIB	=	$(SRC_LIB:.c=.o)

#O_CHK	=	$(NAME_CHK.c=.o)
#O_PS	=	$(NAME_PS:.c=.o)
#O_SHARED=	$(NAME_SHA:.c=.o)
#LIB_OBJ	=	$(NAME_LIB:.c=.o)

#OBJ_CHK	=	$(addprefix $(OBJ_DIR)/, $(O_CHK))
#OBJ_PS	=	$(addprefix $(OBJ_DIR)/, $(O_PS))
#OBJ_SHA	=	$(addprefix $(OBJ_DIR)/, $(O_SHARED))
#OBJLIB	=	$(addprefix $(OBJ_DIR)/, $(LIB_OBJ))

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

all: $(NAMECHK) $(NAMEPS)

$(NAMECHK): $(OBJ_LIB) $(OBJ_SHA) $(OBJ_CHK)
	@$(CC) $(FLAGS) $(OBJ_CHK) $(OBJ_SHA) $(OBJ_LIB) -o $(NAMECHK)
	@echo "\033[1;32mChecker is ready.\033[0m"

$(NAMEPS): $(OBJ_LIB) $(OBJ_SHA) $(OBJ_PS)
	@$(CC) $(FLAGS) $(OBJ_PS) $(OBJ_SHA) $(OBJ_LIB) -o $(NAMEPS)
	@echo "\033[1;32mPush_swap is ready.\033[0m"

clean:
	@rm -f $(OBJ_CHK) $(OBJ_PS) $(OBJ_LIB) $(OBJ_SHA)
	@echo "\033[1;31mObject files has been deleted.\033[0m"

fclean: clean
	@rm -f $(NAMEPS) $(NAMECHK)
	@rm -f debugchk debugps
	@echo "\033[1;31mPush_Swap and Checker has been deleted.\033[0m"

re: fclean all

norme:
	@echo "\033[1;33mNorminette\033[0m"
	@norminette $(INC) $(SRC_LIB) $(SRC_CHK) $(SRC_PS) $(SRC_SHA)

debugps:
	@$(CC) -g $(FLAGS) $(SRC_PS) $(SRC_LIB) -o debugps
	@echo "\033[1;32mPush_swap debug is ready.\033[0m"

debugchk:
	@$(CC) -g $(FLAGS) $(SRC_CHK) $(SRC_LIB) -o debugchk
	@echo "\033[1;32mChecker debug is ready.\033[0m"