#include <stdio.h>
/*
The formula for combinations without repetition is given by:

C(n, k) = n! / (k! * (n - k)!)
Count = C(10, 3)

Now calculate:

Count = 10! / (3! * (10 - 3)!)
Count = 10! / (3! * 7!)
Count = (10 * 9 * 8) / (3 * 2 * 1)
Count = 120
*/
int comb_count(int *n)
{
    int tot_count, numinator, dominator, iter, d, digit;
    digit = *n;
    iter = 10 - (10 - digit);
    numinator =1;
    dominator = 1;
    d=10;

    while (iter > 0)
    {
        numinator *= d;
        iter--;
        d--; 
    }
    iter = 10 - (10 - digit);
    while (iter > 0)
    {
        dominator *=digit;
        iter--;
        digit--;
    }
    tot_count =numinator/dominator;
    //printf("Count : %d\n", tot_count);
    return (tot_count);    
}
// Function to print all n-digit numbers whose digits
// are strictly increasing from left to right.
// out   --> Stores current output number as string
// start --> Current starting digit to be considered
void findStrictlyIncreasingNum(int start, char *s, int n, int *digit, int *count)
{
    // If number becomes N-digit, print it
    if (n == 0)
    {
        printf("%s", s);
        *count = *count +1;
        if (*count != comb_count(digit))
            printf(", ");
        return;
    }
 
    // start from (prev digit + 1) till 9
    for (int i = start; i <= 9; i++)
    {
        // append current digit to number
        char s2[11];
        sprintf(s2, "%s%i", s, i);
        
        // recurse for next digit
        findStrictlyIncreasingNum(i + 1, s2, n - 1, digit, count);
        
    }
}
void ft_print_combn(int n)
{
    int c;
    c=0;
    if (n > 0 && n < 10)
        findStrictlyIncreasingNum(0, "", n, &n, &c);

}

int main (int argc, char* args[])
{
    ft_print_combn(4);
}
