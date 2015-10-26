#include <iostream>
#include <random>
using namespace std;

int my_number [3];
int guess [3];
int intg;
char output [3];

char evaluation( int pos )
{
	int g = guess[pos];
	for( int i = 0; i < 3; i++)
	{
		if( g == my_number[i] )
		{
			if( i == pos )
			{
				return 'F';
			}
			else
			{
				return 'P';
			}
		}
	}
	return 'B';
}

int main ()
{
	/* Number generator */
	random_device rd;
	uniform_int_distribution<int> dist(0, 9);
	my_number[0] = dist(rd);
	do {
		my_number[1] = dist(rd);
	} while( my_number[0] == my_number[1] );
	do {
		my_number[2] = dist(rd);
	} while( my_number[0] == my_number[2] || my_number[1] == my_number[2] );

	// cout << my_number[0] << my_number[1] << my_number[2] << endl;

	/* Intro */
	cout << "Myslím si 3 místné číslo. V tomto čísle se žádná číslice neopakuje." << endl;
	cout << "Tady máš vodítka:" << endl << endl;
	cout << "\x1b[4mKdyž řeknu\x1b[0m  \x1b[4mZnamená to\x1b[0m" << endl;
	cout << "Pico        Jedna číslice je správně ale na špatné pozici." << endl;
	cout << "Fermi       Jedna číslice je správně a na dobrém místě." << endl;
	cout << "Bagels      Žádná číslice není správná." << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << endl << "Tak můžeš hádat!" << endl << endl;

	/* Main game loop */
	for( int loop = 1; loop < 10; loop++)
	{
		cout << "\x1b[32m?\x1b[0m ";
		cin >> intg;
		
		for( int i = 2; i >= 0; i-- )
		{
			guess[i] = intg%10;
			intg /= 10;
		}

		output[0] = ' ';
		output[1] = ' ';
		output[2] = ' ';
		for( int i = 0; i < 3; i++ )
		{
			output[i] = evaluation(i);
		}
		cout << "→ \x1b[3m";
		if( output[0] == output[1] && output[1] == output[2] ) {
			switch( output[0] ) {
				case 'B':
					cout << "Bagels";
					break;
				case 'F':
					cout << "3× Fermi\x1b[0m - \x1b[33mVyhrál jsi!";
					loop = 11;
					break;
				case 'P':
					cout << "3× Pico";
			}
		}
		else
		{
			for( int o = 0; o < 3; o++ ) {
				switch( output[o] ) {
					case 'F':
						cout << "Fermi ";
						break;
					case 'P':
						cout << "Pico ";
						break;
				}
			}
		}
		cout <<  "\x1b[0m" << endl;
	}
	if( loop == 10 ) {
		cout << "No nic. Nedals to..." << endl;
	}
	cout << "Myslel jsem si číslo \x1b[1m" << my_number[0] << my_number[1] << my_number[2] << "\x1b[0m." << endl;
		
	return 0;	
}
