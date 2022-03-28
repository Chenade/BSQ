NAME	= bsq
CC		= gcc
SRC		= main.c
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
OBJS    = ${SRC:.c=.o}
.c.o:
	${CC} -c ${FLAGS} $< -o ${<:.c=.o}
bsq :	${OBJS}
		${CC} -o ${NAME} ${OBJS}
clean:
		${RM} ${OBJS}
fclean:	clean
		${RM} ${NAME}
re:		fclean all
.PHONY: all clean fclean re
