NAME	= mysh

CC	= gcc -no-pie

RM	= rm -f

SRCS	= ./main.c \
		  ./function.c \
		  ./function2.c \
		  ./function3.c \
		  ./function4.c

CFLAGS = -I 
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME):
	 $(CC) $(SRCS) -Llib/ -lmy -o $(NAME) $(LDFLAGS)

clean:
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
