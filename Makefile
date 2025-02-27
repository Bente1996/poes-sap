EXEC_NAME := push_swap
HEADERFILES := ft_printf/Libft/libft.h ft_printf/ft_printf.h push_swap.h
SRCFILES := main.c \
parsing.c \
nodes.c \
operations.c \
little_ones.c \
selection_sort.c \
checks.c \
radix.c \
bubbles.c \
utils.c

OBJFILES := $(SRCFILES:.c=.o)
CFLAGS ?= -g -Wall -Wextra -Werror -I./ft_printf/Libft -I./ft_printf
FT_PRINTF_A := ft_printf/libftprintf.a

all : $(EXEC_NAME)

run: $(EXEC_NAME)
	./$(EXEC_NAME)

valgrind: $(EXEC_NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXEC_NAME) 435 4524 542524 5

$(EXEC_NAME): $(OBJFILES) $(FT_PRINTF_A)
	$(CC) $(OBJFILES) $(FT_PRINTF_A) $(CFLAGS) -o $(EXEC_NAME)

%.o: %.c $(HEADERFILES)
	cc $(CFLAGS) -c $<

$(FT_PRINTF_A):
	$(MAKE) -C ft_printf

clean:
	rm -f $(OBJFILES)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(EXEC_NAME)

re: fclean all

.PHONY: clean fclean re