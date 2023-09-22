/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:37:57 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/20 00:56:54 by rsaygin          ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	lend;
	char			*p;

	lend = ft_strlen(dest);
	p = dest + lend;
	while (*src != '\0')
		*p++ = *src++;
	*p = '\0';
	return (dest);
}
