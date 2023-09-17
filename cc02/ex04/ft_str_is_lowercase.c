/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:07:18 by hilal             #+#    #+#             */
/*   Updated: 2023/09/15 21:07:19 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0' )
	{
		if (!(is_lower(str[index])))
			return (0);
		index++;
	}
	return (1);
}

int	main(void)
{
	if (ft_str_is_lowercase("sdfSg"))
		write(1, " 1 ", 3);
}
