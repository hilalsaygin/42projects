/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:05:07 by hilal             #+#    #+#             */
/*   Updated: 2023/09/12 18:12:47 by hilal            ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int		lend;
	char	*p;

	lend = ft_strlen(dest);
	p = dest + lend;
	while (*src != '\0' && nb--)
		*p++ = *src++;
	*p = '\0';
	return (dest);
}
