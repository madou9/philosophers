NAME = philo

CC   = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g -I$(INCLUDE)

INCLUDE = include/

SRCS = srcs/

SRC = $(SRCS)main.c $(SRCS)init_philo.c $(SRCS)time_philo.c $(SRCS)philo_eat.c $(SRCS)check_philo.c $(SRCS)routine.c $(SRCS)utils.c $(SRCS)ft_take_fork.c $(SRCS)ft_free.c \

OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

all : ${NAME}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
