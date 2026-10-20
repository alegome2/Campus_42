#include <unistd.h>
#include <stdio.h>

void ft_reverso(char *str)
{
	int	i;
	int	j;
	char temp;
	i = 0;
	j = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	while (j < i)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i--;
		j++;
	}
	j = 0;
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
}

int	main(void)
{
	char str[50] = "hola mundo";

	ft_reverso(str);
	return (0);
}
