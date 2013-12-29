#include <stdio.h>

int h, w, count, datacentre[100][100],solution_count, owned;

void solution (int, int);
void check_endpoint (int, int);

void main ()
{
	int i, j;
	int intake_i, intake_j, conditioner_i, conditioner_j;
	owned = 0;
	count = 0;
	solution_count = 0;
	scanf ("%d%d", &w, &h);
	for (i=0; i<h; i++)
		for (j=0; j<w; j++)
			scanf("%d", &datacentre[i][j]);
	
	for (i=0; i<h; i++)
		for (j=0; j<w; j++)
		{
			if (datacentre[i][j] == 2)
			{
				intake_i = i;
				intake_j = j;
			}
			else if(datacentre[i][j] == 3)
			{
				conditioner_i = i;
				conditioner_j = j;
			}
			if (datacentre[i][j] == 0)
			{
				owned += 1;
			}
		}
	//printf ("%d\n", owned);
	solution (intake_i, intake_j);
	printf ("%d", solution_count);
}

void solution(int i, int j)
{
	//printf("I'm here at the solution()\n");
	if (i < h-1 && datacentre[i+1][j] == 0)
	{
		//Move one step down
		i++;
		datacentre[i][j] = 4;
		count++;
		solution (i, j);
		datacentre[i][j] = 0;
		count--;
		i--;
	}
	if (i > 0 && datacentre[i-1][j] == 0)
	{
		//Move one step up
		i--;
		datacentre[i][j] = 4;
		count++;
		solution (i, j);
		datacentre[i][j] = 0;
		count--;
		i++;
	}
	if (j < w-1 && datacentre[i][j+1] == 0)
	{
		//Move one step right
		j++;
		datacentre[i][j] = 4;
		count++;
		solution (i,j);
		datacentre[i][j] = 0;
		count--;
		j--;
	}
	if (j > 0 && datacentre[i][j-1] == 0)
	{
		//Move one step left
		j--;
		datacentre[i][j] = 4;
		count++;
		solution (i,j);
		datacentre[i][j] = 0;
		count--;
		j++;
	}
	if (count == owned)
		check_endpoint (i,j);
}

void check_endpoint (int i, int j)
{
	//printf ("I'm here at check_endpoint()\n");
	if (datacentre[i+1][j] == 3)
	{
		solution_count++;
		return;
	}
	else if (datacentre[i-1][j] == 3)
	{
		solution_count++;
		return;
	}
	else if (datacentre[i][j+1] == 3)
	{
		solution_count++;
		return;
	}
	else if (datacentre[i][j-1] == 3)
	{
		solution_count++;
		return;
	}
}