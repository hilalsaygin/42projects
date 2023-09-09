/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:57 by rsaygin           #+#    #+#             */
/*   Updated: 2023/09/05 18:28:59 by rsaygin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
void ft_putnbr(int nb){
    int rem;
    int div=nb, count=0;
    char digits[50];
    if (div ==0 ){
        write (1,&"0", 1);
        return ;
    }
    if (div<0){
        write (1,&"-", 1);
        div= -div;
    }
    while(div>0){
        rem=div%10;
        digits[count]=rem+'0';
        div=div/10;
        count++;

    }
    while ((--count) >= 0)
    {
        write (1,&digits[count], 1);
    }
}