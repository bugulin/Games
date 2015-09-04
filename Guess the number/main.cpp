#include <iostream>
#include <random>
using namespace std;

int string_to_int( string n )
{
	int result = 0;
	bool negative = false;
	int length = n.length() - 1;
	for( int i = 0; i <= length; i++ )
	{
		switch( n[i] )
		{
			case '-':
				negative = true;
				break;
			case '1':
				result += 1*pow(10, length-i);
				break;
			case '2':
				result += 2*pow(10, length-i);
				break;
			case '3':
				result += 3*pow(10, length-i);
				break;
			case '4':
				result += 4*pow(10, length-i);
				break;
			case '5':
				result += 5*pow(10, length-i);
				break;
			case '6':
				result += 6*pow(10, length-i);
				break;
			case '7':
				result += 7*pow(10, length-i);
				break;
			case '8':
				result += 8*pow(10, length-i);
				break;
			case '9':
				result += 9*pow(10, length-i);
				break;
		}
	}
	if( negative )
	{
		result *= -1;
	}
	return result;
}

int main()
{
	random_device rd;
	uniform_int_distribution<int> dist(1, 29);

	int number = dist(rd);
	int guesses_taken = 0;

	string name;
	string guess;
	int guess_number;

	cout << endl << "Ahoj! Jak se jmenuješ (5. pád)? \x1b[33m";
	cin >> name;

	cout << "\x1b[0mAhoj, " << name << ". Myslím si číslo od 0 do 30." << endl;
	
	do
	{
		cout << "Hádej: \x1b[33m";
		cin >> guess; // vstup nemusí být v intervalu hádání
		
		guess_number = string_to_int(guess);
		if( guess_number < number )
		{
			cout << "\x1b[0mTvé číslo je \x1b[4mmenší\x1b[0m." << endl;
		}
		else if( guess_number > number )
		{
			cout << "\x1b[0mTvé číslo je \x1b[4mvětší\x1b[0m." << endl;
		}
		guesses_taken++;
	} while( guess_number != number && guesses_taken < 10);

	if( guess_number == number )
	{
		cout << "\x1b[32mDobrá práce, " << name << "! Uhádl jsi moje číslo na " << guesses_taken << " pokusů!\x1b[0m" << endl << endl;
	}
	else
	{
		cout << "\x1b[31mNo nic. Číslo, které jsem si myslel bylo " << number << "!\x1b[0m" << endl << endl;
	}
	
	return 0;
}
