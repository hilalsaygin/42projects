/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:40:54 by hilal             #+#    #+#             */
/*   Updated: 2023/09/18 00:21:26 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	current;
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		current = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > current)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = current;
		i++;
	}
}
