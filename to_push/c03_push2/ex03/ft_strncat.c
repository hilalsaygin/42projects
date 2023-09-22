/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:38:03 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/20 01:01:24 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	lend;
	char			*p;

	lend = ft_strlen(dest);
	p = dest + lend;
	while (*src != '\0' && nb--)
		*p++ = *src++;
	*p = '\0';
	return (dest);
}
