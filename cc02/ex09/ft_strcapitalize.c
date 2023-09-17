/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:58:15 by hilal             #+#    #+#             */
/*   Updated: 2023/09/18 00:53:22 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_alphanum(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else if ((ch >= '0' && ch <= '9'))
		return (0);
	return (-1);
}

int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	index;
	int	new_word;

	index = 0;
	new_word = 1;
	while (str[index] != '\0')
	{
		if (new_word)
		{
			if (is_alphanum(str[index]) && is_lower(str[index]))
			{
				str[index] = str[index] -32;
				new_word = 0;
			}
			else if (is_alphanum(str[index]) == 0)
				new_word = 0;
			else if (is_alphanum(str[index]) == -1)
				new_word = 1;
		}
		else
		{
			if (is_alphanum(str[index]) && is_upper(str[index]))
				str[index] = str[index] +32;
			else if (is_alphanum(str[index]) == 0)
				new_word = 0;
			else if (is_alphanum(str[index]) == -1)
				new_word = 1;
		}
		index++;
	}
	return (str);
}