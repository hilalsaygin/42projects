/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:29:36 by hilal             #+#    #+#             */
/*   Updated: 2023/09/16 00:30:14 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0' )
	{
		if (!(is_upper(str[index])))
			return (0);
		index++;
	}
	return (1);
}

int	main(void)
{
	if (ft_str_is_lowercase("FDS"))
		write(1, " 1 ", 3);
}
