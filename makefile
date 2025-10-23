CC = gcc
CFLAGS = -Wall -O2 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lm

SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)
TARGET = Main

.PHONY: all clean rebuild

all: $(TARGET)
	@find . -name "*.o" -exec rm -f {} +

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@find . -name "*.o" -delete
	@rm -f $(TARGET)

rebuild: clean all
