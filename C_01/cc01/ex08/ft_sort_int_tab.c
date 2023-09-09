/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilal <hilal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:40:54 by hilal             #+#    #+#             */
/*   Updated: 2023/09/07 23:40:55 by hilal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
    int current, i, j;
    i = 1;

    while (i < size)
    {
        current = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > current )
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = current;
        i++;
    }
}

int main ( ){
    int ll[10] = {23,4,55,6,1,203};

    ft_sort_int_tab(ll, 6);
    for (int i = 0; i<6;i++ )
    {
        printf ("%d**", ll[i]);
    }
}