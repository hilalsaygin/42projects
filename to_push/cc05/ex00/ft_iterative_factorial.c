/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:11:01 by hilal             #+#    #+#             */
/*   Updated: 2023/09/15 20:11:02 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	factorial;
	int	index;

	if (nb < 0)
		return (0);
	index = 1;
	factorial = 1;
	while (index < nb + 1)
		factorial = factorial * index++;
	return (factorial);
}
