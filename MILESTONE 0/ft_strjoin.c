/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:03:38 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/29 18:16:33 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t     len1;
    size_t     len2;
    char *str;
    size_t     tam;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    tam = len1 + len2;
    str = malloc((tam + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    ft_memcpy(str, s1, len1);
    ft_memcpy(str + len1, s2, len2);
    str[tam] = '\0';
    return (str);
}

int main(void)
{
    char *s1 = "Viva ";
    char *s2 = "el Betis";
    char *strC;
    
    strC = ft_strjoin(s1, s2);
    printf("Joined: %s\n", strC);
    free(strC);
    return (0);
}