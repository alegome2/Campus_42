/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:00:51 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/11 12:45:50 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	ft_strcpy(char *str, char *copy)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (*copy);
}

char	*ft_strdup(char *src)
{
	char	*duplicate;	

	duplicate = (char *) malloc ((ft_strlen(src) + 1) * sizeof(char));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	ft_strcpy(src, duplicate);
	return (duplicate);
}

//CON ARGUMENTOS

/*int	main(int argc, char **argv)
{
	if (argc <= 1)
		printf("Debes meter algun argumento por pantalla\n");
	else if (argc >= 3)
		printf("Debes meter solo un argumento por pantalla\n");
	else
		printf("Se ha copiado la cadena: %s\n", ft_strdup(argv[1]));
	free(ft_strdup(argv[1]));
	return (0);
}*/

// SIN ARGUMENTOS

/*int	main(void)
{
	char	*src;
	char	*dest;

	src = "Hola mundo";
	dest = ft_strdup(src);

	if (dest == NULL)
		return (0);
	printf("La cadena raiz es: %s\n", src);
	printf("La cadena destino es: %s\n", dest);
	free(dest);
	return (0);
}*/
