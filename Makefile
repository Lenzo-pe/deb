# -*- Makefile -*-

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = 	ft_printf.c ft_after.c \
		ft_converter_itoa.c ft_converter_htoa.c \
		ft_converter_ptoa.c ft_converter_utoa.c \
		ft_printf_utils.c ft_printf_utils2.c \
		ft_printf_output_utils.c ft_printf_conversor_utils.c \
		ft_printf_after_utils.c \
		ft_width.c ft_flag.c ft_precision.c \
		ft_parameter_s.c ft_parameter_p.c ft_printf_utils3.c

OBS = $(SRC:.c=.o)

$(NAME): $(OBS) ft_printf.h
	$(CC) $(CFLAGS) $(SRC) -c
	ar -rcs $(NAME) $(OBS)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBS)
fclean: clean
	rm -rf $(NAME)

re: fclean all
