NAME=libft.a

SRCS=srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS=${SRCS:.c=.o}
HEADERS_FOLDER=./includes
CC=cc
CFLAGS=-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I${HEADERS_FOLDER} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re