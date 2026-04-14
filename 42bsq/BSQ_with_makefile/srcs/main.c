/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:34:28 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/20 19:34:38 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

bool	ft_clear(t_map *obj, unsigned short **matrix, bool ret)
{
	if (obj->map)
		free(obj->map);
	if (matrix)
		free_matrix(matrix, obj);
	return (ret);
}

bool	solve(t_map *obj, char *file)
{
	unsigned short	**matrix;

	init_map(obj);
	if (!file)
	{
		if (!read_stdin(obj))
			return (ft_clear(obj, NULL, false));
	}
	else
	{
		if (!read_file(obj, file))
			return (ft_clear(obj, NULL, false));
	}
	matrix = init_matrix(obj);
	if (!matrix)
		return (ft_clear(obj, NULL, false));
	if (!process(obj, matrix))
		return (ft_clear(obj, matrix, false));
	if (PRINT == 0)
		display_bsq(obj, matrix);
	return (ft_clear(obj, matrix, true));
}

int	main(int argc, char **argv)
{
	t_map	d;
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc && solve(&d, argv[i]))
			i++;
		if (i < argc)
			return (1);
	}
	else
		return (solve(&d, NULL));
	return (0);
}
