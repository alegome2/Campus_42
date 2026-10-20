/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:30:28 by username          #+#    #+#             */
/*   Updated: 2026/10/19 19:25:05 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *ptr);
int		ft_print_int(int n);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_hex(unsigned long nb, char *base);
char	*ft_itoa(int n);

#endif
