#include "dict.h"
#include <fcntl.h>

#ifndef DICT
	#define DICT ConstructDict2
#endif


int main (int argc, char **argv)
{
	struct dict_fn *dict1;
	
	dict1 = DICT ();

	dict1->Print (dict1);
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

