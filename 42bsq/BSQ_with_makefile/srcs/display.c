/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:34:21 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/20 19:34:24 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static void	print_bsq(t_map *obj)
{
	(void)!write(1, &obj->map[obj->n], obj->nbr_lines * (obj->len_lines + 1));
}

static void	paint_bsq(t_map *obj, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	top_left_x;
	unsigned int	top_left_y;

	top_left_x = obj->bsq_x - matrix[obj->bsq_y][obj->bsq_x] + 1;
	top_left_y = obj->bsq_y - matrix[obj->bsq_y][obj->bsq_x] + 1;
	y = 0;
	while (y <= obj->nbr_lines)
	{
		x = 0;
		while (x <= obj->len_lines)
		{
			if ((y >= top_left_y && y <= obj->bsq_y)
				&& (x >= top_left_x && x <= obj->bsq_x))
				obj->map[(y * (obj->len_lines + 1)) + x + obj->n] = obj->filler;
			x++;
		}
		y++;
	}
}

void	display_bsq(t_map *obj, unsigned short **matrix)
{
	paint_bsq(obj, matrix);
	print_bsq(obj);
}
