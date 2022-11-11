NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c ft_puts.c ft_puthexa.c

OBJCT = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJCT)
	ar -rc $(NAME) $(OBJCT)

%.o: %.c ft_printf.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJCT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re