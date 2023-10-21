TEST_LIB = test
TEST_CC = gcc
TEST_CFLAGS = -Os -Wall
TEST_PKGS = -I../result/include/simavr -L../result/lib -lsimavr -lelf

all: ../$(TEST_LIB) ../$(TEST_LIB).so

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))

../$(TEST_LIB): $(SRCS)
	$(TEST_CC) $(TEST_CFLAGS) $^ -o $@ $(TEST_PKGS)

../$(TEST_LIB).so: $(OBJS)
	$(TEST_CC) -shared $^ -o $@ $(TEST_PKGS)

%.o : %.c
	$(TEST_CC) $(TEST_CFLAGS) -c -fPIC $< -o $@ $(TEST_PKGS)

clean:
	rm -rf $(OBJS) ../$(TEST_LIB) ../$(TEST_LIB).so
