/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:05:11 by hilal             #+#    #+#             */
/*   Updated: 2023/09/12 18:13:23 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compare_rest(const char *str, const char *find)
{
	while (*find && *str && *str == *find)
	{
		str++;
		find++;
	}
	if (*find == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		if (*str == *to_find)
		{
			if (compare_rest(str + 1, to_find + 1))
				return (str);
		}
		str++;
	}
	return (0);
}
