
NAME:=	philo_bonus
SRC:= 	philo.c parser.c errors.c utils.c philo_utils.c processess.c init_structs.c routine.c controller.c\

OBJ:=	$(SRC:.c=.o)



FLAGS:=	-Wall -Werror -Wextra
# FLAGS+= -g3 -fsanitize=leak

CC:= cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f philo_bonus
re: fclean all