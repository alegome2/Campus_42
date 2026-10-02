/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alegome2 <alegome2@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/30 12:41:54 by alegome2         #+#    #+#              */
/*   Updated: 2026/10/02 17:15:33 by alegome2        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordCount(char const *str, char c)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] && str[0] != c)
		counter++;
	while (str[i])
	{
		if (str[i - 1] == c && str[i] != c)
			counter++;
		i++;
	}
	return (counter);
}

static void	*freeMemory(char **str, int w)
{
	while (w >= 0)
	{
		free(str[w]);
		w--;
	}
	free(str);
	return (NULL);
}

static char	**fillWords(char const *s, char c, char **str)
{
	int	i;
	int	w;
	int	len;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = 0;
		if (s[i])
		{
			while (s[i + len] != c && s[i + len])
				len++;
			str[w] = ft_substr(s, i, len);
			if (!str[w])
				return (freeMemory(str, w));
			w++;
			i = i + len;
		}
	}
	str[w] = NULL;
	return (str);
}

/****************           FUNCION PRINCIPAL           ****************/

char	**ft_split(char const *s, char c)
{
	int		counter;
	char	**str;

	if (!s)
		return (NULL);
	counter = wordCount(s, c);
	str = malloc((counter + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (fillWords(s, c, str));
}

/*
From a unique string separate in few words
*/

/*int	main(void)
{
char	*str = "Viva el Real Betis Balompie";
char	**res;
int		i;

res = ft_split(str, ' ');
if (!res)
return (1);
i = 0;
while (res[i] != NULL)
{
printf("Palabra %d: %s\n", i, res[i]);
i++;
}
return (0);
}*/
