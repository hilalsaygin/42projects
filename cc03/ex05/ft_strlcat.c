/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:06:17 by hilal             #+#    #+#             */
/*   Updated: 2023/09/12 18:13:54 by hilal            ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int		lend;
	char	*p;

	lend = ft_strlen(dest);
	p = dest + lend;
	while (*src != '\0' && --size > 0)
		*p++ = *src++;
	*p = '\0';
	return (lend + ft_strlen(src));
}
