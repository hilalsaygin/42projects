#include <unistd.h>
//prints out only one character on console
void ft_putchar(char c){

    
    write(1,&c,1);
}
