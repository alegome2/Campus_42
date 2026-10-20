#include <unistd.h>

int	funcion(char *argv)
{
	int	i;
	i = 0;
	while(argv[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	a;
	i = 0;
	a = funcion(argv[0]);

	while(argv[0][i] != '\0')
	{
		write(1, &argv[0][i], a);
		i++;
	}
	return(0);
}
