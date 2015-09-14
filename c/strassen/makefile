CC = gcc
SRC = foo.c test.c strassen.c s.c arr.c matrix.c
REL = foo
SRC_BASE = foo.c test_basis.c strassen.c s.c arr.c matrix.c
REL_BASE = foo_base
CFLAG = -Wall -pg -g -fprefetch-loop-arrays

all: $(REL) $(REL_BASE)
	@echo "make completed!"

$(REL): $(SRC)
	@$(CC) -o $@ $(CFLAG) $^
	@objcopy --only-keep-debug $@ $@.debug

$(REL_BASE): $(SRC_BASE)
	@$(CC) -o $@ $(CFLAG) $^
	@objcopy --only-keep-debug $@ $@.debug

clean:
	@rm -rf $(REL) $(REL).debug
	@rm -rf $(REL_BASE) $(REL_BASE).debug
