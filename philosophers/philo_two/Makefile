NAME = philo_two
OBJS = $(SRCS:.c=.o)

SRCS = main.c philosophers.c \
		simulation.c tools.c \
		free.c init.c \
		utils.c \

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -o ${NAME} ${OBJS} 

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re