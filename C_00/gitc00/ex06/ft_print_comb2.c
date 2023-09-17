/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:53 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/17 14:00:52 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(48 + nb % 10);
	}
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
