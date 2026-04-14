/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:23:55 by ogoztak           #+#    #+#             */
/*   Updated: 2023/09/20 19:15:14 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100000
# endif

# define BUFFER_INIT	4096
# define BUFFER_STDIN	4096

# ifndef PRINT
#  define PRINT			0
# endif

typedef struct s_map
{
	char			*map;
	char			empty;
	char			obstacle;
	char			filler;
	unsigned int	nbr_lines;
	unsigned int	len_lines;
	unsigned int	bsq_x;
	unsigned int	bsq_y;
	unsigned long	n;
	int				fd;
}					t_map;

bool			read_file(t_map *d, char *file);
bool			read_stdin(t_map *d);
bool			map_argument(t_map *d);
bool			read_len_lines(t_map *d);

bool			process(t_map *d, unsigned short **matrix);

void			display_bsq(t_map *d, unsigned short **matrix);

void			init_map(t_map *data);
unsigned short	**init_matrix(t_map *d);
void			free_matrix(unsigned short **matrix, t_map *data);
unsigned short	**free_matrix_i(unsigned short **matrix, int i);

char			*ft_strjoin_bsq(char *s1, const size_t size1,
					char *s2, const size_t size2);
bool			ft_pser(char *str);

#endif
