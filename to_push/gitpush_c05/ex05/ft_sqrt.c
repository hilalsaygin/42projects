/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:11:39 by hilal             #+#    #+#             */
/*   Updated: 2023/09/20 12:35:52 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	index;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	index = 1;
	while ((index * index) <= nb)
		index++;
	index -= 1;
	if (index * index == nb)
	{
		return (index);
	}
	return (0);
}
