#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string line;
	string wait;
	ifstream my_file( "./jokes.txt" );
	
	cout << endl;

	if( my_file.is_open() )
	{
		int i = 0;
		while( getline( my_file, line ) )
		{
			if( i%3 == 0 )
			{
				cout << "\x1b[3m" << line << "\x1b[0m";
			}
			else if( i%3 == 1 )
			{
				getline( cin, wait );
				cout << "\x1b[1m" << line << "\x1b[0m";
			}
			else
			{
				getline( cin, wait );
				cout << "\x1b[33m-\x1b[0m" << endl;
			}
			i++;
		}
		my_file.close();
		cout << "\n" << endl;
	}
	else
	{
		cout << "Unable to open file." << endl;
	}

	return 0;
}
