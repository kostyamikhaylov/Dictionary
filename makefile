TAG = dict
DEP1 = main
DEP2 = dict
DEP3 = word
DEP4 = string
DEPS = $(DEP1).o $(DEP2).o $(DEP3).o $(DEP4).o
CFLAGS += -Wall -g
CC = gcc


$(TAG): $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@
	$(RM) $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(DEPS) $(TAG)

