#define P1_SHAPE 'X'
#define P2_SHAPE 'O'

#define IS_P1_AI 0
#define IS_P2_AI 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_grid(char *grid_v);

void do_step(char player, char *grid_v, int ai);

int  check_win_condition(char *grid_v);

int main(void)
{
	char grid_v[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char current_player;
	char is_player_ai = 0;
	int  i;

	srand(time(NULL));

	current_player = (rand() % 2)? P1_SHAPE: P2_SHAPE;

	printf("Player '%c' begins\n", current_player);
	print_grid(grid_v);

	for (i = 0; i < 9; i++)
	{
		is_player_ai = (current_player == P1_SHAPE)? IS_P1_AI: IS_P2_AI;

		do_step(current_player, grid_v, is_player_ai);

		if (check_win_condition(grid_v))
		{
			printf("Winner: %c\n", current_player);
			print_grid(grid_v);

			return 0;
		}

		print_grid(grid_v);

		current_player = (current_player == P1_SHAPE)? P2_SHAPE: P1_SHAPE;
	}

	printf("It's a draw!\n");

	return 0;
}

void print_grid(char *grid_v)
{
	int i;

	for (i = 0; i < 9; i++)
	{
		printf("[%c]", grid_v[i]);

		if ((i + 1) % 3 == 0) printf("\n");
	}
}

void do_step(char player, char *grid_v, int ai)
{
	char position;

	do
	{
		printf("\n'%c' player's move\n", player);
		printf("Choose empty position with number (1-9): ");

		if (ai)
		{
			// TODO: something better than random
			while (grid_v[(position = rand() % 9)] == P1_SHAPE || grid_v[position] == P2_SHAPE)
				;
			printf("%d [AI]\n", position + 1);
		}
		else
		{
			scanf("%c", &position);
			getchar();
			position -= '1';
		}
	} while (position > 8 || grid_v[position] == P1_SHAPE || grid_v[position] == P2_SHAPE);

	grid_v[position] = player;
}

int  check_win_condition(char *grid_v)
{
	// checking diagonals
	if (grid_v[0] == grid_v[4] && grid_v[0] == grid_v[8]) return 1;
	if (grid_v[2] == grid_v[4] && grid_v[2] == grid_v[6]) return 1;

	int i;

	for (i = 0; i < 3; i++)
	{
		// checking cols
		if (grid_v[i] == grid_v[3 + i] && grid_v[i] == grid_v[6 + i]) return 1;
		// checking rows
		if (grid_v[i * 3] == grid_v[1 + i * 3] && grid_v[i * 3] == grid_v[2 + i * 3]) return 1;
	}

	return 0;
}
