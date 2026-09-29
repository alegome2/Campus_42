/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:57:52 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/29 15:34:56 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char  *mini_str;
    size_t  i;
    size_t  counter;
    size_t  cpy;
    
    i = 0;
    counter = 0;
    if (!s)
        return (NULL);
    while (s[counter])
        counter++;
    if (start >= counter)
        return(ft_strdup(""));
    if ((counter - start) < len)
        cpy = counter - start;
    else
        cpy = len;
    mini_str = malloc(cpy + 1);
    if (mini_str == NULL)
        return (NULL);
    while (i < cpy)
        mini_str[i++] = s[start++];
    mini_str[i] = '\0';
    return (mini_str);
}

/*int main(void)
{
    char *f;
    f = ft_substr("Buenos dias", 7, 2);
    printf("Subcadena: %s", f);
    free(f);
    return(0);   
}*/