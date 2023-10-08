CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = bsq
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
HEADDIR = ./includes
SRCSDIR = ./srcs

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re : fclean all
