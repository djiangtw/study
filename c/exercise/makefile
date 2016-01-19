CC=gcc
CFLAG=-Wall

all: ds rand
	@echo "compile done"

rand: rand.c
	$(CC) $(CFLAG) -o $@ $<

ds: ds.c
	$(CC) $(CFLAG) -o $@ $<

clean:
	rm -f ds rand
	@echo "cleaned"
