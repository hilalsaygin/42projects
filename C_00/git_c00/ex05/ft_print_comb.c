/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:49 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/05 20:53:47 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
void    ft_print_comb(void)
{
    char    i, j,k;

    i = '0';

    while (i <= '7')
    {
        j = i + 1;

        while (j <= '8')
        {
            k = j +1;
            while (k <= '9')
            {
                if (i != j && i != k && j != k)
                {
                    write(1, &i, 1);
                    write(1, &j, 1);
                    write(1, &k, 1);
                    if (i == '7' && j == '8' && k == '9')
                        return;
                    write(1, ", ", 2);
                }
                k ++;
            }
          j ++;
        }
        i ++;
    }
}

int main (){
    ft_print_comb();
} 