/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:03:38 by hilal             #+#    #+#             */
/*   Updated: 2023/09/15 21:04:10 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0' )
	{
		if (!(is_numeric(str[index])))
			return (0);
		index++;
	}
	return (1);
}

int	main(void)
{
	if (ft_str_is_numeric("234"))
		write(1, " 1 ", 3);
}
