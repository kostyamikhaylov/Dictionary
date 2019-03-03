#include "dict.h"
#include <ctype.h>
#include <string.h>

#define MAX_DICT_LEN 1000


struct word_fn *ConstructWord (void);

struct dict_list
{
	struct word_fn *word;
	struct dict_list *next;
};

void AddWordToDict2 (struct dict_fn *dict_fn, char *s);
int GetFreqDict2 (struct dict_fn *dict_fn, char *s);
void PrintDict2 (struct dict_fn *dict_fn);
void DestructDict2 (struct dict_fn *dict_fn);

struct dict_fn *ConstructDict2 (void)
{
	struct dict_fn *new_dict = (struct dict_fn *) calloc (1, sizeof (*new_dict) + sizeof (struct dict_list));
	new_dict->Add = AddWordToDict2;
	new_dict->GetFreq = GetFreqDict2;
	new_dict->Print = PrintDict2;
	new_dict->Destroy = DestructDict2;

	return new_dict;
}

void AddWordToDict2 (struct dict_fn *dict_fn, char *s)
{
	struct dict_list *d = (struct dict_list *) (dict_fn + 1);
	if (!d->word)
	{
		struct word_fn *new_word = ConstructWord ();
		d->word = new_word;
		d->next = NULL;

		d->word->Add (d->word, s);
		
		return ;
	}

	while (1)
	{
		if (d->word->Compare (d->word, s))
		{
			d->word->AddFreq (d->word);
			return ;
		}
		if (d->next)
			d = d->next;
		else
			break;
	}

	struct word_fn *new_word = ConstructWord ();
	struct dict_list *new = (struct dict_list *) calloc (1, sizeof (*new));
	d->next = new;
	d->next->word = new_word;
	d->next->next = NULL;

	d->next->word->Add (d->next->word, s);

	return ;
}

int GetFreqDict2 (struct dict_fn *dict_fn, char *s)
{
	struct dict_list *d = (struct dict_list *) (dict_fn + 1);
	
	if (!d->word)
		return 0;
	
	while (1)
	{
		if (d->word->Compare (d->word, s))
		{
			return d->word->GetFreq (d->word);
		}
		if (d->next)
			d = d->next;
		else
			break;
	}
	
	return 0;
}

void PrintDict2 (struct dict_fn *dict_fn)
{
	struct dict_list *d = (struct dict_list *) (dict_fn + 1);
	
	if (!d->word)
	{
		printf ("Dictionary is empty\n");
		return ;
	}

	while (1)
	{
		d->word->Print (d->word);
		if (d->next)
			d = d->next;
		else
			break;
	}

	return ;
}

void DestructDict2 (struct dict_fn *dict_fn)
{
	struct dict_list *d = (struct dict_list *) (dict_fn + 1);
	struct dict_list *save = NULL;
	if (!d->word)
	{
		free (dict_fn);
		return ;
	}
	d->word->Destroy (d->word);
	d = d->next;
	free (dict_fn);
	while (1)
	{
		if (d)
		{
			save = d->next;
			d->word->Destroy (d->word);
			free (d);
			d = save;
		}
		else
			break;
	}

	return ;
}

