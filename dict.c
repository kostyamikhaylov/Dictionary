#include "dict.h"
#include <ctype.h>
#include <string.h>

#define MAX_DICT_LEN 1000


struct word;

struct word_fn * ConstructWord (void);

static int d_index = 0;

struct dict
{
	struct word_fn words[MAX_DICT_LEN];
	int dict_len;
};

void AddWordToDict (struct dict_fn *dict_fn, char *s);
int GetFreqDict (struct dict_fn *dict_fn, char *s);
void PrintDict (struct dict_fn *dict_fn);
void DestructDict (struct dict_fn *dict_fn);

struct dict_fn * ConstructDict (void)
{
	struct dict_fn *new_dict = (struct dict_fn *) calloc (1, sizeof (*new_dict) + sizeof (struct dict));
	new_dict->Add = AddWordToDict;
	new_dict->GetFreq = GetFreqDict;
	new_dict->Print = PrintDict;
	new_dict->Destroy = DestructDict;

	return new_dict;
}

void AddWordToDict (struct dict_fn *dict_fn, char *s)
{
	struct dict *d = (struct dict *) (dict_fn + 1);
	for (int i = 0; i < d->dict_len; i++)
	{
		if (d->words[i].Compare (&(d->words[i]), s))
		{
			d->words[i].AddFreq (&(d->words[i]));
			return ;
		}
	}

	if (d_index == MAX_DICT_LEN)
	{
		fprintf (stderr, "Dictionary is full, exiting\n");
		return ;
	}

	struct word_fn *new_word = ConstructWord ();
	memcpy (&(d->words[d_index]), new_word, sizeof (struct word_fn));
	free (new_word);

	d->words[d_index].Add (&(d->words[d_index]), s);
	d->dict_len++;
	d_index++;

	return ;
}

int GetFreqDict (struct dict_fn *dict_fn, char *s)
{
	struct dict *d = (struct dict *) (dict_fn + 1);
	for (int i = 0; i < d->dict_len; i++)
	{
		if (d->words[i].Compare (&(d->words[i]), s))
		{
			return d->words[i].GetFreq (&(d->words[i]));
		}
	}
	
	return 0;
}

void PrintDict (struct dict_fn *dict_fn)
{
	struct dict *d = (struct dict *) (dict_fn + 1);
	for (int i = 0; i < d->dict_len; i++)
		d->words[i].Print (&(d->words[i]));

	return ;
}

void DestructDict (struct dict_fn *dict_fn)
{
	struct dict *d = (struct dict *) (dict_fn + 1);
	for (int i = 0; i < d->dict_len; i++)
	{
		d->words[i].Destroy (&(d->words[i]));
	}

	return ;
}

