CC = cc

PATH_P = ft_printf
C_FILES_PRINT_F = $(PATH_P)/ft_putnbr.c $(PATH_P)/ft_set_flags.c $(PATH_P)/ft_print_flags.c \
$(PATH_P)/ft_string_filter.c $(PATH_P)/ft_print_format.c $(PATH_P)/ft_puthexa.c \
$(PATH_P)/ft_putchar_and_incr.c $(PATH_P)/ft_count_length.c $(PATH_P)/ft_get_size.c \
$(PATH_P)/ft_atoi_for_flags.c

PATH_F = func
C_FILES_FUNC = $(PATH_F)/ft_perror.c $(PATH_F)/ft_pipe.c $(PATH_F)/ft_split.c \
$(PATH_F)/ft_printf.c $(PATH_F)/ft_execute.c

C_FILES = $(C_FILES_PRINT_F) $(C_FILES_FUNC) pipex.c
O_FILES = $(C_FILES:.c=.o)

C_FILES_BONUS = $(C_FILES_PRINT_F) $(C_FILES_FUNC) pipex_bonus.c
O_FILES_BONUS = $(C_FILES_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror
NAME = pipex.a
NAME_BONUS = pipex_bonus.a
EXE = pipex

all:$(NAME)
bonus:$(NAME_BONUS)

$(NAME):$(O_FILES)
	ar -rcs $(NAME) $(O_FILES)
	$(CC) $(NAME) -o $(EXE)
	rm -f $(NAME_BONUS)
$(NAME_BONUS):$(O_FILES_BONUS)
	ar -rcs $(NAME_BONUS) $(O_FILES_BONUS)
	$(CC) $(NAME_BONUS) -o $(EXE)
	rm -f $(NAME)


%.o:%.c pipex.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(O_FILES) $(O_FILES_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re