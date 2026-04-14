#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100000000
# endif

# define BUFFER_INIT	4096
# define BUFFER_STDIN	280000

# ifndef DEBUG
#  define DEBUG			0
# endif

# ifndef PRINT
#  define PRINT			0
# endif

typedef struct s_data
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
}					t_data;

void    free_matrix(unsigned short **matrix, t_data *data)
{
        unsigned int    i;

        i = 0;
        while (i < data->nbr_lines)
        {
                free(matrix[i]);
                i++;
        }
        if (data->len_lines != 0)
                free(matrix);
}

unsigned short  **free_matrix_i(unsigned short **matrix, int i)
{
        while (--i >= 0)
                free(matrix[i]);
        free(matrix);
        return (NULL);
}

static int      ft_strlen(const char *str)
{
        int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

bool    ft_pser(char *str)
{
        (void)!write(2, str, ft_strlen(str));
        return (false);
}

static int      ft_strcpy(char *dst, const char *src, const size_t size)
{
        size_t  i;

        i = 0;
        while (i < size && src[i])
        {
                dst[i] = src[i];
                i++;
        }
        dst[i] = '\0';
        return (i);
}

char    *ft_strjoin_bsq(char *s1, const size_t size1,
                char *s2, const size_t size2)
{
        char    *res;

        res = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
        if (!res)
                return (NULL);
        ft_strcpy(res, s1, size1);
        ft_strcpy(&res[size1], s2, size2);
        free(s1);
        return (res);
}

void    init_data(t_data *data)
{
        data->nbr_lines = 0;
        data->len_lines = 0;
        data->bsq_x = 0;
        data->bsq_y = 0;
        data->map = NULL;
}

unsigned short  **init_matrix(t_data *d)
{
        unsigned short  **matrix;
        unsigned int    i;

        matrix = malloc(sizeof(unsigned short *) * d->nbr_lines);
        if (!matrix)
        {
                ft_pser("Error: Malloc failed\n");
                return (NULL);
        }
        i = 0;
        while (i < d->nbr_lines)
        {
                matrix[i] = malloc(sizeof(unsigned short) * d->len_lines);
                if (!matrix[i])
                        return (free_matrix_i(matrix, i));
                i++;
        }
        return (matrix);
}

bool    map_arg(t_data *d)
{
        unsigned int    i;
        unsigned int    x;

        i = 0;
        while (d->map[i] && d->map[i] != '\n')
                i++;
        if (!d->map[i] || !d->map[i + 1])
                return (ft_pser("Error: map error\t(file need more than one line)\n"));
        d->n = i + 1;
        d->filler = d->map[--i];
        d->obstacle = d->map[--i];
        d->empty = d->map[--i];
        if (d->empty == d->filler || d->empty == d->obstacle
                || d->filler == d->obstacle)
                return (ft_pser("Error: map error\t(map char can't be the same)\n"));
        x = 0;
        d->nbr_lines = 0;
        while (x < i)
        {
                if (d->map[x] > '9' || d->map[x] < '0')
                        return (ft_pser("Error: map error\t(nbr_lines isn't a number)\n"));
                d->nbr_lines = d->nbr_lines * 10 + d->map[x++] - '0';
        }
        return (true);
}

bool    read_len_lines(t_data *d)
{
        unsigned int    i;

        if (d->nbr_lines == 0)
                return (ft_pser("Error: map error\t(nbr_lines can't be equal to 0)\n"));
        i = d->n;
        while (d->map[i] && d->map[i] != '\n')
                i++;
        d->len_lines = i - d->n;
        if (d->len_lines == 0)
                return (ft_pser("Error: map error\t(len_lines can't be equal to 0)\n"));
        return (true);
}

static void     print_bsq(t_data *d)
{
        (void)!write(1, &d->map[d->n], d->nbr_lines * (d->len_lines + 1));
}

static void     print_debug(t_data *d, unsigned short **matrix)
{
        unsigned int    x;
        unsigned int    y;

        printf("\n");
        y = 0;
        while (y < d->nbr_lines)
        {
                x = 0;
                while (x < d->len_lines)
                {
                        printf("%d", matrix[y][x]);
                        x++;
                }
                y++;
                printf("\n");
        }
}

static void     paint_bsq(t_data *d, unsigned short **matrix)
{
        unsigned int    x;
        unsigned int    y;
        unsigned int    top_left_x;
        unsigned int    top_left_y;

        top_left_x = d->bsq_x - matrix[d->bsq_y][d->bsq_x] + 1;
        top_left_y = d->bsq_y - matrix[d->bsq_y][d->bsq_x] + 1;
        y = 0;
        while (y <= d->nbr_lines)
        {
                x = 0;
                while (x <= d->len_lines)
                {
                        if ((y >= top_left_y && y <= d->bsq_y)
                                && (x >= top_left_x && x <= d->bsq_x))
                                d->map[(y * (d->len_lines + 1)) + x + d->n] = d->filler;
                        x++;
                }
                y++;
        }
}

void    display_bsq(t_data *d, unsigned short **matrix)
{
        paint_bsq(d, matrix);
        print_bsq(d);
        if (DEBUG != 0)
                print_debug(d, matrix);
}

static void     process_empty(t_data *d, unsigned short **matrix,
        unsigned int x, unsigned int y)
{
        unsigned short  tmp;

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
                if (matrix[y][x] > matrix[d->bsq_y][d->bsq_x])
                {
                        d->bsq_y = y;
                        d->bsq_x = x;
                }
        }
}

