#include "dict.h"
#include <string.h>


struct String
{
	char *string;
};

void AddString (struct String_fn *str_fn, char *s);
int CompareString (struct String_fn *str_fn, char *s);
void PrintString (struct String_fn *str_fn);
void DestroyString (struct String_fn *str_fn);

struct String_fn *ConstructString (void)
{
	struct String_fn *new_string = (struct String_fn *) calloc (1, sizeof (*new_string) + sizeof (struct String));
	new_string->Add = AddString;
	new_string->Compare = CompareString;
	new_string->Print = PrintString;
	new_string->Destroy = DestroyString;

	return new_string;
}

void AddString (struct String_fn *str_fn, char *s)
{
	struct String *str = (struct String *) (str_fn + 1);
	str->string = (char *) calloc (strlen (s) + 1, sizeof (*(str->string)));
	memcpy (str->string, s, strlen (s) + 1);
}

int CompareString (struct String_fn *str_fn, char *s)
{
	struct String *str = (struct String *) (str_fn + 1);
	if (!strcmp (str->string, s))
		return 1;
	else
		return 0;
}

void PrintString (struct String_fn *str_fn)
{
	struct String *str = (struct String *) (str_fn + 1);
	printf ("%s", str->string);
}

void DestroyString (struct String_fn *str_fn)
{
	struct String *str = (struct String *) (str_fn + 1);
	free (str->string);
	free (str_fn);
}

