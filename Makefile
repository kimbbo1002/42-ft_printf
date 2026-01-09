NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INCL = ft_printf.h
SRCS = ft_printf.c \
		utils.c \
		utils2.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs $@ $^

%.o: %.c ${INCL}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
