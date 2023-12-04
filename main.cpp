#include<iostream>
#include <string>
using namespace std;

//creating borad of game 2D array of characters
char board[3][3]= { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char player1 = 'X';
char player2 = 'O';
int row, column;
string n1, n2;
char token='X';
bool tie=false;
char winner;
void create() {
	
	for (int i = 0;i <= 3;i++) {
		
			cout << "------------------" << endl;
			if (i == 3)
				break;
		
		cout << "     |     |     " << endl;
		cout << "  " << board[i][0] << "  |" << "  " << board[i][1] << "  |" << "  " << board[i][2] << "  " << endl; 
		cout << "     |     |     " << endl;

	}}
void getInput() {
	int digit;
	if (token == 'X') {
		
			cout << n1 << "please enter the position between 1 and 9 of " << player1 << endl;
			cin >> digit;
	}
	if (token == 'O') {
		
		cout << n2 << "please enter the position between 1 and 9 of " << player2 << endl;
		cin >> digit;
	}
	if (digit == 1) {
		row = 0;
		column = 0;
	}
	else if (digit == 2) {
		row = 0;
		column = 1;
		
	}
	else if (digit == 3) {
		row = 0;
		column = 2;
		
	}
	else if (digit == 4) {
		row = 1;
		column = 0;
		
	}
	else if (digit == 5) {
		row = 1;
		column = 1;
		
	}
	else if (digit == 6) {
		row = 1;
		column = 2;
		}
	else if (digit == 7) {
		row = 2;
		column = 0;
		
	}
	else if (digit == 8) {
		row = 2;
		column = 1;
		
	}
	else if (digit == 9) {
		row = 2;
		column = 2;
		
	}
	if (token == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
		board[row][column] = token;
		token = 'O';
	}
	else if (token == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
		board[row][column] = token;
		token = 'X';
	}
	else {
		cout << "there is no empty space" << endl;
		

	}

}
bool emptyOrNot() {
	for (int i = 0;i < 3;i++) {
			if ((board[i][0] == board[i][1]&& board[i][1] == board[i][2]) || (board[0][i] == board[1][i]&& board[0][i] == board[2][i])) 
			{
				//winner == board[i][0];
				return true;
			}
		
	}
	if (board[0][0] == board[1][1]&&board[1][1] == board[2][2])
		//winner == board[0][0];

		return true;
	if (board[0][2] == board[1][1]&& board[1][1] == board[2][0])
		//winner == board[0][2];

		return true;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if ( (board[i][j] != 'X' && board[i][j] != 'O'))
			{
				return false;
			}
		}
	}
	tie = true;
	winner = NULL;
	return false;

}
int main() {
	//enter names of players
	cout << "Please Enter your Name: " << endl;
	getline(cin, n1);
	cout << "Please Enter your Name: " << endl;

	getline(cin, n2);
	cout << n1 << " is the first player began the game" << endl;
	cout << n2 << " is the second player " << endl;

	while (!emptyOrNot()) 
	{
		create();
		getInput();
		

	}
	create();
	if (!tie) {
		if (token == 'O') {
			cout << n1 << " is the winner" << endl;
		}
		else if (token == 'X') {
			cout << n2 << " is the winner" << endl;
		}
	}
	else {
		cout << "it's a tie" << endl;
	}
	return 0;
}