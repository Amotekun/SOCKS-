CC = gcc
CFLAGS = -Wall -Iinclude

SRCS = src/amotekun.c src/socks.c src/utils.c
OBJS = $(SRCS:.c=.o)

TARGET = amotekun

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)