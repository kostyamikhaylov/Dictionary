#include "dict.h"
#include <fcntl.h>


int main (int argc, char **argv)
{
	struct dict_fn *dict1;
/*
	int fd = -1;
	if (argc == 2)
	{
		if ((fd = open (argv[1], O_RDONLY)) < 0)
		{
			perror ("open");
			exit (EXIT_FAILURE);
		}
	}
	else if (argc == 1)
		fd = STDIN_FILENO;
	else
	{
		fprintf (stderr, "Usage: <name>  [filename]\n");
		exit (EXIT_FAILURE);
	}
*/
	dict1 = ConstructDict ();

	dict1->Add (dict1, "fff");
	dict1->Add (dict1, "fff");
	
	dict1->Print (dict1);
	dict1->Add (dict1, "sss");
	
	printf ("Frequency of word \"%s\" is %d\n", "fff", dict1->GetFreq (dict1, "fff"));

	dict1->Print (dict1);

	dict1->Add (dict1, "sss");
	
	dict1->Add (dict1, "xxx");
	
	dict1->Add (dict1, "sss");

	dict1->Add (dict1, "fff");
	
	dict1->Print (dict1);

	dict1->Destroy (dict1);

	return 0;
}

