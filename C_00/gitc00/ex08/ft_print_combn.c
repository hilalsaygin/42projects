/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:29:01 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/14 19:23:00 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_count = 0;

int	ft_srtlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

void	ft_sprintf(char *dest, char *str, int i)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		dest[index] = str[index];
		index++;
	}
	dest[index] = (i + '0');
	dest[index + 1] = '\0';
}

int	comb_g_count(int *n)
{
	int	numinator;
	int	dominator;
	int	iter;
	int	d;
	int	digit;

	digit = *n;
	iter = 10 - (10 - digit);
	numinator = 1;
	dominator = 1;
	d = 10;
	while (iter-- > 0)
	{
		numinator *= d;
		d--;
	}
	iter = 10 - (10 - digit);
	while (iter-- > 0)
	{
		dominator *= digit;
		digit--;
	}
	return (numinator / dominator);
}

void	find_combn(int start, char *s, int n, int *digit)
{
	int		i;
	char	str2[15];

	if (n == 0)
	{
		write (1, s, ft_srtlen(s));
		g_count = g_count +1;
		if (g_count != comb_g_count(digit))
			write (1, ", ", 2);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		ft_sprintf(str2, s, i);
		find_combn(i + 1, str2, n - 1, digit);
		i++;
	}
}

void	ft_print_combn(int n)
{
	if (n > 0 && n < 10)
		find_combn(0, "", n, &n);
}
