/*
	419. Battleships in a Board
	Robert Clark, JUL 17 2021
	
	"Given an m x n matrix board where each cell is a battleship 'X' or empty '.', 
	return the number of the battleships on board.

	Battleships can only be placed horizontally or vertically on board. In other words,
	they can only be made of the shape 1 x k (1 row, k columns) or 
	k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or 
	vertical cell separates between two battleships (i.e., there are no 
	adjacent battleships)."
*/

using namespace std;
#include <iostream>
#include <vector>

int countBattleships(vector<vector<char>>& board) 
{
	int m = board.size(); //height of the board, or number of rows
	int n = board[0].size(); //width of the board, or number of columns
	int numShips = 0; //number of ships on the board

	//try to find the beginning of a ship
	//we only need to find the top/left corner of a ship
	//note to self: vectorName[y][x], or vectorName[ud][lr]
	for (int i = 0; i < m; i++) //i is the row
	{
		for (int j = 0; j < n; j++) //j is the column
		{
			if (board[i][j] == 'X') 
			{
				if (j == 0 && i == 0)
					numShips++;
				else if (j == 0)
				{
					if (board[i - 1][j] != 'X')
						numShips++;
				}
				else if (i == 0)
				{
					if (board[i][j - 1] != 'X')
						numShips++;
				}
				else if (board[i-1][j] != 'X' && board[i][j-1] != 'X')
					numShips++;
			}//end if statement
		}//end for loop
	}//end for loop

	return numShips;

}//end countBattleships method
  
int main()
{
	int numShips = 0; //the number of ships on each board
	
	//first board
		vector<vector<char>> board1 //the first board
		{
			{'X','.','.','X'},
			{'.','.','.','X'},
			{'.','.','.','X'}
		};
		
		int m = board1.size(); //height of the board, or number of rows
		int n = board1[0].size(); //width of the board, or number of columns
		
		for (int i = 0; i < m; i++) //i is the row
		{
			for (int j = 0; j < n; j++) //j is the column
			{
				cout << board1[i][j] << "\t";
			}
			
			cout << "\n";
		}
		
		numShips = countBattleships(board1);
		
		cout << "\n" << "There are " << numShips << " ships on this board";
	
	//second board
	
		vector<vector<char>> board2 //the second board
		{
			{'.'}
		};
		
		m = board2.size(); //height of the board, or number of rows
		n = board2[0].size(); //width of the board, or number of columns
		
		cout << "\n\n";
		
		for (int i = 0; i < m; i++) //i is the row
		{
			for (int j = 0; j < n; j++) //j is the column
			{
				cout << board2[i][j] << "\t";
			}
			
			cout << "\n";
		}
		
		numShips = countBattleships(board2);
		
		cout << "\n" << "There are " << numShips << " ships on this board";
		
	//second board
	
		vector<vector<char>> board3 //the second board
		{
			{'X', 'X', 'X'}
		};
		
		m = board3.size(); //height of the board, or number of rows
		n = board3[0].size(); //width of the board, or number of columns
		
		cout << "\n\n";
		
		for (int i = 0; i < m; i++) //i is the row
		{
			for (int j = 0; j < n; j++) //j is the column
			{
				cout << board3[i][j] << "\t";
			}
			
			cout << "\n";
		}
		
		numShips = countBattleships(board3);
		
		cout << "\n" << "There are " << numShips << " ships on this board";
	
	return 0;
}//end main method