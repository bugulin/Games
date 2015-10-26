#include <iostream>
#include <random>
using namespace std;

char board [9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char me;
char comp;
random_device rd;

void draw_board()
{
	cout << endl;
	for( int y = 6; y >= 0; y -= 3 )
	{
		cout << "\t";
		for( int x = y; x < y+3; x++ )
		{
			if( board[x] == 'X' )
			{
				cout << "\x1b[31mX\x1b[0m";
			}
			else if( board[x] == 'O' )
			{
				cout << "\x1b[34mO\x1b[0m";
			}
			else
			{
				cout << "\x1b[33m" << x+1 << "\x1b[0m";
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool input_is_ok( int input )
{
	if( input > 0 && input < 10 )
	{
		if( board[input-1] == ' ' )
		{
			return true;
		}
	}
	return false;
}

char is_winner( char board[] )
{
	// horizontal (|)
	for( int i = 6; i < 9; i++ )
	{
		if( board[i] == board[i-3] && board[i-3] == board[i-6] && board[i] != ' ' )
		{
			return board[i];
		}
	}
	// vertical (-)
	for( int i = 0; i <= 6; i+=3 )
	{
		if( board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != ' ' )
		{
			return board[i];
		}
	}
	// \ /
	if( ( board[0] == board[4] && board[4] == board[8] && board[0] != ' ' ) || ( board[2] == board[4] && board[4] == board[6] && board[2] != ' ' ) )
	{
		return board[4];
	}
	return ' ';
}

int get_comp_move()
{
	// Comp can win in the next move
	for( int i = 0; i < 9; i++ )
	{
		char board_copy[9];
		for( int a = 0; a < 9; a++ )
		{
			board_copy[a] = board[a];
		}
		if( board_copy[i] == ' ' )
		{
			board_copy[i] = comp;
			if( is_winner( board_copy ) == comp )
			{
				return i;
			}
		}
	}
	
	// Player can win in the move after comp
	for( int i = 0; i < 9; i++ )
	{
		char board_copy[9];
		for( int a = 0; a < 9; a++ )
		{
			board_copy[a] = board[a];
		}
		if( board_copy[i] == ' ')
		{
			board_copy[i] = me;
			if( is_winner( board_copy ) == me )
			{
				return i;
			}
		}
	}

	// Try to take one of corners
	if (board[0] == ' ' || board[2] == ' ' || board[6] == ' ' || board[8] == ' ')
	{
		int free_places [4] = {0, 0, 0, 0};
		int free = 0;
		for( int i = 0; i < 9; i+=2 )
		{
			if( i == 4 )
			{
				i += 2;
			}
			if( board[i] == ' ' )
			{
				free_places[free] = i;
				free++;
			}
		}

		uniform_int_distribution<int> dist( 0, free-1 );
		return free_places[dist(rd)];
	}
	// Try to take the center
	else if( board[4] == ' ' )
	{
		return 4;
	}
	// Move on one of the sides
	else {
		int free_places [4] = {0, 0, 0, 0};
		int free = 0;
		for( int i = 1; i < 9; i+=2 )
		{
			if( board[i] == ' ' )
			{
				free_places[free] = i;
				free++;
			}
		}
		
		uniform_int_distribution<int> dist( 0, free-1 );
		return free_places[dist(rd)];
	}
}

int main()
{
	cout << "Vítej ve hře Piškvorky!" << endl;
	cout << "Chceš být X nebo O? ";
	cin >> me;
	if( me == 'X' )
	{
		comp = 'O';
	}
	else
	{
		comp = 'X';
	}

	uniform_int_distribution<int> dist(0, 1);
	bool turn;
	if( dist(rd) == 0 )
	{
		cout << "Počítač hraje první." << endl;
		turn = false;
	}
	else
	{
		cout << "Začínáš." << endl;
		turn = true;
	}

	// Main game loop
	int move;
	char winner = ' ';
	for( int i = 0; i < 9; i++)
	{
		if( turn )
		{
			if( i > 1 )
			{
				cout << "\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A                    \n";
			}
			draw_board();
			cout << "Tvůj tah [1-9]: ";
			cin >> move;
			
			while( !input_is_ok(move) )
			{
				cout << "Jaký je tvůj příští tah [1-9]? ";
				cin >> move;
			}
			board[move-1] = me;
		}
		else
		{
			board[get_comp_move()] = comp;
		}

		turn = !turn;
		winner = is_winner(board);
		if( winner != ' ')
		{
			break;
		}
	}
	
	cout << "\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A" << endl;
	draw_board();
	if( winner == me )
	{
		cout << "Gratuluji. Vyhrál jsi!" << endl;
	}
	else if( winner == ' ' )
	{
		cout << "Remíza. Nyní tu není žádný vítěz ani žádný poražený..." << endl;
	}
	else
	{
		cout << "Ne. To je prohra..." << endl; 
	}

	return 0;
}
