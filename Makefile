EXEC_NAME := push_swap
HEADERFILES := Libft/libft.h Libft/ft_printf.h push_swap.h
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
CFLAGS ?= -g -Wall -Wextra -Werror -I./Libft
LIBFT_A := Libft/libft.a

all : $(EXEC_NAME)

run: $(EXEC_NAME)
	./$(EXEC_NAME)

valgrind: $(EXEC_NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXEC_NAME) 3 2 1 

$(EXEC_NAME): $(OBJFILES) $(LIBFT_A)
	$(CC) $(OBJFILES) $(LIBFT_A) $(CFLAGS) -o $(EXEC_NAME)

%.o: %.c $(HEADERFILES)
	cc $(CFLAGS) -c $<

$(LIBFT_A):
	$(MAKE) -C Libft

clean:
	rm -f $(OBJFILES)
	$(MAKE) -C Libft clean

fclean: clean
	rm -f $(EXEC_NAME)

re: fclean all

.PHONY: clean fclean re