SRCS = $(addprefix $(SRCDIR)/,  ft_control_calculation.c ft_strlen.c ft_atoi.c ft_putnbr.c main.c ft_putstr.c ft_oper.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./srcs
HEADERDIR = ./includes
TARGET = do-op

all : $(TARGET)

$(TARGET) : $(OBJS)
	cc -o $@ $(CFLAGS) $^

%.o : %.c
	cc $(CFLAGS) -c $^ -o $@ -I $(HEADERDIR)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
