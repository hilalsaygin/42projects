#include<unistd.h>

int ft_srtlen(char* str){
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void ft_sprintf(char* dest,char* str, int i ){
    int index=0;
    while(str[index] != '\0'){
        dest[index]=str[index];
        index++;
    }
    dest[index]=(i+'0');
    dest[index + 1] = '\0'; 
}
void combn(int start, int n, char* s)
{
    int i=start;
    if(n==0){
        write(1,s, ft_srtlen(s));
        write(1,", ",2);

        return;
    } 

  while(i<=9){      
      char s2[10];   
      ft_sprintf(s2,s,i);
      combn(i+1,n-1, s2);
      i++;
  }
}

void ft_print_combn(int n)
{
    int c=0;
    if (n>=1 && n<=10)
    {   combn(0,n,"");}
}

int main (){
    ft_print_combn(2);
}