/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:43:55 by hilal             #+#    #+#             */
/*   Updated: 2023/09/16 00:57:17 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	char	c;
	int		index;

	index = 0;
	while (str[index] != '\0' )
	{
		c = str[index];
		if (c >= 'A' && c <= 'Z')
		{
			str[index] = c + ('a' - 'A');
		}
		index++;
	}
	return (str);
}
