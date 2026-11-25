/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 11:51:40 by alegome2          #+#    #+#             */
/*   Updated: 2026/11/25 10:40:14 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	*free_all(char **str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	is_sep(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	word_count(char const *str)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] && !is_sep(str[0]))
		counter++;
	while (str[i])
	{
		if (is_sep(str[i - 1]) && !is_sep(str[i]))
			counter++;
		i++;
	}
	return (counter);
}

static char	**fill_words(char const *s, char **str)
{
	int	i;
	int	w;
	int	len;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (is_sep(s[i]))
			i++;
		len = 0;
		if (s[i])
		{
			while (!is_sep(s[i + len]) && s[i + len])
				len++;
			str[w] = ft_substr(s, i, len);
			if (!str[w])
				return (free_all(str));
			w++;
			i = i + len;
		}
	}
	str[w] = NULL;
	return (str);
}

char	**ft_split(char const *s)
{
	int		counter;
	char	**str;

	if (!s)
		return (NULL);
	counter = word_count(s);
	str = malloc((counter + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (fill_words(s, str));
}
