#include<unistd.h>
void ft_print_comb(void){
    char i, j,k;
    for (i = '0'; i <= '9'; i++) {
        for (j = i + 1; j <= '9'; j++) {
            for (k = j + 1; k <= '9'; k++) {
                if (i != j && i != k && j != k) {
                    write(1,&i,1);
                    write(1,&j,1);
                    write(1,&k,1);
                    write(1,", ",2);
                }
            }
        }
    }
}

int main (){
    ft_print_comb();
} 