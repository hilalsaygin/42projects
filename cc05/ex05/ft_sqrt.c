/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:11:39 by hilal             #+#    #+#             */
/*   Updated: 2023/09/15 20:21:07 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int		index;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	index = 0;
	while ((index * index) <= (unsigned int)nb)
		index++;
	index -= 1;
	if (index * index == (unsigned int)nb)
	{
		return (index);
	}
	return (0);
}
