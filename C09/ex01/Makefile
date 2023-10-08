SRCS = $(addprefix $(SRCDIR)/,  ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./srcs
HEADERDIR = ./includes
TARGET = libft.a

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	cc $(CFLAGS) -c $^ -o $@ -I $(HEADERDIR)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
