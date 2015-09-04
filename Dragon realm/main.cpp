#include <iostream>
#include <string>
#include <random>
#include <unistd.h>
using namespace std;

void print_text( string text, bool new_line = true )
{
	for( int i = 0; i < text.length(); i++ )
	{
		cout << text[i];
		cout.flush();
		usleep(50000);
	}
	if( new_line )
	{
		cout << endl;
	}
}

int main()
{
	random_device rd;
	uniform_int_distribution<int> dist(1, 2);
	string input;
	char cave_number;
	char friendly_cave;

	switch( dist(rd) )
	{
		case 1:
			friendly_cave = '1';
			break;
		case 2:
			friendly_cave = '2';
			break;
	}

	cout << endl;

	print_text("Jsi v zemi plné draků. Před sebou vidíš dvě\n\
jeskyně. V jedné žije drak Přátelák, který bude s tebou\n\
sdílet svoje bohatství. Druhý drak, žijící v druhé\n\
jeskyni, je chamtivý a hladový, a sní tě hned po prvním pohledu."); 
	print_text("Do které jeskyně se vydáš (1 nebo 2)? \x1b[33m", false);

	getline(cin, input);
	while( cave_number != '1' && cave_number != '2')
	{
		if( input.length() == 1 && ( input == "1" || input == "2" ) )
		{
			cave_number = input[0];
			break;
		}
		print_text("\x1b[0mJsou tam dvě jeskyně \x1b[1m(1 a 2)\x1b[0m! \x1b[33m", false);
		getline(cin, input);
	}
	
	cout << "\x1b[0m";
	usleep(1500000);
	print_text("Vešel jsi do jeskyně...");
	usleep(1500000);
	print_text("Je tam tma a je to tam strašidelné...");
	usleep(1500000);
	print_text("Velký drak skočil před tebe! Otevřel svou obrovskou tlamu a...");
	usleep(1500000);

	if( cave_number == friendly_cave )
	{
		cout << "\x1b[32mDává ti svůj poklad!\x1b[0m" << endl;
	}
	else
	{
		cout << "\x1b[31mPolyká tě v jednom soustu!\x1b[0m" << endl;
	}

	cout << endl;

	return 0;
}
