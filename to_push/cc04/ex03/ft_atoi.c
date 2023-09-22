/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:18:53 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/19 23:21:13 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_space_sign(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while (str[i] <= 32 || str[i] == 127)
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = check_space_sign(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}
