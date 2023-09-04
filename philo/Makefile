NAME = Philosophers

CC   = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g -I$(INCLUDE)

INCLUDE = include/

LIBFT	= ./libft/libft.a

SRCS = srcs/

SRC = $(SRCS)main.c $(SRCS)init_philo.c $(SRCS)time_philo.c \

OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME) 

all : ${NAME}

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
