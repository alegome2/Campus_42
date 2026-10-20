#include <unistd.h>

void	rush01 (char matriz[4][4])
{
	int	i;
	int	j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			write(1, &matriz[i][j], 1);
			write(1, " ", 1);
			j++;
		}
	write(1, "\n", 1);
	i++;
	}
}



int	main(void)
{

char	matriz[4][4] = {{'1', '2', '3', '4'}, {'4', '5', '6', '7'}, {'1', '2', '3', '4'}, {'1', '2', '3', '4'}};

	rush01(matriz);
	return(0);
}


