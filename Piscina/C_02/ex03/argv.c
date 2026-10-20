#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0') && (str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	is_numeric;
	if(argc >= 2)
	{ 
	is_numeric = ft_str_is_numeric(argv[1]);
	printf("%i\n", is_numeric);
	}
	else printf("Error");
	return (0);
}
