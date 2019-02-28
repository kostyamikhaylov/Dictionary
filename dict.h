#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


struct String_fn
{
	void (*Add) (struct String_fn *str_fn, char *s);
	int (*Compare) (struct String_fn *str_fn, char *s);
	void (*Print) (struct String_fn *str_fn);
	void (*Destroy) (struct String_fn *str_fn);
};

struct word_fn
{
	void (*Add) (struct word_fn *word_fn, char *s);
	int (*Compare) (struct word_fn *word_fn, char *s);
	int (*GetFreq) (struct word_fn *word_fn);
	void (*AddFreq) (struct word_fn *word_fn);
	void (*Print) (struct word_fn *word_fn);
	void (*Destroy) (struct word_fn *word_fn);
};

struct dict_fn
{
	void (*Add) (struct dict_fn *dict_fn, char *s);
	int (*GetFreq) (struct dict_fn *dict_fn, char *s);
	void (*Print) (struct dict_fn *dict_fn);
	void (*Destroy) (struct dict_fn *dict_fn);
};

struct dict_fn *ConstructDict (void);

