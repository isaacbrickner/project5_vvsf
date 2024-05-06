CC = gcc
CFLAGS = -Wall -Wextra -DCTEST_ENABLE
LIB = libvvsfs.a test_open_img.txt
SRCS = image.c block.c testfs.c
OBJS = $(SRCS:.c=.o)
EXEC = testfs

.PHONY: all clean pristine

all: $(EXEC)

$(EXEC): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(LIB): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC) $(LIB) *.d

pristine: clean
	rm -f $(EXEC) $(LIB)
