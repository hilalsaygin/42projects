#include<unistd.h>

int is_printable (char c)
{
    if (c >= 32 && c <= 126)
        return 1;
    return 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr_non_printable(char *str)
{
    int     index;
    unsigned char	ch;

    index = 0;
    while (str[index] != '\0')
    {
        ch = str[index];
        if (is_printable(ch))
        {
            ft_putchar(ch);
        }
        else
        {
            ft_putchar('\\');
			ft_putchar("0123456789abcdef"[ch / 16]);
			ft_putchar("0123456789abcdef"[ch % 16]);
        }
        index++;
    }
}

int main (){
    char in[50] = "Coucou\ntu vas bien ?";
    ft_putstr_non_printable(in);
}