
CFLAGS = -Wall -Wextra -fPIC

SRCS = random.c file_utils.c str_utils.c utils.c
OBJS = $(SRCS:.c=.o)
TARGET = libutils.so

all: $(TARGET)

$(TARGET): $(OBJS)
	gcc -shared -o $@ $^

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.so
	rm -f *.o
