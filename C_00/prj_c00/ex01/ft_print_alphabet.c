#include <unistd.h>
void ft_print_alphabet(void){
    char ch = 'a';
    while(ch <= 'z'){
        write(1,&ch,1);
        ch++;
    }
}
