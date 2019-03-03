#include <iostream>
#include <string>
#include <vector>
using namespace std;


class String
{
	public:
		String (void) {}
		String (const string& s)
		{
			str = s;
		}
		int IsString (string s) const
		{
			if (str == s)
				return 1;
			else
				return 0;
		}
		void AddString (const string& s)
		{
			str = s;
		}
		void PrintString (void) const
		{
			cout << str;
		}

	private:
		string str;
};

class Word
{
	public:
		Word (const string& s)
		{
			word.AddString (s);
			freq = 1;
		}
		int IsWord (const string& s) const
		{
			return CompareString (s);
		}
		void AddFreq (void)
		{
			freq += 1;
		}
		void PrintWord (void) const
		{
			cout << "Word: ";
			word.PrintString ();
		   	cout <<	"\tfrequency: " << freq << '\n';
		}

	private:
		int CompareString (const string& s) const
		{
			if (word.IsString (s))
				return 1;
			else
				return 0;
		}
		String word;
		int freq;
};

class Dictionary
{
	public:
		Dictionary (void) {}
		Dictionary (const vector<string>& s)
		{
			for (const string& str : s)
			{
				AddWord (str);
			}
		}
		
		void AddWord (const string& s)
		{
			if (!CheckExistence (s))
			{
				Word new_word (s);
				words.push_back (new_word);
			}
			else
			{
				for (Word& w : words)
				{
					if (w.IsWord (s))
						w.AddFreq ();
				}
			}
		}
		void PrintDict (void) const
		{
			for (const Word& w : words)
				w.PrintWord ();
		}

	private:
		int CheckExistence (const string& str) const
		{
			for (const Word& w : words)
			{
				if (w.IsWord (str))
					return 1;
			}
			return 0;
		}
		vector<Word> words;
};

int main ()
{
	Dictionary dict ({"sss", "ddd", "asaad", "djslds", "sss", "dieke", "ddd"});
	dict.AddWord ("sss");
	dict.AddWord ("dsdssfds");
	dict.PrintDict ();

	return 0;
}

