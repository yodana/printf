NAME = libftprintf.a

SRC = ft_printf.c ft_calc.c ft_conv_char.c ft_lst.c ft_conv.c ft_conv_f.c \
	ft_calc_bi.c ft_calc_exposant.c ft_conv_spe.c norme.c ft_attribut.c \
	ft_check.c ft_prec_champ.c ft_conv_e.c ft_conv_b.c ft_calc_float.c

HEADER = printf.h

BIN_FOLDER = ./bin/

YELLOW = \033[0;33m

GREEN = \033[0;32m

END_COLOR = \033[0m

OBJ = $(addprefix $(BIN_FOLDER),$(SRC:.c=.o))

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bin:
	@mkdir bin

$(NAME): bin $(OBJ)
		@make -C libft
		@cp libft/libft.a $(NAME)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@printf "$(GREEN)Compilation finish $(END_COLOR)"

$(BIN_FOLDER)%.o :%.c
	@gcc $< -c -I $(HEADER) -o $@ -Wall -Wextra -Werror -g

clean :
	@make clean -C libft
	@rm -rf $(BIN_FOLDER)
	@printf "$(GREEN)Clean done $(END_COLOR)\n"

fclean : clean 
	@make fclean -C libft
	@rm -rf $(NAME)
	@printf "$(GREEN)Fclean done $(END_COLOR)\n"

re : fclean all

.PHONY : all clean fclean re
