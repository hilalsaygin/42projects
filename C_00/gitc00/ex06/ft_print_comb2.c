/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:53 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/14 20:09:57 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_digits[20];

void	ft_putnbr(int nb)
{
	int	div;
	int	count;

	div = nb;
	count = 0;
	if (div == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (div < 0)
	{
		write(1, "-", 1);
		div = (-div);
	}
	while (div > 0)
	{
		g_digits[count] = (div % 10) + '0';
		div = div / 10;
		count++;
	}
	while ((--count) >= 0)
		write(1, &g_digits[count], 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= 99)
	{
		while (j <= 99)
		{
			if (i <= 9)
				write(1, &"0", 1);
			ft_putnbr(i);
			write(1, &" ", 1);
			if (j <= 9)
				write(1, &"0", 1);
			ft_putnbr(j);
			if (i == 98 && j == 99)
				return ;
			write(1, &", ", 2);
			j++;
		}
		i++;
		j = i + 1;
	}
}
