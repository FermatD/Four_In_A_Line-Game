#define ROWS 5
#define COLS 5


typedef char TBoard[ROWS][COLS];

// ****************************************************************************
// Sub Program: is_aligned
// Purpose: Verifies if the discs of a player are aligned Vertically, horizontally,
// or diagonally. Return 1 if the discs are aligned and 0 otherwise
//
// ****************************************************************************
int is_aligned(TBoard tab)
{
	int row, col, aligned = 0;

	//Horizontal check (along the rows)
	for(row = 0; row < ROWS; row++)
	{
		for(col = 0; col < COLS - 3; col++)
		{
			if (tab[row][col] != ' ' && tab[row][col] == tab[row][col+1] &&
                tab[row][col] == tab[row][col+2] && tab[row][col] == tab[row][col+3])
			{
				aligned = 1;
			}
		}
	}

	//Vertical check (along the columns)
	for(col = 0; col < COLS; col++)
	{
		for(row = 0; row < ROWS - 3; row++)
		{
			if (tab[row][col] != ' ' && tab[row][col] == tab[row+1][col] &&
                tab[row][col] == tab[row+2][col] && tab[row][col] == tab[row+3][col])
			{
				aligned = 1;
			}
		}
	}

	//Leading diagonal check (top left corner to bottom right corner)
	for(row = 0; row < ROWS - 3; row++)
	{
		for(col = 0; col < COLS - 3; col++)
		{
			if (tab[row][col] != ' ' && tab[row][col] == tab[row+1][col+1] &&
                tab[row][col] == tab[row+2][col+2] && tab[row][col] == tab[row+3][col+3])
			{
				aligned = 1;
			}
		}
	}

	//Counter diagonal check (top right corner to bottom left corner
	for(row = 0; row < ROWS - 3; row++)
	{
		for(col = COLS-1; col > 2; col--)
		{
			if (tab[row][col] != ' ' && tab[row][col] == tab[row+1][col-1] &&
                tab[row][col] == tab[row+2][col-2] && tab[row][col] == tab[row+3][col-3])
			{
				aligned = 1;
			}
		}
	}

	return aligned;
}

// ****************************************************************************
// Sub Program: empty_grid
// Purpose: Sets the grid cells to empty.
// ****************************************************************************
void empty_grid(TBoard tab){		//Subprogram to empty the grid
	int i, j;

	for(i = 0; i< ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			tab[i][j]=' ';
		}
	}
}


