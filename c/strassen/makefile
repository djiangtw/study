CC = gcc
SRC = foo.c test.c strassen.c s.c
REL = foo
CFLAG = -Wall -pg -g

all: $(REL)
	@echo "make completed!"

$(REL): $(SRC)
	@$(CC) -o $@ $(CFLAG) $^
	@objcopy --only-keep-debug $@ $@.debug

clean:
	@rm -rf $(REL) $(REL).debug
