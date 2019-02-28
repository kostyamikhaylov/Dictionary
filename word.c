#include "dict.h"


struct String;

struct String_fn *ConstructString (void);

struct word
{
	struct String_fn *w;
	int freq;
};


void AddWord (struct word_fn *word_fn, char *s);
int CompareWord (struct word_fn *word_fn, char *s);
int GetFreqWord (struct word_fn *word_fn);
void AddFreqWord (struct word_fn *word_fn);
void PrintWord (struct word_fn *word_fn);
void DestroyWord (struct word_fn *word_fn);

struct word_fn * ConstructWord (void)
{
	struct word_fn *new_word = (struct word_fn *) calloc (1, sizeof (*new_word) + sizeof (struct word));
	new_word->Add = AddWord;
	new_word->Compare = CompareWord;
	new_word->GetFreq = GetFreqWord;
	new_word->AddFreq = AddFreqWord;
	new_word->Print = PrintWord;
	new_word->Destroy = DestroyWord;

	return new_word;
}

void AddWord (struct word_fn *word_fn, char *s)
{
	struct word *word = (struct word *) (word_fn + 1);
	word->w = ConstructString ();
	
	word->w->Add (word->w, s);
	word->freq = 1;
}

int CompareWord (struct word_fn *word_fn, char *s)
{
	struct word *word = (struct word *) (word_fn + 1);
	return word->w->Compare (word->w, s);
}

int GetFreqWord (struct word_fn *word_fn)
{
	struct word *word = (struct word *) (word_fn + 1);
	return word->freq;	
}

void AddFreqWord (struct word_fn *word_fn)
{
	struct word *word = (struct word *) (word_fn + 1);
	word->freq++;	
}

void PrintWord (struct word_fn *word_fn)
{
	struct word *word = (struct word *) (word_fn + 1);
	printf ("Word: ");
	word->w->Print (word->w);
	printf ("\tfrequency: %d\n", word->freq);
}

void DestroyWord (struct word_fn *word_fn)
{
	struct word *word = (struct word *) (word_fn + 1);
	word->w->Destroy (word->w);
	free (word_fn);
}

