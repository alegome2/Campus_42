#include <unistd.h>

void funcion (void)
{
	char digito1;
	char digito2;
	int contador;
	char str1[] = "buzz";
	char str2[] = "fizz";

	digito1 = '0';
	digito2 = '0';
	contador = 1;	
//	str1 = "buzz";
//	str2 = "fizz";

	while(digito2 <= '9')
	{
//		write(1, &digito2, 1);
//		digito2++;
		while(digito1 <= '9')
		{
			if (contador % 4 == 0 && contador % 7 == 0)
			{
			    write(1, &str1, 4);
			    write(1, &str2, 4);
			}
			if (contador % 4 == 0)
			{
			 	 write(1, &str1, 4);
			}
			if (contador % 7 == 0)
			{
				    write(1, &str2, 4);
			}
			if(!(contador % 4 == 0 && contador % 7 == 0))
			{
				write(1, &digito2, 1);
				write(1, &digito1, 1);
				write(1, "\n", 1);
			}
			digito1++;
			contador++;
		}
		digito2++;
		digito1 = '0';
	}
}

int main (void)
{
	funcion();
	return(0);
}
