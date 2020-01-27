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
OBJ_DIR =	./objs
LIB_DIR	=	./libft

INC_NAME=	push_swap.h get_next_line.h libftprintf.h
S_CHK	=	checker.c init.c operations.c visu.c
S_PS	=	push_swap.c init.c operations.c visu.c algolot.c
O_CHK	=	$(S_CHK:.c=.o)
O_PS	=	$(S_PS:.c=.o)
LIB_NAME=	ft_atoi.c ft_memcpy.c ft_putchar.c ft_strcmp.c ft_strnew.c speci_c.c speci_s.c\
			ft_bzero.c ft_memmove.c ft_putstr.c ft_strcpy.c ft_strsplit.c speci_d_i.c speci_u.c\
			ft_conv_base.c ft_memset.c ft_putstr_fd.c ft_strdup.c get_next_line.c speci_f.c speci_x.c\
			ft_itoa.c ft_power.c ft_strcat.c ft_strjoinfree.c pfparsing.c speci_o.c\
			ft_memalloc.c ft_printf.c ft_strclr.c ft_strlen.c pftools.c speci_p.c
LIB_OBJ	=	$(LIB_NAME:.c=.o)

INC		=	$(addprefix $(INC_DIR)/, $(INC_NAME))
SRC_CHK	=	$(addprefix $(SRC_DIR)/, $(S_CHK))
SRC_PS	=	$(addprefix $(SRC_DIR)/, $(S_PS))
OBJ_CHK	=	$(addprefix $(OBJ_DIR)/, $(O_CHK))
OBJ_PS	=	$(addprefix $(OBJ_DIR)/, $(O_PS))
LIB		=	$(addprefix $(LIB_DIR)/, $(LIB_NAME))
OBJLIB	=	$(addprefix $(OBJ_DIR)/, $(LIB_OBJ))

FLAGS	=	-Wall -Wextra -Werror

all: $(NAMEPS)

$(NAMEPS):
	@gcc -c $(FLAGS) $(SRC_CHK) $(LIB)
	@mv $(O_CHK) $(LIB_OBJ) $(OBJ_DIR)
	@gcc $(OBJ_CHK) $(OBJLIB) -o $(NAMECHK)
	@echo "\033[1;32mChecker is ready.\033[0m"
	@gcc -c $(FLAGS) $(SRC_PS) $(LIB)
	@mv  $(O_PS) $(LIB_OBJ) $(OBJ_DIR)
	@gcc $(OBJ_PS) $(OBJLIB) -o $(NAMEPS)
	@echo "\033[1;32mPush_swap is ready.\033[0m"

clean:
	@rm -f $(OBJ_CHK) $(OBJ_PS) $(OBJLIB)
	@echo "\033[1;31mObject files has been deleted.\033[0m"

fclean: clean
	@rm -f $(NAMEPS) $(NAMECHK)
	@rm -f debugchk debugps
	@echo "\033[1;31mPush_Swap and Checker has been deleted.\033[0m"

re: fclean all

norme:
	@echo "\033[1;33mNorminette\033[0m"
	@norminette $(INC) $(LIB) $(SRC_CHK) $(SRC_PS)

debugps:
	@gcc -g $(FLAGS) $(SRC_PS) $(LIB) -o debugps
	@echo "\033[1;32mPush_swap debug is ready.\033[0m"

debugchk:
	@gcc -g $(FLAGS) $(SRC_CHK) $(LIB) -o debugchk
	@echo "\033[1;32mChecker debug is ready.\033[0m"