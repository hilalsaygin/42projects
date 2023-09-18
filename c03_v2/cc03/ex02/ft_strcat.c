/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:27:38 by hilal             #+#    #+#             */
/*   Updated: 2023/09/12 15:27:39 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		lend;
	char	*p;

	lend = ft_strlen(dest);
	p = dest + lend;
	while (*src != '\0')
		*p++ = *src++;
	*p = '\0';
	return (dest);
}
