NAME = libft.a

SRC_DIR = srcs
INCLUDES = includes

SRC =  $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swap.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c
OBJ = $(SRC: .c = .o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rc
RANLIB = ranlib
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

%.o: %.c
	$(cc) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean: 
	$(RM) $(OBJ)
	
fclean: clean 
	$(RM) $(name)
	
re : fclean all