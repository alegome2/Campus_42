#include <unistd.h>

void	ft_funcion(void)
{
	char abc;
	
	abc = 'z';

	while (abc >= 'a')
	{
		if (abc % 2 != 0)
		{
			write(1 , &abc, 1);
			abc--;
		}
		else
		{
			abc = abc -32;
			write(1, &abc, 1);
			abc += 32;
			abc--;
		}
	}
}

int	main(void)
{
	ft_funcion();
	return (0);
}
