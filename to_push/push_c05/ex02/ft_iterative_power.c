/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:11:15 by hilal             #+#    #+#             */
/*   Updated: 2023/09/15 20:15:17 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int		result;

	if (power < 0)
		return (0);
	result = 1;
	while (power-- > 0)
		result *= nb;
	return (result);
}
