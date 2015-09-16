CC = gcc
SRC_FILES = foo.c test.c strassen.c arr.c matrix.c
SRC_PATH = src/
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
REL_FILES = foo
REL_PATH = rel/
REL = $(addprefix $(REL_PATH), $(REL_FILES))
# SRC_BASE = foo.c test_basis.c strassen.c s.c arr.c matrix.c
# REL_BASE = foo_base
CFLAG = -Wall -pg -g

all: $(REL)
	@echo "make completed!"

$(REL): $(SRC)
	@mkdir -p rel
	@$(CC) -o $@ $(CFLAG) $^
	@objcopy --only-keep-debug $@ $@.debug
	@echo $(SRC)

#$(REL_BASE): $(SRC_BASE)
#	@$(CC) -o $@ $(CFLAG) $^
#	@objcopy --only-keep-debug $@ $@.debug

dox: foo.dox
	@doxygen $^

prof: $(REL) gmon.out
	@gprof rel/foo gmon.out > doc/analysis.txt
	@echo code analysis is generated in doc/analysis.txt

clean:
	@rm -rf $(REL_PATH)
	@rm -rf doc/html doc/latex
	@rm -f doc/analysis.txt
	@rm gmon.out
#	@rm -rf $(REL_BASE) $(REL_BASE).debug

