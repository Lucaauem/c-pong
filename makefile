CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -O2
LDFLAGS = -lgdi32

SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)
TARGET = Main.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
#
