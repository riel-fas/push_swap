NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = 

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h




all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
        $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
        make -C libft

%.o: %.c $(HEADER)
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        rm -rf $(OBJS)
        make clean -C libft

fclean: clean
        rm -rf $(NAME)
        make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
