#include <unistd.h>
int	int_str(int nb)
{
	char	c;

	if(nb >= 10)
	{
		int_str(nb/10);
	}
	c = nb%10 + '0';
	write(1, &c, 1);
	return (0);
}
int	main(void)
{
	int counter = 1;
	while(counter <= 100)
	{
		if(counter % 4 == 0 & counter % 7 == 0)
		{
			write(1, "fizzbuzz", 8);
		}else if(counter % 4 == 0)
		{
			write(1, "fizz", 4);
		}else if(counter % 7 == 0)
		{
			write(1, "buzz", 4);
		}else
		{
		int_str(counter);
		}
		write(1,"\n",1);
		counter++;
	}
	return (0);
}
