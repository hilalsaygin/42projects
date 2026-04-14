/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:34:47 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/20 20:03:23 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static bool	read_big_map(t_map *obj, int fd, size_t buffer_size, size_t size)
{
	char	*buffer;
	int		ret;

	buffer = (char *)malloc(sizeof(char) * buffer_size + 1);
	if (!buffer)
		return (ft_pser("Error: Malloc failed\n"));
	ret = read(fd, buffer, buffer_size);
	buffer[ret] = '\0';
	while (ret != 0 && ret != EOF)
	{
		obj->map = ft_strjoin_bsq(obj->map, size, buffer, buffer_size);
		if (!obj->map)
			return (ft_pser("Error: Malloc failed\n"));
		size += ret;
		ret = read(fd, buffer, buffer_size);
		buffer[ret] = '\0';
	}
	free(buffer);
	return (true);
}

static bool	read_map(t_map *obj, int fd, size_t buffer_size)
{
	int		ret;

	obj->map = (char *)malloc(sizeof(char) * BUFFER_INIT + 1);
	if (!obj->map)
		return (ft_pser("Error: Malloc failed\n"));
	ret = read(fd, obj->map, BUFFER_INIT);
	obj->map[ret] = '\0';
	if (ret != 0 && ret != EOF)
		if (!read_big_map(obj, fd, buffer_size, ret))
			return (false);
	return (true);
}

bool	read_stdin(t_map *obj)
{
	if (!read_map(obj, 0, BUFFER_STDIN))
		return (false);
	if (!map_argument(obj) || !read_len_lines(obj))
		return (false);
	return (true);
}

bool	read_file(t_map *obj, char *file)
{
	obj->map = NULL;
	obj->fd = open(file, O_RDONLY);
	if (obj->fd < 0)
		return (ft_pser("Error: Open failed\n"));
	if (!read_map(obj, obj->fd, BUFFER_SIZE))
	{
		close(obj->fd);
		return (false);
	}
	close(obj->fd);
	if (!map_argument(obj) || !read_len_lines(obj))
		return (false);
	return (true);
}
