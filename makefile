TAG = dict
HDR = dict.h
DEP1 = main
DEP2 = dict
DEP3 = dict2
DEP4 = word
DEP5 = string
MACRO1 = DICT
DICTIONARY = ConstructDict2				#Choose ConstructDict / ConstructDict2
DEPS = $(DEP1).o $(DEP2).o $(DEP3).o $(DEP4).o $(DEP5).o
CFLAGS += -Wall -g
CC = gcc

$(TAG): $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@
	$(RM) $(DEPS)

$(DEP1).o: $(DEP1).c
	$(CC) $(CFLAGS) -c $^ -o $@ -D $(MACRO1)=$(DICTIONARY)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(TAG): $(HDR)

clean:
	$(RM) $(DEPS) $(TAG)

