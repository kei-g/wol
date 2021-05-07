CC = clang
CFLAGS = -D_GNU_SOURCE -O3 -Wall -Werror -march=native -std=c17
LD = clang
LDFLAGS = -Wl,-s
TARGET_BINARY = wol
TARGET_OBJECTS = $(TARGET_SOURCES:%.c=%.o)
TARGET_SOURCES = wol.c

all: $(TARGET_BINARY)

clean:
	$(RM) $(TARGET_BINARY) $(TARGET_OBJECTS)

.PHONY: all clean

.c.o:
	$(CC) $(CFLAGS) -c $<

$(TARGET_BINARY): $(TARGET_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^
