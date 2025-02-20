NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = \
    push_swap.c \
    algo_1.c \
    algo_2.c \
    algo_3.c \
    stack_operations_1.c \
    stack_operations_2.c \
    stack_utils_1.c \
    stack_utils_2.c \
    string_pars.c

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
