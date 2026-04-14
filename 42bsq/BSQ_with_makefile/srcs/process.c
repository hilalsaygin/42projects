/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:34:41 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/20 19:34:46 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static void	process_empty(t_map *obj, unsigned short **matrix,
	unsigned int x, unsigned int y)
{
	unsigned short	tmp;

	if (x == 0 || y == 0)
		matrix[y][x] = 1;
	else
	{
		if (matrix[y - 1][x] > matrix[y][x - 1])
			tmp = matrix[y][x - 1];
		else
			tmp = matrix[y - 1][x];
		if (tmp > matrix[y - 1][x - 1])
			matrix[y][x] = matrix[y - 1][x - 1] + 1;
		else
			matrix[y][x] = tmp + 1;
		if (matrix[y][x] > matrix[obj->bsq_y][obj->bsq_x])
		{
			obj->bsq_y = y;
			obj->bsq_x = x;
		}
	}
}

static bool	process_end_check(t_map *obj,
	unsigned int *x, unsigned int *y, unsigned int i)
{
	if (obj->map[i] == '\n')
	{
		if (x[0] != obj->len_lines)
			return (ft_pser("(all lines should be the same length)\n"));
		x[0] = -1;
		y[0] += 1;
	}
	else
		return (ft_pser(
				"Error: map error\t(lines not same lenght)\n"));
	return (true);
}

bool	process(t_map *obj, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	i = obj->n;
	x = 0;
	y = 0;
	while (i < (obj->len_lines + 1) * obj->nbr_lines)
	{
		if (y >= obj->nbr_lines)
			return (ft_pser(
					"Error: map error\t(lines more than argument lines)\n"));
		else if (obj->map[i] == obj->empty)
			process_empty(obj, matrix, x, y);
		else if (obj->map[i] == obj->obstacle)
			matrix[y][x] = 0;
		else if (!process_end_check(obj, &x, &y, i))
			return (false);
		i++;
		x++;
	}
	return (true);
}
