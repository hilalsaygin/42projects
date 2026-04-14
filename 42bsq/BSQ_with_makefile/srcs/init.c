/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:33:41 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/20 19:47:08 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	init_map(t_map *data)
{
	data->nbr_lines = 0;
	data->len_lines = 0;
	data->bsq_x = 0;
	data->bsq_y = 0;
	data->map = NULL;
}

unsigned short	**init_matrix(t_map *obj)
{
	unsigned short	**matrix;
	unsigned int	i;

	matrix = malloc(sizeof(unsigned short *) * obj->nbr_lines);
	if (!matrix)
	{
		ft_pser("Error: Malloc failed\n");
		return (NULL);
	}
	i = 0;
	while (i < obj->nbr_lines)
	{
		matrix[i] = malloc(sizeof(unsigned short) * obj->len_lines);
		if (!matrix[i])
			return (free_matrix_i(matrix, i));
		i++;
	}
	return (matrix);
}
