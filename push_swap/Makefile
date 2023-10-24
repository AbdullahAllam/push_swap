NAME = push_swap
CHECK = checker

SRCS =  $(wildcard src/*.c utils/*.c)
CHECK_SRCS = $(wildcard utils/*.c) checker.c

OBJS = ${SRCS:.c=.o}
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

#all: ${NAME} ${CHECK}

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

#${CHECK}: ${CHECK_OBJS} 
#	@${CC} ${CFLAGS} ${CHECK_OBJS} ./libft/libft.a -o ${CHECK}

bonus: ${CHECK}
${CHECK}: ${CHECK_OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${CHECK_OBJS} ./libft/libft.a -o ${CHECK}


clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

bonusre: fclean bonus

.PHONY: all clean fclean re bonus
