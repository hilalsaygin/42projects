/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:57 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/14 20:06:30 by rsaygin          ###   ########.fr       */
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
		if(div == -2147483648)
		{
			div = div / 10;
			g_digits[i] = 8 + '0';
			i++;
		}
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
