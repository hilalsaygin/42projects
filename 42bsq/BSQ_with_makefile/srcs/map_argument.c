/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:33:48 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/20 19:47:35 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

bool	map_argument(t_map *obj)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	while (obj->map[i] && obj->map[i] != '\n')
		i++;
	if (!obj->map[i] || !obj->map[i + 1])
		return (ft_pser("Error: map error\t(file need more than one line)\n"));
	obj->n = i + 1;
	obj->filler = obj->map[--i];
	obj->obstacle = obj->map[--i];
	obj->empty = obj->map[--i];
	if (obj->empty == obj->filler || obj->empty == obj->obstacle
		|| obj->filler == obj->obstacle)
		return (ft_pser("Error: map error\t(map char can't be the same)\n"));
	x = 0;
	obj->nbr_lines = 0;
	while (x < i)
	{
		if (obj->map[x] > '9' || obj->map[x] < '0')
			return (ft_pser("Error: map error\t(nbr_lines isn't a number)\n"));
		obj->nbr_lines = obj->nbr_lines * 10 + obj->map[x++] - '0';
	}
	return (true);
}

bool	read_len_lines(t_map *obj)
{
	unsigned int	i;

	if (obj->nbr_lines == 0)
		return (ft_pser("Error: map error\t(nbr_lines can't be equal to 0)\n"));
	i = obj->n;
	while (obj->map[i] && obj->map[i] != '\n')
		i++;
	obj->len_lines = i - obj->n;
	if (obj->len_lines == 0)
		return (ft_pser("Error: map error\t(len_lines can't be equal to 0)\n"));
	return (true);
}
