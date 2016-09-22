
NAME = libftprintf.a

CC = gcc

FLAG = -Wall -Wextra -Werror

INC_PATH = ./inc/

SRC_PATH = ./src/

SRC_NAME = ft_printf \
			is_flag \
			loop_primary \
			print_precision \
			valid_arg \
			valid_opt \
			valid_flag \
			valid_convert \
			valid_precision \
			error_convert \
			add_flag \
			print_zero \
			not_option \
			init_var \
			bufferisation \
			\
			lib/ft_atoi \
			lib/ft_isdigit \
			lib/ft_itoa \
			lib/ft_memset \
			lib/ft_numlen \
			lib/ft_numtoa \
			lib/ft_put_str \
			lib/ft_strcmp \
			lib/ft_strdel \
			lib/ft_strlen \
			lib/ft_strrev \
			lib/ft_numtoa_unsign \
			lib/ft_put_toupper \
			lib/ft_putwchar \
			lib/ft_wcharlen \
			lib/ft_strdup \
			lib/ft_put \
			lib/ft_put_dec \
			lib/ft_realloc \
			lib/ft_strncpy \
			lib/ft_putnbr \
			\
			option/option_b \
			option/option_c \
			option/option_lc \
			option/option_d \
			option/option_ld \
			option/option_i \
			option/option_o \
			option/option_lo \
			option/option_p \
			option/option_s \
			option/option_ls \
			option/option_u \
			option/option_lu \
			option/option_x \
			option/option_lx

OBJ_PATH = ./obj/

OBJ_FOLDER = ./obj/ \
			./obj/lib/ \
			./obj/option/

SRC_EXT = $(addsuffix .c, $(SRC_NAME))

OBJ_NAME = $(SRC_EXT:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_EXT))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Create: $(NAME)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ_FOLDER)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
