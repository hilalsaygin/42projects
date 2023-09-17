
#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int index;

	index = 0;
    if(size > 0)
    {
        while (index < size -1 && src[index] != '\0')
    	{
    		dest[index] = src[index];
    		index++;
    	}
    	dest[index] = '\0';
    }
    return (index -1);
}

int main()
{
	char in[100] = "tgu vas ? quarante-deux; cinquante+et+un";
    char dest[100];
	ft_strlcpy(dest, in, 10);
	printf("%s",dest);
}
