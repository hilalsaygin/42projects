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
    while ((--count) >= 0){
        write (1,&digits[count], 1);
    }
}
void ft_print_comb2(void){
    int i=0, j=1;
    while (i <= 99) {
        while ( j <= 99) {
            
            if (i <=9)   
            {   write(1,&"0",1);}
            ft_putnbr(i);
            write(1,&" ",1);
            if(j<=9)
            {   write(1,&"0",1);}
            ft_putnbr(j);
            if (i==98 && j==99)
                return;
            write(1,&", ",2);
            j++;
        }
        i++;
        j=i+1;
    }
    
}

int main (){
    ft_print_comb2();
} 