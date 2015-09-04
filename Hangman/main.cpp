#include <iostream>
#include <random>
using namespace std;

string PICS [7] = {"\n\
   +---+\n\
   |   |\n\
       |\n\
       |\n\
       |\n\
       |\n\
 =========", "\n\
   +---+\n\
   |   |\n\
   O   |\n\
       |\n\
       |\n\
       |\n\
 =========", "\n\
   +---+\n\
   |   |\n\
   O   |\n\
   |   |\n\
       |\n\
       |\n\
 =========", "\n\
   +---+\n\
   |   |\n\
   O   |\n\
  /|   |\n\
       |\n\
       |\n\
 =========", "\n\
   +---+\n\
   |   |\n\
   O   |\n\
  /|\\  |\n\
       |\n\
       |\n\
 =========", "\n\
   +---+\n\
   |   |\n\
   O   |\n\
  /|\\  |\n\
  /    |\n\
       |\n\
 =========", "\n\
   +---+\n\
   |   |\n\
   O   |\n\
  /|\\  |\n\
  / \\  |\n\
       |\n\
 ========="};
string WORDS [25] = {"perl", "python", "ruby", "javascript", "lua", "php", "c", "r", "coffeescript", "typescript", "go", "c++", "pascal", "bash", "prolog", "java", "basic", "delphi", "a", "haskell", "karel", "matlab", "objective-c", "sql", "petr"};

int main()
{
	random_device rd;
	uniform_int_distribution<int> dist(0, 24);
	string word = WORDS[dist(rd)];
	string guessed(word.length(), '_');
	char guess;
	int missed = 0;

	cout << "\nZkus uhádnout \x1b[4mprogramovací jazyk\x1b[0m, který si myslím!\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

	while( missed < 6 )
	{
		for( int i = 0; i < 11; i++ )
		{
			cout << "\033[F";
		}
		cout << PICS[missed] << endl;
		for( int i = 0; i < word.length(); i++ )
		{
			cout << " " << guessed[i];
		}
		cout << endl << endl << "Hádej písmeno: \x1b[33m";
		cin >> guess;
		cout << "\x1b[0m";

		bool ok = false;
		bool all = true;
		for( int i = 0; i < word.length(); i++ )
		{
			if( word[i] == guess )
			{
				guessed[i] = guess;
				ok = true;
			}
			else if( guessed[i] == '_' )
			{
				all = false;
			}
		}
		if( not ok )
		{
			missed++;
		}
		else if( all )
		{
			break;
		}
	}

	cout << "\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F";
	cout << PICS[missed] << endl;
	for( int i = 0; i < word.length(); i++ )
	{
		cout << " " <<  guessed[i];
	}

	if( missed == 6 )
	{
		cout << endl << "\n\x1b[31mKonec hry\x1b[0m. Už je oběšený... Myslel jsem si jazyk \x1b[1m" << word << "\x1b[0m.\n" << endl;
	}
	else
	{
		cout << endl << "\n\x1b[32mVýborně\x1b[0m. Myslel jsem \x1b[1m" << word << "\x1b[0m.\n" << endl;
	}

	return 0;
}
