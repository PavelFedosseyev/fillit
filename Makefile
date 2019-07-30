NAME = fillit
SRCS = 	main.c\
				ft_fillit.c\
				ft_newlist.c\
				map.c\
				ft_validate.c\

INCLUDES = -I fillit.h
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) $(INCLUDES) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
