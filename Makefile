CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
NAME = fillit 

SRC =   main.c valid.c checktermino.c ft_backtrack.c ft_check.c ft_freemap.c ft_map.c ft_search.c ft_vivod.c 

.PHONY: re clean fclean all test libft #Указывает что это не файл
OBJ = $(SRC:.c=.o) #Делаем из того что в SRC .o
LIBFTFLAGS = -L./libft -lft #флаги для либы
LIBFT = libft 

all: $(NAME)

%.o:%.c #правило для компиляции .o-файлов; $@ - автопеременная; меняет .o в .c
	$(CC) -c $< -I./libft $(CFLAGS) 

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -I./libft $(LIBFTFLAGS) $(CFLAGS) -o $(NAME)

$(LIBFT):
	make -C ./libft all

clean:
	rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME) 
	make -C ./libft fclean

re: fclean all

c: clean
f: fclean