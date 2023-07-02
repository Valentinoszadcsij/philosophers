
NAME:=	philo
SRC:= 	philo.c parser.c errors.c utils.c thread_init.c thread_func.c

OBJ:=	$(SRC:.c=.o)



FLAGS:=	-Wall -Werror -Wextra
# FLAGS+= -g3 -fsanitize=address

CC:= cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f philo
re: fclean all