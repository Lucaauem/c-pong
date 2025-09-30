CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -O2
LDFLAGS = -lgdi32

SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)
TARGET = Main.exe

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
