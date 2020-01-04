#include <stdio.h>
#include <stdlib.h>

int		can_place_digit(char **field, int digit, int row, int col)
{
	for (int i = 0; i < 9; ++i)
		if (field[row][i] == digit + '0')
			return (0);
	for (int i = 0; i < 9; ++i)
		if (field[i][col] == digit + '0')
			return (0);
	for (int i = row / 3 * 3; i < row / 3 * 3 + 3; ++i)
		for (int j = col / 3 * 3; j < col / 3 * 3 + 3; ++j)
			if (field[i][j] == digit + '0')
				return (0);
	return (1);
}

int		solve(char **field)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (field[i][j] != '.')
				continue;
			for (int k = 1; k < 10; ++k)
			{
				if (can_place_digit(field, k, i, j))
				{
					field[i][j] = k + '0';
					if (solve(field))
						return (1);
					else
						field[i][j] = '.';
				}
			}
			return (0);
		}
	}
	return (1);
}

void print_solution(char **field)
{
	printf("\n\n");
	for (int i = 0; i < 9; ++i)
	{
		if ( !(i % 3))
			printf("\n");
		for (int j = 0; j < 9; ++j)
		{
			if (!(j % 3))
				printf(" ");
			printf("%2c", field[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	char **field = malloc(sizeof(void*) * 9);
	for (int i = 0; i < 9; ++i)
		field[i] = malloc(10);
	printf("Input your sudoku:\n");
	for (int i = 0; i < 9; ++i)
		scanf("%s", field[i]);
	if (solve(field))
		print_solution(field);
	else
		printf("There are no solutions for this sudoku!\n");
	for (int i = 0; i < 9; ++i)
		free(field[i]);
	free(field);
	return (0);
}
