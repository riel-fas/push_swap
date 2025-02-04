NAME	=	libft.a

CC	= cc

CCFLAGS	= -Wall -Wextra -Werror

SRC = ft_strlen.c ft_strdup.c ft_substr.c

OBJ = $(SRC:.c=.o)

AR = ar rcs


all	:	${NAME}

$(NAME)	:	$(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c libft.h
	$(CC) $(CCFLAGS) -c $< -o $@

clean	:
		rm	-rf	$(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean	all

.PHONY : all clean fclean re