static bool     process_end_check(t_data *d,
        unsigned int *x, unsigned int *y, unsigned int i)
{
        if (d->map[i] == '\n')
        {
                if (x[0] != d->len_lines)
                        return (ft_pser(
                                        "Error: map error\t(all lines should be the same length)\n"));
                x[0] = -1;
                y[0] += 1;
        }
        else
                return (ft_pser(
                                "Error: map error\t(all lines should be the same length)\n"));
        return (true);
}

bool    process(t_data *d, unsigned short **matrix)
{
        unsigned int    x;
        unsigned int    y;
        unsigned int    i;

        i = d->n;
        x = 0;
        y = 0;
        while (i < (d->len_lines + 1) * d->nbr_lines)
        {
                if (y >= d->nbr_lines)
                        return (ft_pser(
                                        "Error: map error\t(lines over number of lines in arg)\n"));
                else if (d->map[i] == d->empty)
                        process_empty(d, matrix, x, y);
                else if (d->map[i] == d->obstacle)
                        matrix[y][x] = 0;
                else if (!process_end_check(d, &x, &y, i))
                        return (false);
                i++;
                x++;
        }
        return (true);
}

static bool     read_big_map(t_data *d, int fd, size_t buffer_size, size_t size)
{
        char    *buffer;
        ssize_t ret;

        buffer = (char *)malloc(sizeof(char) * buffer_size + 1);
        if (!buffer)
                return (ft_pser("Error: Malloc failed\n"));
        ret = read(fd, buffer, buffer_size);
        buffer[ret] = '\0';
        while (ret != 0 && ret != EOF)
        {
                d->map = ft_strjoin_bsq(d->map, size, buffer, buffer_size);
                if (!d->map)
                        return (ft_pser("Error: Malloc failed\n"));
                size += ret;
                ret = read(fd, buffer, buffer_size);
                buffer[ret] = '\0';
        }
        free(buffer);
        return (true);
}

static bool     read_map(t_data *d, int fd, size_t buffer_size)
{
        ssize_t         ret;

        d->map = (char *)malloc(sizeof(char) * BUFFER_INIT + 1);
        if (!d->map)
                return (ft_pser("Error: Malloc failed\n"));
        ret = read(fd, d->map, BUFFER_INIT);
        d->map[ret] = '\0';
        if (ret != 0 && ret != EOF)
                if (!read_big_map(d, fd, buffer_size, ret))
                        return (false);
        return (true);
}

bool    read_stdin(t_data *d)
{
        if (!read_map(d, 0, BUFFER_STDIN))
                return (false);
        if (!map_arg(d) || !read_len_lines(d))
                return (false);
        return (true);
}

bool    read_file(t_data *d, char *file)
{
        d->map = NULL;
        d->fd = open(file, O_RDONLY);
        if (d->fd < 0)
                return (ft_pser("Error: Open failed\n"));
        if (!read_map(d, d->fd, BUFFER_SIZE))
        {
                close(d->fd);
                return (false);
        }
        close(d->fd);
        if (!map_arg(d) || !read_len_lines(d))
                return (false);
        return (true);
}

bool    ft_clear(t_data *d, unsigned short **matrix, bool ret)
{
        if (d->map)
                free(d->map);
        if (matrix)
                free_matrix(matrix, d);
        return (ret);
}

bool    solve(t_data *d, char *file)
{
        unsigned short  **matrix;

        init_data(d);
        if (!file)
        {
                if (!read_stdin(d))
                        return (ft_clear(d, NULL, false));
        }
        else
        {
                if (!read_file(d, file))
                        return (ft_clear(d, NULL, false));
        }
        matrix = init_matrix(d);
        if (!matrix)
                return (ft_clear(d, NULL, false));
        if (!process(d, matrix))
                return (ft_clear(d, matrix, false));
        if (PRINT == 0)
                display_bsq(d, matrix);
        return (ft_clear(d, matrix, true));
}

int     main(int ac, char **av)
{
        t_data  d;
        int             i;

        if (ac > 1)
        {
                i = 1;
                while (i < ac && solve(&d, av[i]))
                        i++;
                if (i < ac)
                        return (1);
        }
        else
                return (solve(&d, NULL));
        return (0);
}